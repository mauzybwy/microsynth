/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __PC4_PERIPH_H
#define __PC4_PERIPH_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
//#include "stm32f4xx.h"
//#include "p24.h"
   
typedef enum 
{
  A_COLON = 0,
  B_DIGIT4 = 1,
  C_DIGIT2 = 2,
	D_ROT_ENC = 3,
  E_R = 4,
  F_DIGIT1 = 5,
	G_DIGIT3 = 6,
  DP_G = 7,
	CA_EN = 8,
	CA_CLK = 9,
	AN_EN = 10,
	AN_CLK = 11
} ANCA_TypeDef;


/** 
  * @brief  Define for PC4_PERIPH board  
  */ 
#if !defined (USE_STM324xG_EVAL)
 #define USE_STM324xG_EVAL 
#endif

#define ANCAn                            12
#define U_CAn                            10

#define CA_EN_PIN                        GPIO_Pin_1
#define CA_EN_GPIO_PORT                  GPIOC
#define CA_EN_GPIO_CLK                   RCC_AHB1Periph_GPIOC

#define CA_A_PIN                         GPIO_Pin_5
#define CA_A_GPIO_PORT                   GPIOC
#define CA_A_GPIO_CLK                    RCC_AHB1Periph_GPIOC

#define CA_B_PIN                         GPIO_Pin_1
#define CA_B_GPIO_PORT                   GPIOB
#define CA_B_GPIO_CLK                    RCC_AHB1Periph_GPIOB

#define CA_C_PIN                         GPIO_Pin_1
#define CA_C_GPIO_PORT                   GPIOA
#define CA_C_GPIO_CLK                    RCC_AHB1Periph_GPIOA

#define CA_D_PIN                         GPIO_Pin_5
#define CA_D_GPIO_PORT                   GPIOB
#define CA_D_GPIO_CLK                    RCC_AHB1Periph_GPIOB

#define CA_E_PIN                         GPIO_Pin_11
#define CA_E_GPIO_PORT                   GPIOB
#define CA_E_GPIO_CLK                    RCC_AHB1Periph_GPIOB

#define CA_F_PIN                         GPIO_Pin_2
#define CA_F_GPIO_PORT                   GPIOC
#define CA_F_GPIO_CLK                    RCC_AHB1Periph_GPIOC

#define CA_G_PIN                         GPIO_Pin_4
#define CA_G_GPIO_PORT                   GPIOC
#define CA_G_GPIO_CLK                    RCC_AHB1Periph_GPIOC

#define CA_DP_PIN                        GPIO_Pin_0
#define CA_DP_GPIO_PORT                  GPIOB
#define CA_DP_GPIO_CLK                   RCC_AHB1Periph_GPIOB

#define CA_CLK_PIN                       GPIO_Pin_2
#define CA_CLK_GPIO_PORT                 GPIOD
#define CA_CLK_GPIO_CLK                  RCC_AHB1Periph_GPIOD



#define U_ANn                            10

#define AN_EN_PIN                        GPIO_Pin_4
#define AN_EN_GPIO_PORT                  GPIOB
#define AN_EN_GPIO_CLK                   RCC_AHB1Periph_GPIOB

#define AN_COLON_PIN                     GPIO_Pin_5
#define AN_COLON_GPIO_PORT               GPIOC
#define AN_COLON_GPIO_CLK                RCC_AHB1Periph_GPIOC

#define AN_DIGIT4_PIN                    GPIO_Pin_1
#define AN_DIGIT4_GPIO_PORT              GPIOB
#define AN_DIGIT4_GPIO_CLK               RCC_AHB1Periph_GPIOB

#define AN_DIGIT2_PIN                    GPIO_Pin_1
#define AN_DIGIT2_GPIO_PORT              GPIOA
#define AN_DIGIT2_GPIO_CLK               RCC_AHB1Periph_GPIOA

#define AN_ROT_ENC_PIN                   GPIO_Pin_5
#define AN_ROT_ENC_GPIO_PORT             GPIOB
#define AN_ROT_ENC_GPIO_CLK              RCC_AHB1Periph_GPIOB

#define AN_R_PIN                         GPIO_Pin_11
#define AN_R_GPIO_PORT                   GPIOB
#define AN_R_GPIO_CLK                    RCC_AHB1Periph_GPIOB

#define AN_DIGIT1_PIN                    GPIO_Pin_2
#define AN_DIGIT1_GPIO_PORT              GPIOC
#define AN_DIGIT1_GPIO_CLK               RCC_AHB1Periph_GPIOC

#define AN_DIGIT3_PIN                    GPIO_Pin_4
#define AN_DIGIT3_GPIO_PORT              GPIOC
#define AN_DIGIT3_GPIO_CLK               RCC_AHB1Periph_GPIOC

#define AN_G_PIN                         GPIO_Pin_0
#define AN_G_GPIO_PORT                   GPIOB
#define AN_G_GPIO_CLK                    RCC_AHB1Periph_GPIOB

#define AN_CLK_PIN                       GPIO_Pin_11
#define AN_CLK_GPIO_PORT                 GPIOC
#define AN_CLK_GPIO_CLK                  RCC_AHB1Periph_GPIOC


#define sEE_TIME_CONST                   168 

void ANCA_INIT_All();
void ANCAInit(ANCA_TypeDef Anca);
void ANCA_Set (int ANCA[8]);
void ANCA_Print_Num (int num, int digit, int dot);
void ANCA_Print_Ascii (char c, int digit);

#define QSIZE 20 //realistically, this thing should never have more than 1 item at a time.

typedef struct swevent {
	unsigned int pr : 1 ;  //press-release bit: 1 -- switch was pressed; 0 -- switch was released
	unsigned int sw : 7 ;  //switch number for this event  (with room for expansion)
	unsigned int msec : 24; //time in milliseconds the event occurred (rolls over at 2**24 ms).
} swevent_t;

swevent_t fifo[QSIZE];
unsigned int head = 0, tail = 0;

int queue(swevent_t * in);
swevent_t dequeue();

swevent_t getswitch(void);
void hw8stuff(void);

//__value_in_regs extern swevent_t getswitch(void);

#ifdef __cplusplus
}
#endif

#endif /* __PC4_PERIPH_H */


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
