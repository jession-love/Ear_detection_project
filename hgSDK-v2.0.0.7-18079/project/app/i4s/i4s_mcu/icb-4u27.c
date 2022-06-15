/*system include*/
#include "sys_config.h"
#include "typesdef.h"
#include "list.h"
#include "lwip/err.h"
#include "lwip/sockets.h"
#include "lwip/netdb.h"
#include "lwip/sys.h"
#include "lwip/ip_addr.h"
#include "lwip/tcpip.h"
#include "osal/string.h"
#include "osal/semaphore.h"
#include "osal/mutex.h"
#include "osal/irq.h"
#include "osal/task.h"
#include "osal/sleep.h"
#include "osal/timer.h"
#include "osal/work.h"
#include "lib/umac/umac.h"
#include "hal/dvp.h"
#include "lib/video/dvp/jpeg/jpg.h"
#include "hal/jpeg.h"
#include "syscfg.h"
#include "hal/gpio.h"


#define GPIO_DET_CHARGE			PA_3
#define GPIO_CTRL_MCU			PA_4
#define GPIO_LED_RED			PA_5
#define GPIO_LED_BLUE			PA_6	
#define GPIO_PWR_KEY			PA_7
#define GPIO_LED_WHITE			PA_14

static volatile int connect_flag = 0;

static void i4s_gpio_init(void)
{
	gpio_iomap_input(GPIO_DET_CHARGE, GPIO_DIR_INPUT);         //charge 
	gpio_iomap_input(GPIO_PWR_KEY, GPIO_DIR_INPUT);         //USB_EN

	gpio_iomap_output(GPIO_CTRL_MCU, GPIO_IOMAP_OUTPUT);     //mcu control

	gpio_iomap_output(GPIO_LED_RED, GPIO_IOMAP_OUTPUT);     //red LED
	gpio_iomap_output(GPIO_LED_BLUE, GPIO_IOMAP_OUTPUT);      //blue_LED
	gpio_iomap_output(GPIO_LED_WHITE, GPIO_IOMAP_OUTPUT);      //white LED
	
	gpio_set_val(GPIO_LED_RED,0);
	gpio_set_val(GPIO_LED_BLUE,0);
	gpio_set_val(GPIO_LED_WHITE,0);
}

static void _mcu_task(void *arg)
{
	int idx = 0;
	int cnt = 0;
	int time_ctr = 0;
	while(1){
		if(cnt >= 40){
			os_printf("Power off\r\n");			
			gpio_set_val(GPIO_LED_BLUE,0);
			gpio_set_val(GPIO_CTRL_MCU,0);
			os_printf("Power finish\r\n");	
			while(1);
		}
		if(gpio_get_val(GPIO_PWR_KEY)){
			os_printf("power key:%d\r\n", cnt);
			cnt++;
		}else{
			cnt = 0;
		}

		if(gpio_get_val(GPIO_DET_CHARGE)){
			gpio_set_val(GPIO_LED_RED,1);
		}else{
			gpio_set_val(GPIO_LED_RED,0);
		}
		
		if(connect_flag){
			gpio_set_val(GPIO_LED_BLUE,1);
		}else{
			if(time_ctr >= 9){
				idx ^=0x01;
				gpio_set_val(GPIO_LED_BLUE, idx);
				time_ctr = 0;
			}
		}
		os_sleep_ms(50);
		time_ctr++;
	}
}

int i4s_mcu_init(void)
{
	void *thread;

	i4s_gpio_init();
	os_printf("i4s mcu init\r\n");
	
	gpio_set_val(GPIO_CTRL_MCU,1);
	gpio_set_val(GPIO_LED_WHITE,1);
	gpio_set_val(GPIO_LED_BLUE,1);
	csi_kernel_task_new((k_task_entry_t)_mcu_task, "i4s_mcu_init", NULL, 9, 0, NULL, 1024, &thread);

	return 0;
}

int i4s_connected(int connect)
{
	connect_flag = connect;

	return 0;
}
