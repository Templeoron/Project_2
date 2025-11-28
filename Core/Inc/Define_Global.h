/*********************************************************************************************************
* 模块名称: var.h
* 摘    要:
* 当前版本: 1.0.0
* 作    者: Oron
* 创建日期: 2025-11-24
* 内    容:
* 注    意: none
**********************************************************************************************************
* 取代版本:
* 作    者:
* 完成日期:
* 修改内容:
* 修改文件:
*********************************************************************************************************/
#ifndef __VAR_H__
#define __VAR_H__
/*********************************************************************************************************
*                                              包含头文件
*********************************************************************************************************/
#include "main.h"
#include "Define_Type.h"
/*********************************************************************************************************
*                                              宏定义
*********************************************************************************************************/
#define 	BEEP	PBout(8)   	//BEEP
#define 	LED0	PBout(5)   	//LED0
#define 	LED1	PEout(5)   	//LED1

#define   	TM1638_CLK_H()   	HAL_GPIO_WritePin(TM1638_CLK_GPIO_Port, TM1638_CLK_Pin, GPIO_PIN_SET)
#define   	TM1638_CLK_L()   	HAL_GPIO_WritePin(TM1638_CLK_GPIO_Port, TM1638_CLK_Pin, GPIO_PIN_RESET)

#define   	TM1638_DIO_H()   	HAL_GPIO_WritePin(TM1638_DIO_GPIO_Port, TM1638_DIO_Pin, GPIO_PIN_SET)
#define   	TM1638_DIO_L()   	HAL_GPIO_WritePin(TM1638_DIO_GPIO_Port, TM1638_DIO_Pin, GPIO_PIN_RESET)

#define   	TM1638_STB_H()   	HAL_GPIO_WritePin(TM1638_STB_GPIO_Port, TM1638_STB_Pin, GPIO_PIN_SET)
#define   	TM1638_STB_L()   	HAL_GPIO_WritePin(TM1638_STB_GPIO_Port, TM1638_STB_Pin, GPIO_PIN_RESET)

#define 	KEY0				HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0)
#define 	KEY1				HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1)
	
#define 	KEY0_PRES			1
#define 	KEY1_PRES			2

#define 	DHT11_HIGH     		HAL_GPIO_WritePin(DTI11_GPIO_Port, DTI11_Pin,	GPIO_PIN_SET) //输出高电平
#define 	DHT11_LOW     		HAL_GPIO_WritePin(DTI11_GPIO_Port, DTI11_Pin, GPIO_PIN_RESET)//输出低电平

#define 	DHT11_IO_IN      	HAL_GPIO_ReadPin(DTI11_GPIO_Port, DTI11_Pin)//读取IO口电平
/*********************************************************************************************************
*                                              全局变量
*********************************************************************************************************/
extern 	volatile bits	StateF;
#define 	Flag_StateF			StateF.all
#define 	Standby_B			StateF.one.b0
#define 	PowerON_B			StateF.one.b1

extern 	volatile bits	OtherF;
#define 	Flag_OtherF			OtherF.all
#define 	Flag_Main_4ms		OtherF.one.b0
#define 	Flag_DisplayAll		OtherF.one.b1
#define 	Flag_Time_500ms		OtherF.one.b2
#define 	Flag_BeepEn			OtherF.one.b3
/*********************************************************************************************************
*                                              枚举结构体定义
*********************************************************************************************************/
typedef struct
{
    uint8_t Beep;  // 蜂鸣器计数
}CNT;

typedef struct 
{
    float Distance;  // 距离
}hc_sr04;

extern CNT Cnt;
extern hc_sr04 HC_SR04;
/*********************************************************************************************************
*                                              API函数声明
*********************************************************************************************************/
void Task_20ms_DIV(void);
void User_Init(void);
void delay_us(uint32_t us);

void Buzzer_ShortBeep(void);
void Buzzer_LongBeep(void);
void Buzzer_Event(void);

uint8_t Key_Scan(void);
void Key_Program(void);

void Display_Program(void);
void Timer_Program(void);

void TM1638_DisPlayDriver(void);
uint8_t TM1638_ReadKey(void);

float Get_Temprate(void);

#endif


