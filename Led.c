//=== INCLUDES =============================================================================
#include "stm32l4xx.h"
#include "Led.h"
#include "Arduino.h"
#include "Puls.h"
#include <string.h>
#include "FreeRTOS.h"
#include "task.h"

//-----------------------------------------------------------------------------------------
// inizializzazione led rosso (PB2) e led verde (PE8)
// INPUT:  //
// OUTPUT: //
// AUTORE: Stefano Pagano
//30/04/21  1.0  Versione iniziale
//-----------------------------------------------------------------------------------------
void LedInit(void){
	LedRossoInit();
	LedVerdeInit();
}

void LedRossoInit(void){
	RCC->AHB2ENR |= RCC_AHB2ENR_GPIOBEN;
	GPIOB->MODER |= GPIO_MODER_MODE2_0;
	GPIOB->MODER &= ~GPIO_MODER_MODE2_1;
}

void LedVerdeInit(void){
	RCC->AHB2ENR |= RCC_AHB2ENR_GPIOEEN;
	GPIOE->MODER |= GPIO_MODER_MODE8_0;
	GPIOE->MODER &= ~GPIO_MODER_MODE8_1;
}

//-----------------------------------------------------------------------------------------
// accensione led rosso
// INPUT:  //
// OUTPUT: //
// AUTORE: Stefano Pagano
//30/04/21  1.0  Versione iniziale
//-----------------------------------------------------------------------------------------
void LedRossoOn(void){
	GPIOB->ODR |= GPIO_ODR_OD2;
}

//-----------------------------------------------------------------------------------------
// spegnimento led rosso
// INPUT:  //
// OUTPUT: //
// AUTORE: Stefano Pagano
//30/04/21  1.0  Versione iniziale
//-----------------------------------------------------------------------------------------
void LedRossoOff(void){
	GPIOB->ODR &= ~GPIO_ODR_OD2;
}

//-----------------------------------------------------------------------------------------
// inversione stato led rosso
// INPUT:  //
// OUTPUT: //
// AUTORE: Stefano Pagano
//30/04/21  1.0  Versione iniziale
//-----------------------------------------------------------------------------------------
void LedRossoToggle(void){
	GPIOB->ODR ^= GPIO_ODR_OD2;
}

//-----------------------------------------------------------------------------------------
// accensione led verde
// INPUT:  //
// OUTPUT: //
// AUTORE: Stefano Pagano
//30/04/21  1.0  Versione iniziale
//-----------------------------------------------------------------------------------------
void LedVerdeOn(void){
	GPIOE->ODR |= GPIO_ODR_OD8;
}

//-----------------------------------------------------------------------------------------
// spegnimento led verde
// INPUT:  //
// OUTPUT: //
// AUTORE: Stefano Pagano
//30/04/21  1.0  Versione iniziale
//-----------------------------------------------------------------------------------------
void LedVerdeOff(void){
	GPIOE->ODR &= ~GPIO_ODR_OD8;
}

//-----------------------------------------------------------------------------------------
// inversione stato led verde
// INPUT:  //
// OUTPUT: //
// AUTORE: Stefano Pagano
//30/04/21  1.0  Versione iniziale
//-----------------------------------------------------------------------------------------
void LedVerdeToggle(void){
	GPIOE->ODR ^= GPIO_ODR_OD8;
}


//-----------------------------------------------------------------------------------------
// lampeggio led rosso
// INPUT:  ritardo=ms di ritardo, ncicli=numero lampeggi
// OUTPUT: //
// AUTORE: Stefano Pagano
//30/04/21  1.0  Versione iniziale
//-----------------------------------------------------------------------------------------
void LedRossoBlink(int ritardo,int ncicli){
	int i=0;
	while(i<ncicli){
		vTaskDelay(ritardo);
		LedRossoToggle();
		vTaskDelay(ritardo);
		LedRossoToggle();
		i++;
	}
}

//-----------------------------------------------------------------------------------------
// lampeggio led verde
// INPUT:  ritardo=ms di ritardo, ncicli=numero lampeggi
// OUTPUT: //
// AUTORE: Stefano Pagano
//30/04/21  1.0  Versione iniziale
//-----------------------------------------------------------------------------------------
void LedVerdeBlink(int ritardo,int ncicli){
	int i=0;
	while(i<ncicli){
		vTaskDelay(ritardo);
		LedVerdeToggle();
		vTaskDelay(ritardo);
		LedVerdeToggle();
		i++;
	}
}

//-----------------------------------------------------------------------------------------
// test dei due led 
// INPUT:  //
// OUTPUT: //
// AUTORE: Stefano Pagano
//30/04/21  1.0  Versione iniziale
//-----------------------------------------------------------------------------------------
void LedTest(void){
	int i=0;
	while(i<10){
		vTaskDelay(100);
		LedRossoToggle();
		LedVerdeToggle();
		vTaskDelay(100);
		LedRossoToggle();
		LedVerdeToggle();
		i++;
	}
}

//-----------------------------------------------------------------------------------------
// lampeggio del led in base ai parametri inseriti
// INPUT:  colore led, ritardo e numero lampeggi
// OUTPUT: //
// AUTORE: Stefano Pagano
//30/04/21  1.0  Versione iniziale
//-----------------------------------------------------------------------------------------
void LedBlink(pin p,int ritardo, int ncicli){
	int i=0;
	while(i<ncicli){
		delay(ritardo);
		LedRossoToggle();
		delay(ritardo);
		LedRossoToggle();
		i++;
	}
}

//-----------------------------------------------------------------------------------------
// lampeggio del led rosso in base ai parametri inseriti 
// INPUT:  tempo(ms) led acceso e tempo(ms) totale   
// tempo totale = tempo led accesso + tempo led spento
// OUTPUT: //
// AUTORE: Stefano Pagano
//30/04/21  1.0  Versione iniziale
//-----------------------------------------------------------------------------------------
void LedRossoTask(int Ton,int Toff){
	LedRossoOn();
	vTaskDelay(Ton);
	LedRossoOff();
	vTaskDelay(Toff);
}


//-----------------------------------------------------------------------------------------
// lampeggio del led verde in base ai parametri inseriti 
// INPUT:  tempo(ms) led acceso e tempo(ms) totale   
// tempo totale = tempo led accesso + tempo led spento
// OUTPUT: //
// AUTORE: Stefano Pagano
//30/04/21  1.0  Versione iniziale
//-----------------------------------------------------------------------------------------
void LedVerdeTask(int Ton,int Toff){
	LedVerdeOn();
	vTaskDelay(Ton);
	LedVerdeOff();
	vTaskDelay(Toff);
}

//-----------------------------------------------------------------------------------------
// lampeggio del led verde in base al parametri inserito
// INPUT:  tempo lampeggio (in ms) 
// tempo totale = tempo led accesso + tempo led spento
// OUTPUT: //
// AUTORE: Stefano Pagano
//30/04/21  1.0  Versione iniziale
//-----------------------------------------------------------------------------------------
void LedVerdeBlinkTask(int startTime){
	LedVerdeToggle();
	vTaskDelay(startTime);
}

void LedRossoBlinkTask(int startTime){
	LedRossoToggle();
	vTaskDelay(startTime);
}
