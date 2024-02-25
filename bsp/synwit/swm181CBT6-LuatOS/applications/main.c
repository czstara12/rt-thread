#include "SWM181.h"

#include "rtthread.h"

void TaskADC(void *arg);
void TaskPWM(void *arg);

struct rt_thread taskADC;
static uint8_t stackADC[256];
static uint8_t priorityADC = 4;

struct rt_thread taskPWM;
static uint8_t stackPWM[256];
static uint8_t priorityPWM = 5;

int main(void)
{
	SystemInit();

	rt_thread_init(&taskADC, "ADC", TaskADC, RT_NULL, stackADC, sizeof(stackADC), priorityADC, 20);
	rt_thread_startup(&taskADC);

	rt_thread_init(&taskPWM, "PWM", TaskPWM, RT_NULL, stackPWM, sizeof(stackPWM), priorityPWM, 20);
	rt_thread_startup(&taskPWM);

	GPIO_Init(GPIOB, PIN8, 1, 0, 0, 0); // 调试指示信号

	while (1)
	{
		GPIO_InvBit(GPIOB, PIN8);
		rt_thread_delay(1000);
	}
}

void TaskADC(void *arg)
{
	while (1)
	{
		rt_thread_delay(1000);
	}
}
void TaskPWM(void *arg)
{
	while (1)
	{
		rt_thread_delay(1000);
	}
}
