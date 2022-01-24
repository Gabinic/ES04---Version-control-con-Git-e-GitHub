/** ****************************************************************************************
* @file Puls.h
* @brief Libreria contenente tutte le funzoni utili per utilizzare e gestire LCD
* 
* @author Stefano Pagano
* @date 23/11/21
* @version 1.0 23/11/21 inserite funzioni per gestire LCD
*/

#ifndef __STM32L476G_DISCOVERY_LCD_H

//------------------------------------------------------------------------------------------
//=== INCLUDES =============================================================================
//------------------------------------------------------------------------------------------
#include <stdint.h>

//=== CONSTANTS ============================================================================
#define bool _Bool
#define __STM32L476G_DISCOVERY_LCD_H
typedef enum{BAR0,BAR1,BAR2,BAR3} bar;

 /** ****************************************************************************************
* @brief Inizializzazione display LCD
* @author Stefano Pagano
* @date 23/11/21
* @version 1.0 23/11/21
*/
void LCDInitialization(void);

 /** ****************************************************************************************
* @brief Scrivo il valore della barra nel frame buffer dell'LCD
* @author Stefano Pagano
* @date 23/11/21
* @version 1.0 23/11/21
*/
void LCDBar(void);

 /** ****************************************************************************************
* @brief Inizializzo clock per LCD
* @author Stefano Pagano
* @date 23/11/21
* @version 1.0 23/11/21
*/
void LCDClockInit(void);


void LCDPinInit(void);
void LCDConfigure(void);
void LCDClear(void);
void LCDDisplayString(uint8_t* ptr);
void LCDDisplayStringEx(uint8_t* ptr);
void LCDWriteChar(uint8_t* ch, bool point, bool colon, uint8_t position);
static void LCDConvCharSeg(uint8_t* c,bool point,bool colon, uint8_t* digit);
void LCDDisplayName(void);
void LCDContrastoUp(void);
void LCDContrastoDown(void);
uint8_t LCDContrastoValue(void);
void LCDContrastoSet(uint8_t c);
void LCDbarOn(bar b);
void LCDbarOff(bar b);
#endif /* __STM32L476G_DISCOVERY_LCD_H */
