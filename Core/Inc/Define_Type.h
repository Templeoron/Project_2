/*********************************************************************************************************
* 模块名称: Define_Type.h
* 摘    要: 
* 当前版本: 1.0.0
* 作    者: Oron
* 创建日期: 2025-11-25
* 内    容: 
* 注    意: none 
**********************************************************************************************************
* 取代版本: 
* 作    者: 
* 完成日期: 
* 修改内容: 
* 修改文件: 
*********************************************************************************************************/
#ifndef __DEFINE_TYPE_H__
#define __DEFINE_TYPE_H__
/*********************************************************************************************************
*                                              包含头文件
*********************************************************************************************************/

/*********************************************************************************************************
*                                              宏定义
*********************************************************************************************************/
#define TRUE        1
#define FALSE       0

#define ENABLE      1
#define DISABLE     0

#define SET         1
#define RESET       0
//-------------------------------------------------------------------------
#define	SetBit(x,y)     x |= (1 << y)		//将寄存器x的第y位置1
#define ClrBit(x,y)     x &= ~(1 << y)		//将寄存器x的第y位清0
//-------------------------------------------------------------------------

#define uchar  unsigned char
#define uint   unsigned int
#define ulong  unsigned long
	
//-------------------------------------------------------------------------
//IO口操作宏定义
#define BITBAND(addr, bitnum) ((addr & 0xF0000000)+0x2000000+((addr &0xFFFFF)<<5)+(bitnum<<2)) 
#define MEM_ADDR(addr)  *((volatile unsigned long  *)(addr)) 
#define BIT_ADDR(addr, bitnum)   MEM_ADDR(BITBAND(addr, bitnum)) 
//-------------------------------------------------------------------------
//IO口地址映射
#define GPIOA_ODR_Addr    (GPIOA_BASE+12) //0x4001080C 
#define GPIOB_ODR_Addr    (GPIOB_BASE+12) //0x40010C0C 
#define GPIOC_ODR_Addr    (GPIOC_BASE+12) //0x4001100C 
#define GPIOD_ODR_Addr    (GPIOD_BASE+12) //0x4001140C 
#define GPIOE_ODR_Addr    (GPIOE_BASE+12) //0x4001180C 
#define GPIOF_ODR_Addr    (GPIOF_BASE+12) //0x40011A0C    
#define GPIOG_ODR_Addr    (GPIOG_BASE+12) //0x40011E0C    

#define GPIOA_IDR_Addr    (GPIOA_BASE+8) //0x40010808 
#define GPIOB_IDR_Addr    (GPIOB_BASE+8) //0x40010C08 
#define GPIOC_IDR_Addr    (GPIOC_BASE+8) //0x40011008 
#define GPIOD_IDR_Addr    (GPIOD_BASE+8) //0x40011408 
#define GPIOE_IDR_Addr    (GPIOE_BASE+8) //0x40011808 
#define GPIOF_IDR_Addr    (GPIOF_BASE+8) //0x40011A08 
#define GPIOG_IDR_Addr    (GPIOG_BASE+8) //0x40011E08 
//-------------------------------------------------------------------------
//IO口操作,只对单一的IO口!
//确保n的值小于16!
#define PAout(n)   BIT_ADDR(GPIOA_ODR_Addr,n)  //输出 
#define PAin(n)    BIT_ADDR(GPIOA_IDR_Addr,n)  //输入 

#define PBout(n)   BIT_ADDR(GPIOB_ODR_Addr,n)  //输出 
#define PBin(n)    BIT_ADDR(GPIOB_IDR_Addr,n)  //输入 

#define PCout(n)   BIT_ADDR(GPIOC_ODR_Addr,n)  //输出 
#define PCin(n)    BIT_ADDR(GPIOC_IDR_Addr,n)  //输入 

#define PDout(n)   BIT_ADDR(GPIOD_ODR_Addr,n)  //输出 
#define PDin(n)    BIT_ADDR(GPIOD_IDR_Addr,n)  //输入 

#define PEout(n)   BIT_ADDR(GPIOE_ODR_Addr,n)  //输出 
#define PEin(n)    BIT_ADDR(GPIOE_IDR_Addr,n)  //输入

#define PFout(n)   BIT_ADDR(GPIOF_ODR_Addr,n)  //输出 
#define PFin(n)    BIT_ADDR(GPIOF_IDR_Addr,n)  //输入

#define PGout(n)   BIT_ADDR(GPIOG_ODR_Addr,n)  //输出 
#define PGin(n)    BIT_ADDR(GPIOG_IDR_Addr,n)  //输入
//-------------------------------------------------------------------------

/*数码管段选显示*/
#define SEG_A		0x01		
#define SEG_B		0x02
#define SEG_C		0x04		
#define SEG_D		0x08	
#define SEG_E		0x10
#define SEG_F		0x20		
#define SEG_G		0x40

/* 数码管数字和字母显示 */
#define NUMBER_0    (SEG_A + SEG_B + SEG_C + SEG_D + SEG_E + SEG_F)
#define NUMBER_1    (SEG_B + SEG_C)
#define NUMBER_2    (SEG_A + SEG_B + SEG_G + SEG_E + SEG_D)
#define NUMBER_3    (SEG_A + SEG_B + SEG_G + SEG_C + SEG_D)
#define NUMBER_4    (SEG_F + SEG_G + SEG_B + SEG_C)
#define NUMBER_5    (SEG_A + SEG_F + SEG_G + SEG_C + SEG_D)
#define NUMBER_6    (SEG_A + SEG_F + SEG_G + SEG_C + SEG_D + SEG_E)
#define NUMBER_7    (SEG_A + SEG_B + SEG_C)
#define NUMBER_8    (SEG_A + SEG_B + SEG_C + SEG_D + SEG_E + SEG_F + SEG_G)
#define NUMBER_9    (SEG_A + SEG_B + SEG_C + SEG_D + SEG_F + SEG_G)

#define DSP_A       (SEG_A + SEG_B + SEG_C + SEG_E + SEG_F + SEG_G)
#define DSP_b       (SEG_C + SEG_D + SEG_E + SEG_F + SEG_G)
#define DSP_c       (SEG_D + SEG_E + SEG_G)
#define DSP_C       (SEG_A + SEG_D + SEG_E + SEG_F)
#define DSP_d       (SEG_B + SEG_C + SEG_D + SEG_E + SEG_G)
#define DSP_E       (SEG_A + SEG_D + SEG_E + SEG_F + SEG_G)
#define DSP_F       (SEG_A + SEG_E + SEG_F + SEG_G)
#define DSP_H       (SEG_B + SEG_C + SEG_E + SEG_F + SEG_G)
#define DSP_o       (SEG_C + SEG_D + SEG_E + SEG_G)  
#define DSP_O		(SEG_A + SEG_B + SEG_C + SEG_D + SEG_E + SEG_F)
#define DSP_n       (SEG_C + SEG_E + SEG_G)  
#define DSP_N       (SEG_A + SEG_B + SEG_C + SEG_E + SEG_F)
#define DSP_L       (SEG_D + SEG_E + SEG_F)
#define DSP_P       (SEG_A + SEG_B + SEG_E + SEG_F + SEG_G)
#define DSP_U       (SEG_B + SEG_C + SEG_D + SEG_E + SEG_F)
#define DSP_ALL     (SEG_A + SEG_B + SEG_C + SEG_D + SEG_E + SEG_F + SEG_G + SEG_H)
#define DSP_CROSS   (SEG_G)
/*********************************************************************************************************
*                                              全局变量
*********************************************************************************************************/

/*********************************************************************************************************
*                                              枚举结构体定义
*********************************************************************************************************/
typedef union
{
    unsigned char  all;
    struct
    {
       unsigned char b0:1;
       unsigned char b1:1;
       unsigned char b2:1;
       unsigned char b3:1;
       unsigned char b4:1;
       unsigned char b5:1;
       unsigned char b6:1;
       unsigned char b7:1;
    }one;
}bits;
/*********************************************************************************************************
*                                              API函数声明
*********************************************************************************************************/


#endif


