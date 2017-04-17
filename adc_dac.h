/**
  ******************************************************************************
  * @file    adc_dac.h
  * @author  Vu Trung Hieu
  * @version V1.0
  * @date    17-April-2017
  * @brief   This file contains all the functions prototypes for adc_dac
  *          library.  
  ******************************************************************************
  * @attention
  *
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __ADC_DAC_H
#define __ADC_DAC_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx.h"

/* Define --------------------------------------------------------------------*/


/* Initialization and Configuration functions --------------------------------*/
void ADC_DMA_Init(void);

/* Start & Stop function -------------------------------------------------------------*/

#ifdef __cplusplus
}
#endif

#endif /*__ADC_DAC_H */


/*********************************END OF FILE**********************************/
