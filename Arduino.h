/** ****************************************************************************************
* @file Arduino.h
* @brief Libreria contenente tutte le funzoni utili per simulare arduino
* 
* @author Stefano Pagano
* @date 23/11/21
* @version 1.0 23/11/21 inserite funzioni per simulare arduino
*/

//------------------------------------------------------------------------------------------
//=== INCLUDES =============================================================================
//------------------------------------------------------------------------------------------
#include <stdint.h>

typedef enum{PA0,PA1,PA2,PA3,PA4,PA5,PA6,PA7,PA8,PA9,PA10,PA11,PA12,PA13,PA14,PA15,
						 PB0,PB1,PB2,PB3,PB4,PB5,PB6,PB7,PB8,PB9,PB10,PB11,PB12,PB13,PB14,PB15,
						 PC0,PC1,PC2,PC3,PC4,PC5,PC6,PC7,PC8,PC9,PC10,PC11,PC12,PC13,PC14,PC15,
             PD0,PD1,PD2,PD3,PD4,PD5,PD6,PD7,PD8,PD9,PD10,PD11,PD12,PD13,PD14,PD15,
						 PE0,PE1,PE2,PE3,PE4,PE5,PE6,PE7,PE8,PE9,PE10,PE11,PE12,PE13,PE14,PE15,
						 PF0,PF1,PF2,PF3,PF4,PF5,PF6,PF7,PF8,PF9,PF10,PF11,PF12,PF13,PF14,PF15,
						 PG0,PG1,PG2,PG3,PG4,PG5,PG6,PG7,PG8,PG9,PG10,PG11,PG12,PG13,PG14,PG15,
						 PH0,PH1,PH2,PH3,PH4,PH5,PH6,PH7,PH8,PH9,PH10,PH11,PH12,PH13,PH14,PH15} pin;
typedef enum{INPUT,OUTPUT} dir;
typedef enum{PULLUP=1,PULLDOWN} pupd;
typedef enum{LOW,HIGH} digitalState;


 /** ****************************************************************************************
* @brief Inizializzazione di una porta
* @param  pin e dir(INPUT/OUTPUT)
* @author Stefano Pagano
* @date 23/11/21
* @version 1.0 23/11/21
*/
void pinMode(pin,dir);

 /** ****************************************************************************************
* @brief Inizializzazione di una porta input con pullup o pulldown
* @param  pin, dir(INPUT/OUTPUT) e pupd(PULLUP/PULLDOWN)
* @author Stefano Pagano
* @date 23/11/21
* @version 1.0 23/11/21
*/
void pinModeEx(pin,dir,pupd);

 /** ****************************************************************************************
* @brief Metto HIGH o LOW una porta
* @param  pin e digitalState(HIGH/LOW)
* @author Stefano Pagano
* @date 23/11/21
* @version 1.0 23/11/21
*/
void digitalWrite(pin, digitalState);

 /** ****************************************************************************************
* @brief Leggo valore di una porta
* @param  pin
* @author Stefano Pagano
* @date 23/11/21
* @version 1.0 23/11/21
*/
digitalState digitalRead(pin);

 /** ****************************************************************************************
* @brief Misuro impulso su una porta
* @param  pin, digitalState(HIGH/LOW), timeout
* @author Stefano Pagano
* @date 23/11/21
* @version 1.0 23/11/21
*/
uint32_t  pulseIn(pin, digitalState,int timeout);

 /** ****************************************************************************************
* @brief *VECCHIA VERSIONE* Inizializzazione di una porta
* @param  pin e mode(INPUT/OUTPUT)
* @author Stefano Pagano
* @date 23/11/21
* @version 1.0 23/11/21
*/
void PinModeOld(char *pin,char *mode);

 /** ****************************************************************************************
* @brief *VECCHIA VERSIONE* Metto HIGH o LOW una porta
* @param  pin e mode(HIGH/LOW)
* @author Stefano Pagano
* @date 23/11/21
* @version 1.0 23/11/21
*/
void DigitalWriteOld(char *pin,char *mode);

 /** ****************************************************************************************
* @brief Stampo su display LCD tempo di pressione tasto
* @param  pin, digitalState(HIGH/LOW), timeout
* @author Stefano Pagano
* @date 23/11/21
* @version 1.0 23/11/21
*/
void TimeSwPress(pin,digitalState,int timeout);

 /** ****************************************************************************************
* @brief Lampeggio del led in base ai parametri inseriti
* @param  pin, ritardo e ncicli(num lampeggi)
* @author Stefano Pagano
* @date 23/11/21
* @version 1.0 23/11/21
*/
void LedBlink(pin p,int ritardo, int ncicli);
