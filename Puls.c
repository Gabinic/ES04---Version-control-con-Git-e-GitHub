//=== INCLUDES =============================================================================
#include "stm32l4xx.h"
#include "Puls.h"
#include "Led.h"
#include "Arduino.h"
#include "LCD.h"
#include <stdio.h>
#include "FreeRTOS.h"
#include "task.h"

char click=0;

//-----------------------------------------------------------------------------------------
// Inizializzazione dei 5 pulsanti
// INPUT:  //
// OUTPUT: //
// AUTORE: Stefano Pagano
// 13/05/21  1.0  Versione iniziale
//-----------------------------------------------------------------------------------------
void SwInit(void){
	SwCenterInit();
	SwLeftInit();
	SwRightInit();
	SwUpInit();
	SwDownInit();
}

void SwCenterInit(void){
	//inizializzo pulsante centrale
	RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;
	GPIOA->MODER &= ~GPIO_MODER_MODE0_0;
	GPIOA->MODER &= ~GPIO_MODER_MODE0_1;
	GPIOA->PUPDR &= ~GPIO_PUPDR_PUPD0_0;
	GPIOA->PUPDR |= GPIO_PUPDR_PUPD0_1;
}

void SwLeftInit(void){
	//inizializzo pulsante sinistro
	RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;
	GPIOA->MODER &= ~GPIO_MODER_MODE1_0;
	GPIOA->MODER &= ~GPIO_MODER_MODE1_1;
	GPIOA->PUPDR &= ~GPIO_PUPDR_PUPD1_0;
	GPIOA->PUPDR |= GPIO_PUPDR_PUPD1_1;
}

void SwRightInit(void){
	//inizializzo pulsante destro
	RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;
	GPIOA->MODER &= ~GPIO_MODER_MODE2_0;
	GPIOA->MODER &= ~GPIO_MODER_MODE2_1;
	GPIOA->PUPDR &= ~GPIO_PUPDR_PUPD2_0;
	GPIOA->PUPDR |= GPIO_PUPDR_PUPD2_1;
}

void SwUpInit(void){
	//inizializzo pulsante superiore
	RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;
	GPIOA->MODER &= ~GPIO_MODER_MODE3_0;
	GPIOA->MODER &= ~GPIO_MODER_MODE3_1;
	GPIOA->PUPDR &= ~GPIO_PUPDR_PUPD3_0;
	GPIOA->PUPDR |= GPIO_PUPDR_PUPD3_1;
}

void SwDownInit(void){
	//inizializzo pulsante inferiore
	RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;
	GPIOA->MODER &= ~GPIO_MODER_MODE5_0;
	GPIOA->MODER &= ~GPIO_MODER_MODE5_1;
	GPIOA->PUPDR &= ~GPIO_PUPDR_PUPD5_0;
	GPIOA->PUPDR |= GPIO_PUPDR_PUPD5_1;
}

//-----------------------------------------------------------------------------------------
// verifico pressione pulsante centrale
// INPUT:  //
// OUTPUT: //
// AUTORE: Stefano Pagano
// 13/05/21  1.0  Versione iniziale
//-----------------------------------------------------------------------------------------
int SwCenterPress()
{
	if(!digitalRead(PA0))
		return 0;
	else
		return 1;
}

//-----------------------------------------------------------------------------------------
// verifico pressione pulsante sinistro
// INPUT:  //
// OUTPUT: //
// AUTORE: Stefano Pagano
// 13/05/21  1.0  Versione iniziale
//-----------------------------------------------------------------------------------------
int SwLeftPress()
{
	if(!digitalRead(PA1))
		return 0;
	else
		return 1;
}

//-----------------------------------------------------------------------------------------
// verifico pressione pulsante destro
// INPUT:  //
// OUTPUT: //
// AUTORE: Stefano Pagano
// 13/05/21  1.0  Versione iniziale
//-----------------------------------------------------------------------------------------
int SwRightPress()
{
	if(!digitalRead(PA2))
		return 0;
	else
		return 1;
}

//-----------------------------------------------------------------------------------------
// verifico pressione pulsante superiore
// INPUT:  //
// OUTPUT: //
// AUTORE: Stefano Pagano
// 13/05/21  1.0  Versione iniziale
//-----------------------------------------------------------------------------------------
int SwUpPress()
{
	if(!digitalRead(PA3))
		return 0;
	else
		return 1;
}

//-----------------------------------------------------------------------------------------
// verifico pressione pulsante inferiore
// INPUT:  //
// OUTPUT: //
// AUTORE: Stefano Pagano
// 13/05/21  1.0  Versione iniziale
//-----------------------------------------------------------------------------------------
int SwDownPress()
{
	if(!digitalRead(PA5))
		return 0;
	else
		return 1;
}

//-----------------------------------------------------------------------------------------
// testo i 5 pulsanti
// INPUT:  //
// OUTPUT: //
// AUTORE: Stefano Pagano
// 13/05/21  1.0  Versione iniziale
//-----------------------------------------------------------------------------------------
void SwTest(){
	if(SwUpPress())							//premo tasto superiore
		LedRossoOn();									//accendo led rosso
	
	else if(SwDownPress())				//premo tasto inferiore
		LedRossoOff();								//spengo led rosso
	
	else if(SwLeftPress())				//premo tasto sinistro
		LedVerdeOn();									//accendo led verde
	
	else if(SwRightPress())				//premo tasto destro
		LedVerdeOff();									//spengo led verde
	
	else if(SwCenterPress()){	 		//premo tasto centrale
		LedRossoToggle();							 //inverto stato di entrambi i led
		LedVerdeToggle();
	}
}

//-----------------------------------------------------------------------------------------
// verifico click pulsante sinistro (click=pressione+rilascio)
// INPUT:  //
// OUTPUT: //
// AUTORE: Stefano Pagano
// 13/05/21  1.0  Versione iniziale
//-----------------------------------------------------------------------------------------
int SwLeftClick(){
	//verifico se il pulsante è premuto
	if(digitalRead(PA1)){
		//aspetto che il pulsante venga rilasciato
		while(digitalRead(PA1)){
		}
		return 1;
	}
	else
		return 0;
}

//-----------------------------------------------------------------------------------------
// verifico click pulsante destro (click=pressione+rilascio)
// INPUT:  //
// OUTPUT: //
// AUTORE: Stefano Pagano
// 13/05/21  1.0  Versione iniziale
//-----------------------------------------------------------------------------------------
int SwRightClick(){
	//verifico se il pulsante è premuto
	if(digitalRead(PA2)){
		//aspetto che il pulsante venga rilasciato
		while(digitalRead(PA2)){
		}
		return 1;
	}
	else
		return 0;
}

//-----------------------------------------------------------------------------------------
// *VECCHIA VERSIONE*verifico click pulsante destro (click=pressione+rilascio)
// INPUT:  //
// OUTPUT: //
// AUTORE: Stefano Pagano
// 13/05/21  1.0  Versione iniziale
//-----------------------------------------------------------------------------------------
int SwRightClickOld(){
	static int valSwOld=0;
	static char valSw;
	valSw = digitalRead(PA2);
	//verifico se il pulsante è premuto
	if(valSw==HIGH && valSwOld==0){
		valSwOld = 1;
	// Il pulsante è stato premuto
	}
	if(valSw==LOW && valSwOld==1){
	// Il pulsante è stato rilasciato
		valSwOld = 0;
		return 1;
	}
	else
		return 0;
}

//-----------------------------------------------------------------------------------------
// *VECCHIA VERSIONE* verifico click pulsante sinistro (click=pressione+rilascio)
// INPUT:  //
// OUTPUT: //
// AUTORE: Stefano Pagano
// 13/05/21  1.0  Versione iniziale
//-----------------------------------------------------------------------------------------
int SwLeftClickOld(){
	static int valSwOld=0;
	static char valSw;
	valSw = digitalRead(PA1);
	//verifico se il pulsante è premuto
	if(valSw==HIGH && valSwOld==0){
		valSwOld = 1;
	// Il pulsante è stato premuto
	}
	if(valSw==LOW && valSwOld==1){
	// Il pulsante è stato rilasciato
		valSwOld = 0;
		return 1;
	}
	else
		return 0;
}

//-----------------------------------------------------------------------------------------
// verifico doppio click pulsante destro (click=pressione+rilascio)
// INPUT:  //
// OUTPUT: //
// AUTORE: Stefano Pagano
// 13/05/21  1.0  Versione iniziale
//-----------------------------------------------------------------------------------------
int SwRight2Click(){
	//se il pulsante viene cliccato aspetto il secondo click
	while(SwRightClick()==0){
	}
	//aspetto il secondo click
	while(SwRightClick()==0){
	}
		return 1;
}

//-----------------------------------------------------------------------------------------
// verifico pressione lunga pulsante inferiore (pressione > 3s)
// INPUT:  //
// OUTPUT: //
// AUTORE: Stefano Pagano
// 13/05/21  1.0  Versione iniziale
//-----------------------------------------------------------------------------------------
int SwDownLPress(){
	//se il pulsante viene premuto aspetto
	if(SwDownPress()){
		//utilizzo systick per aspettare 3 secondi
			vTaskDelay(3000);
			if(SwDownPress()!=1)
				return 0;
			else
				return 1;
		}
		return 0;
	}

//-----------------------------------------------------------------------------------------
// verifico click pulsante sinistro (click=pressione+rilascio) con variabili globali
// INPUT:  //
// OUTPUT: //
// AUTORE: Stefano Pagano
// 13/05/21  1.0  Versione iniziale
//-----------------------------------------------------------------------------------------
void SwLeftClickTask(){
	//verifico se il pulsante è premuto
	if(digitalRead(PA1)){
		//aspetto che il pulsante venga rilasciato
		while(digitalRead(PA1)){
		}
		click=1;
	}
	else
		click=0;
}	
	

	//DA TESTARE


//-----------------------------------------------------------------------------------------
// lampeggio del led con tempo base 2000ms, ad ogni click velocizzo di 100ms
// INPUT:  //
// OUTPUT: //
// AUTORE: Stefano Pagano
// 13/05/21  1.0  Versione iniziale
//-----------------------------------------------------------------------------------------
void LedVerdeSwTask(){
	static int startTime=2000;
	if(click==1){
		startTime=startTime-100;
		click=0;
	}
	if(startTime <= 0)
		startTime=2000;
	LedVerdeToggle();
	vTaskDelay(startTime);
}


//-----------------------------------------------------------------------------------------
// testo le diverse pressioni dei pulsanti
// INPUT:  //
// OUTPUT: //
// AUTORE: Stefano Pagano
// 13/05/21  1.0  Versione iniziale
//-----------------------------------------------------------------------------------------
void TestPressSw(){
	if(SwUpPress())							//premo tasto superiore
		LedRossoOn();									//accendo led rosso
	
	else if(SwDownLPress())			//premo tasto inferiore per 3 secondi
		LedRossoOff();								//spengo led rosso
	
	else if(SwLeftClick())				//click tasto sinistro
		LedVerdeOn();									//accendo led verde
	
	else if(SwRight2Click())				//doppio click tasto destro
		LedVerdeOff();									//spengo led verde
}


//-----------------------------------------------------------------------------------------
// stampo su display LCD tempo di pressione tasto
// INPUT:  pin e stato
// OUTPUT: //
// AUTORE: Stefano Pagano
// 13/10/21  1.0  Versione iniziale
//-----------------------------------------------------------------------------------------
void TimeSwPress(pin p, digitalState stato,int timeout){
		char c[10];
		float durata;
		durata=pulseIn(p,stato,timeout);
		sprintf(c,"%.lf",durata);
		//LCDClear();
		//LCDDisplayString((uint8_t *)c);
}
