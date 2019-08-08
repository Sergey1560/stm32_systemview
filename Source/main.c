#include "stm32f4xx.h"
#include <stdio.h>
#include "SEGGER_RTT.h"
#include "SEGGER_SYSVIEW.h"
#include "rcc.h"

volatile uint8_t led_on=0;

void timer2_init(void){
	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
	TIM2->PSC = (uint16_t)((TIM2_CLK/2)/1000)/1000 - 1;
	TIM2->ARR = (1000 )*2000 - 1; 		//2000 - 1sec, Вкл-выкл, 0.5 секунды задержка
	TIM2->DIER |= TIM_DIER_UIE;
	TIM2->CR1 |= TIM_CR1_CEN;
	
	NVIC_EnableIRQ(TIM2_IRQn);
	NVIC_SetPriority (TIM2_IRQn, 5);
}

void TIM2_IRQHandler(void)
{
	SEGGER_SYSVIEW_RecordEnterISR();
	if(TIM2->SR & TIM_SR_UIF)	TIM2->SR &= ~TIM_SR_UIF; 

	if(led_on){
		SEGGER_RTT_printf(0,"Led is off\n");
		GPIOD->BSRR = GPIO_BSRR_BR14;
		led_on=0;
	}else{
		SEGGER_RTT_printf(0,"Led is on\n");
		GPIOD->BSRR = GPIO_BSRR_BS14;
		led_on=1;
	}

	

	SEGGER_SYSVIEW_RecordExitISR();
}

/*
void SysTick_Handler(void){
	SEGGER_SYSVIEW_RecordEnterISR();
	SEGGER_SYSVIEW_RecordExitISR();
}
*/
int main(void){

	RCC_init();
	//SysTick_Config(SystemCoreClock/1000);

	SEGGER_RTT_ConfigUpBuffer(0, NULL, NULL, 0, SEGGER_RTT_MODE_BLOCK_IF_FIFO_FULL);
	SEGGER_RTT_WriteString(0, "##### System start ######\r\n");
	SEGGER_SYSVIEW_Conf();
	
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;
	GPIOD->MODER |= GPIO_MODER_MODE14_0;
	GPIOD->OSPEEDR |= (2 << GPIO_OSPEEDR_OSPEED14_Pos);
	GPIOD->PUPDR |= GPIO_PUPDR_PUPD14_1; //Pull down

	timer2_init();

	while(1){
		//SEGGER_SYSVIEW_OnIdle();
	};


}
