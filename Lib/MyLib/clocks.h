#ifndef CLOCKS_H
#define CLOCKS_H

//#define STM32F407
#define STM32F429

/* Источник PLL */
#define PLL_HSE 1
#define PLL_HSI 0

#ifdef STM32F407
/* Основные настройки тактирования */
#define RCC_PLL_M 8 
#define RCC_PLL_N 336 
#define RCC_PLL_P 2
#define RCC_PLL_Q 7
#define RCC_PLL_SOURCE PLL_HSE
#define RCC_HSE 8000000

/* Тактирование шин */
#define APB1_CLK 42000000UL
#define APB2_CLK 84000000UL

/* Тактирование таймеров */
#define APB1_TIMER_CLK 84000000UL //42Mhz и множитель 2
#define APB2_TIMER_CLK 168000000UL //84Mhz и множитель 2

#define TIM2_CLK APB1_TIMER_CLK
#define TIM3_CLK APB1_TIMER_CLK
#define TIM4_CLK APB1_TIMER_CLK
#define TIM5_CLK APB1_TIMER_CLK
#define TIM6_CLK APB1_TIMER_CLK
#define TIM7_CLK APB1_TIMER_CLK
#define TIM9_CLK APB2_TIMER_CLK
#define TIM10_CLK APB2_TIMER_CLK

#endif

#ifdef STM32F429
/* Основные настройки тактирования */
#define RCC_PLL_M 4 
#define RCC_PLL_N 180 
#define RCC_PLL_P 2
#define RCC_PLL_Q 4
#define RCC_PLL_SOURCE PLL_HSE
#define RCC_HSE 8000000

/* Тактирование шин */
#define APB1_CLK 45000000UL
#define APB2_CLK 90000000UL

/* Тактирование таймеров */
#define APB1_TIMER_CLK 90000000UL //42Mhz и множитель 2
#define APB2_TIMER_CLK 180000000UL //84Mhz и множитель 2

#define TIM2_CLK APB1_TIMER_CLK
#define TIM3_CLK APB1_TIMER_CLK
#define TIM4_CLK APB1_TIMER_CLK
#define TIM5_CLK APB1_TIMER_CLK
#define TIM6_CLK APB1_TIMER_CLK
#define TIM7_CLK APB1_TIMER_CLK
#define TIM9_CLK APB2_TIMER_CLK
#define TIM10_CLK APB2_TIMER_CLK
#endif


#endif