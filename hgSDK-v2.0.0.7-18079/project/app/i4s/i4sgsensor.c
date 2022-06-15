#include "include.h"
#include "arm_arch.h"
#include "drv_model_pub.h"
#include "bk_timer_pub.h"
#include "i2c_pub.h"
#include "uart_pub.h"
#include "rtos_pub.h"
#include "error.h"

#include "i4s.h"
#include "i4sgsensor.h"

#define GSENSOR_PRT                warning_prf
#define GSENSOR_WARN               warning_prf
#define GSENSOR_FATAL              fatal_prf

#define GSENSOR_TMR_DURATION  10
#define GSENSOR_DATA_CONV(x) ((x) < 0?((-(x)) | 0x200):(x))

//#define GSENSOR_GMA301	1
#define GSENSOR_SC7A20	1



static DD_HANDLE i2c_gsensor = DD_HANDLE_UNVALID;
static UINT8 i2c_salve_id = 0;
static I2C_OP_ST i2c_gsensor_operater;
static beken_timer_t g_gsensor_timer;


static void get_xyz(void *param);

int (*gensor_correction)(int*,int*,int*) = NULL;

void gsonsor_conv2i4s(int X, int Y, int Z)
{
	uint32_t x = 0, y = 0, z = 0;
	int tX, tY, tZ;

	tX = X;
	tY = Y;
	tZ = Z;
	if(gensor_correction){
		gensor_correction(&tX, &tY, &tZ);
	}
	x = GSENSOR_DATA_CONV(tX);
	y = GSENSOR_DATA_CONV(tY);
	z = GSENSOR_DATA_CONV(tZ);
	i4sGensorDataUpdate((x<< 20 | y<<10 | z));
}

static void gsensor_i2c_write(UINT8 addr, char* data, UINT8 len)
{
	i2c_gsensor_operater.salve_id = i2c_salve_id;
	i2c_gsensor_operater.op_addr = addr;
	ddev_write(i2c_gsensor, data, len, (UINT32)&i2c_gsensor_operater);
}

static void gsensor_i2c_read(UINT8 addr, char* data, UINT8 len)
{
	i2c_gsensor_operater.salve_id = i2c_salve_id;
	i2c_gsensor_operater.op_addr = addr;
	ddev_read(i2c_gsensor, data, len, (UINT32)&i2c_gsensor_operater);
}


static void gsensor_timer_configure(void)
{
	OSStatus result;	
    result = rtos_init_timer(&g_gsensor_timer,
                            GSENSOR_TMR_DURATION,
                            get_xyz,
                            (void *)0);
    ASSERT(kNoErr == result);
	
    result = rtos_start_timer(&g_gsensor_timer);
    ASSERT(kNoErr == result);
}

static void gsensor_timer_unconfig(void)
{
	OSStatus ret;
	if(rtos_is_timer_init(&g_gsensor_timer))
	{
	    if (rtos_is_timer_running(&g_gsensor_timer)) 
		{
	        ret = rtos_stop_timer(&g_gsensor_timer);
			ASSERT(kNoErr == ret);
	    }

	    ret = rtos_deinit_timer(&g_gsensor_timer);
		ASSERT(kNoErr == ret);
	}
}

#if (GSENSOR_GMA301 == 1)

static void get_xyz(void *param)
{	
	int X, Y, Z = 0;
	u8 read_buf[6] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
	gsensor_i2c_read((0x14 | 0x80), read_buf, 6);
	X = (read_buf[1] << 8)| read_buf[0];  //
	Y = (read_buf[3] << 8) | read_buf[2];
	Z = (read_buf[5] << 8) | read_buf[4];

	GSENSOR_PRT("X:%02X Y:%02X Z:%02X\r\n", X, Y, Z);	
	gsonsor_conv2i4s(X, Y, Z);
}

int gsensor_init(void)
{
	char buffer[16] = {0};
	int trynum = 0;
	
	i2c_salve_id = 0x18;
	//Read the STADR register (12h) and check the value should be 0x55h
	for(trynum = 0; trynum < 3; trynum++){
		gsensor_i2c_read(0x12, buffer, 1);
		if(buffer[0] == 0x55){
			GSENSOR_PRT("gsensor gma301 ready\r\n");
			break;
		}
	}
	if(trynum >= 3){
		GSENSOR_PRT("gensor gma301 not ready\r\n");
		return -1;
	}
	//Write 0x52 to the PD register (21h). This will set the RST bit which reset the sensor
	buffer[0] = 0x52;
	gsensor_i2c_write(0x21, buffer, 1);
	//Write the 5-byte sequence, 0x02, 0x12, 0x02, 0x82 and 0x02, to the ACTR register (00h)
	buffer[0] = 0x02; buffer[1] = 0x12; buffer[2] = 0x02; buffer[3] = 0x82; buffer[4] = 0x02;
	gsensor_i2c_write(0x21, buffer, 5);

	//Write 0x28 to the MISC2 register (1Fh).
	buffer[0] = 0x28;
	gsensor_i2c_write(0x1F, buffer, 1);

	//Write 0x8F to the AFEM(0Ch) register.
	buffer[0] = 0x8F;
	gsensor_i2c_write(0x0C, buffer, 1);
	
	//Write 0x06 to the ACTR(00h) register. 
	buffer[0] = 0x06;
	gsensor_i2c_write(0x00, buffer, 1);

	
	GSENSOR_PRT("gensor gma301 init ok\r\n");

	return 0;
}

#elif (GSENSOR_SC7A20 == 1)


#define cAccDropLen	(2)
#define cAccBufPayLen	(1 << 3)
#define cAccBufLen	(cAccDropLen+cAccBufPayLen)
int AccData_Last[3][cAccBufLen];
int AccData_Drop[3][cAccDropLen];

static void get_xyz(void *param)
{	
	int X, Y, Z = 0, i;
	u8 read_buf[6] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
	static UINT8 bInitAccData = 0;
	int ACCSum[3] = {0};

	gsensor_i2c_read((0x28 | 0x80), read_buf, 6);

	X = (signed short int)((read_buf[1] << 8) | read_buf[0]); 
	Y = (signed short int)((read_buf[3] << 8) | read_buf[2]);
	Z = (signed short int)((read_buf[5] << 8) | read_buf[4]);

	// Acc filter
	if(bInitAccData==0)
	{
		for(i = 0; i < cAccBufLen; i++)
		{
			AccData_Last[0][i] = X;
			AccData_Last[1][i] = Y;
			AccData_Last[2][i] = Z;
		}
		bInitAccData = 1;
	}
	else
	{
		for(i = 0; i < (cAccBufLen-1); i++)
		{
			AccData_Last[0][i] = AccData_Last[0][i+1];
			AccData_Last[1][i] = AccData_Last[1][i+1];
			AccData_Last[2][i] = AccData_Last[2][i+1];
		}
		AccData_Last[0][cAccBufLen-1] = X;
		AccData_Last[1][cAccBufLen-1] = Y;
		AccData_Last[2][cAccBufLen-1] = Z;
	}

	ACCSum[0] = 0;
	ACCSum[1] = 0;
	ACCSum[2] = 0;
	AccData_Drop[0][0] = AccData_Drop[0][1] = X;
	AccData_Drop[1][0] = AccData_Drop[1][1] = Y;
	AccData_Drop[2][0] = AccData_Drop[2][1] = Z;

	for(i = 0; i < cAccBufLen; i++)
	{
		ACCSum[0] += AccData_Last[0][i];
		AccData_Drop[0][0] = min(AccData_Drop[0][0], AccData_Last[0][i]);
		AccData_Drop[0][1] = max(AccData_Drop[0][1], AccData_Last[0][i]);

		ACCSum[1] += AccData_Last[1][i];
		AccData_Drop[1][0] = min(AccData_Drop[1][0], AccData_Last[1][i]);
		AccData_Drop[1][1] = max(AccData_Drop[1][1], AccData_Last[1][i]);

		ACCSum[2] += AccData_Last[2][i];
		AccData_Drop[2][0] = min(AccData_Drop[2][0], AccData_Last[2][i]);
		AccData_Drop[2][1] = max(AccData_Drop[2][1], AccData_Last[2][i]);

	}
	X = ((ACCSum[0]-AccData_Drop[0][0]-AccData_Drop[0][1])/cAccBufPayLen) >> 6;
	Y = ((ACCSum[1]-AccData_Drop[1][0]-AccData_Drop[1][1])/cAccBufPayLen) >> 6;
	Z = ((ACCSum[2]-AccData_Drop[2][0]-AccData_Drop[2][1])/cAccBufPayLen) >> 6;

#if 0
	GSENSOR_PRT("mx:%d/%d \tmy:%d/%d \tmz:%d/%d\r\n",
			AccData_Drop[0][0], AccData_Drop[0][1], AccData_Drop[1][0], AccData_Drop[1][1],
			AccData_Drop[2][0], AccData_Drop[2][1]);
	GSENSOR_PRT("X:%d \tY:%d \tZ:%d\r\n", X, Y, Z);
#endif

	gsonsor_conv2i4s(X, Y, Z);
}

#define CHIPID_SC7A20 0x0f
int gsensor_init(void)
{
	char buffer[16] = {0};
	int trynum = 0;
	
	i2c_salve_id = 0x18; //0x18:low; 0x19:high
	
	//Read the STADR register (12h) and check the value should be 0x55h
	for(trynum = 0; trynum < 3; trynum++){
		gsensor_i2c_read(CHIPID_SC7A20, buffer, 1);
		if(buffer[0] == 0x11){
			GSENSOR_PRT("gsensor sc7a20 ready\r\n");
			break;
		}
	}
	if(trynum >= 3){
		GSENSOR_PRT("gensor sc7a20 not ready\r\n");
		return -1;
	}

#if 0
	//close SDO	
	buffer[0] = 0x05;
	gsensor_i2c_write(0x1E, buffer, 1); //打开操作权限，0x1E 寄存器写 0x05
	gsensor_i2c_read(0x57, buffer, 1); //读取 0x57 寄存器当前配置
	buffer[0]= buffer[0]|0x80; //SDO_PU 置 1
	gsensor_i2c_write(0x57, buffer, 1); //操作 SDO_PU 位，0x57 寄存器写入配置
	buffer[0] = 0x00;
	gsensor_i2c_write(0x1E, buffer, 1);

	buffer[0] = 0x97;
	gsensor_i2c_write(0x20, buffer, 1);
	buffer[0] = 0x77;
	gsensor_i2c_write(0x20, buffer, 1);

	buffer[0] = 0x88;
	gsensor_i2c_write(0x23, buffer, 1);

#endif
	//close SDO
	buffer[0] = 0x05;
	gsensor_i2c_write(0x1E, buffer, 1); //打开操作权限，0x1E 寄存器写 0x05
	gsensor_i2c_read(0x57, buffer, 1); //读取 0x57 寄存器当前配置
	buffer[0]= buffer[0]|0x80; //SDO_PU 置 1
	gsensor_i2c_write(0x57, buffer, 1); //操作 SDO_PU 位，0x57 寄存器写入配置
	buffer[0] = 0x00;
	gsensor_i2c_write(0x1E, buffer, 1);

	//start sensor
	buffer[0] = 0x97; //0x9f
	gsensor_i2c_write(0x20, buffer, 1);

	buffer[0] = 0x04; //0x04
	gsensor_i2c_write(0x21, buffer, 1);
	buffer[0] = 0x88;//0x88
	gsensor_i2c_write(0x23, buffer, 1);

	GSENSOR_PRT("gensor sc7a20 init ok\r\n");

	return 0;
}


#endif

int i4s_gsensor_init(void)
{
    UINT32 status, oflag;

	oflag = I2C_DEF_DIV;

	//uninit first for multi call init
	i4s_gsensor_uninit();
	i2c_gsensor = ddev_open(I2C2_DEV_NAME, &status, oflag);
	//init gsensor
	if(gsensor_init() < 0){
		i4s_gsensor_uninit();
		GSENSOR_PRT("gsenor init failed\r\n");
		return -1;
	}
	//init gsensor timer
	gsensor_timer_configure();

	return 0;	
}

void i4s_gsensor_uninit(void)
{
    GLOBAL_INT_DECLARATION();

	gsensor_timer_unconfig();
    ddev_close(i2c_gsensor);
    GLOBAL_INT_DISABLE();
    i2c_gsensor = DD_HANDLE_UNVALID;
    GLOBAL_INT_RESTORE();
}

void i4s_gsensor_correction_callback(int (*callback)(int*,int*,int*))
{
	gensor_correction = callback;
	GSENSOR_PRT("register gsensor correction\r\n");
}
