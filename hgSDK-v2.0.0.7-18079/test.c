#define I4SC_PRT                os_printf
#define I4SC_WARN               os_printf
#define I4SC_FATAL              os_printf

#define I4S_BUF_SIZE		1500

typedef struct _proto_t{
	int cmd_sockfd;	/*socket fd*/
	int pic_sockfd;	
	uint8_t buffer[I4S_BUF_SIZE];
	uint16_t port;	/*listen port*/
	void *thread; /*thread task id*/
}proto_t; /*protocol handle struct*/



static int test_protocol_handle(int sock, uint8_t *buffer, int buf_size)
{
	int rev_len, snd_len;
	uint16_t tmp_len;
	socklen_t addr_len;
	struct sockaddr_in cli_addr;

	if(sock == -1){
		I4SC_FATAL("parameter error\r\n");
		return 0;
	}

	os_memset(buffer, 0, sizeof(buf_size));
	rev_len = recvfrom(sock, buffer, buf_size, 0, (struct sockaddr *)&cli_addr, &addr_len);
	if(rev_len <= 0){
		I4SC_FATAL("recv failed\r\n");
		return 0;
	}
	I4SC_FATAL("receive %d bytes:%s\r\n", rev_len, buffer);
	uint8_t *test = "hello world";
	snd_len = sendto(sock, test, os_strlen(test), 0, (struct sockaddr *)&cli_addr, sizeof(struct sockaddr));
	I4SC_FATAL("sock:%d send %d bytes:%s\r\n", sock, snd_len, test);
	if(snd_len < 0){
		I4SC_FATAL("udp error:%d socket: %s",
				errno, strerror( errno ));
	}

	return snd_len;
}

static void _proto_task_test(void *arg)
{
	proto_t	*pctxd = (proto_t*)arg;
    fd_set rdset;
    struct timeval tv = {0, 200000};
	int ret, maxfd;

	if(!pctxd){
		I4SC_FATAL("protoCtx_task null\r\n");
		return;
	}
	while(WIFI_RUN_STATUS == TASK_RUN){
        FD_ZERO(&rdset);
        FD_SET(pctxd->cmd_sockfd, &rdset);	
        FD_SET(pctxd->pic_sockfd, &rdset);
		tv.tv_sec = 0;
		tv.tv_usec = 200000; /*200ms*/
		maxfd = max(pctxd->cmd_sockfd, pctxd->pic_sockfd);
		
        ret = select(maxfd+1, &rdset, NULL, NULL, &tv);
        if (ret < 0) {
			I4SC_FATAL("select failed:%d\r\n", ret);
            break;
        }else if(ret == 0) {
			continue;
        }
		if(FD_ISSET(pctxd->cmd_sockfd, &rdset)){
			/*handle request*/
			test_protocol_handle(pctxd->cmd_sockfd, pctxd->buffer, sizeof(pctxd->buffer));
		}
		if(FD_ISSET(pctxd->pic_sockfd, &rdset)){
			/*handle request*/
			test_protocol_handle(pctxd->pic_sockfd, pctxd->buffer, sizeof(pctxd->buffer));
		}
	}

	I4SC_PRT("protoCtx Task Quit\r\n");	
}

proto_t t_proto;

static int _proto_init_test(uint16_t port)
{
	int ret;
	struct sockaddr_in addr;
	int cmd_sockfd, pic_sockfd;

	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	addr.sin_port = htons(port);
	/*init cmd socket*/
    cmd_sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if (cmd_sockfd  == -1) {
		I4SC_PRT("create cmd udp failed\r\n");
		goto EXIT;
	}
	I4SC_PRT("csock:%d\r\n", cmd_sockfd);
	/*bind socket*/
    ret = bind(cmd_sockfd, (struct sockaddr *)&addr, sizeof (struct sockaddr));
	if(ret){
		I4SC_PRT("bind udp failed\r\n");
		goto EXIT;
	}
	//create picture sockfd
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	addr.sin_port = htons(port+1);
	/*init cmd socket*/
    pic_sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if (pic_sockfd  == -1) {
		I4SC_PRT("create pic udp failed\r\n");
		goto EXIT;
	}
	
	I4SC_PRT("psock:%d\r\n", pic_sockfd);
	/*bind socket*/
    ret = bind(pic_sockfd, (struct sockaddr *)&addr, sizeof (struct sockaddr));
	if(ret){
		I4SC_PRT("bind pic udp failed\r\n");
		goto EXIT;
	}

	t_proto.cmd_sockfd = cmd_sockfd;
	t_proto.pic_sockfd = pic_sockfd;
	t_proto.port = port;
	csi_kernel_task_new((k_task_entry_t)_proto_task_test, "protoCtxtest", &t_proto, 9, 0, NULL, 1024, &(t_proto.thread));
	I4SC_PRT("protoCtx OK!\r\n");
	return 0;
	
EXIT:
	I4SC_PRT("protoCtx quit!\r\n");
	return -1;
}
