//=== INCLUDES =============================================================================
#include <string.h>
#include "Arduino.h"
#include "stm32l4xx.h"                  // Device header
#include "Led.h"
#include "Puls.h"

//-----------------------------------------------------------------------------------------
// configuro un pin come input/output
// INPUT:  pin e modalita'
// OUTPUT: //
// AUTORE: Stefano Pagano
// 13/05/21  1.0  Versione iniziale
//-----------------------------------------------------------------------------------------
void pinMode(pin p,dir d){
	int porta=p/16;
	int pin_num=p%16;
	GPIO_TypeDef * gpio= (GPIO_TypeDef *)(AHB2PERIPH_BASE + 0x400*porta);
	
	RCC->AHB2ENR |=1<<porta;
	gpio->MODER &= ~(3<<pin_num*2);
	gpio->MODER |= d<<pin_num*2;
	gpio->PUPDR &= ~(3<<pin_num*2);
}

//-----------------------------------------------------------------------------------------
// configuro un pin come input/output con aggiunta di pull up/pull down
// INPUT:  pin ,modalita' e pu/pd
// OUTPUT: //
// AUTORE: Stefano Pagano
// 13/05/21  1.0  Versione iniziale
//-----------------------------------------------------------------------------------------
void pinModeEx(pin p,dir d,pupd ud){
	int porta=p/16;
	int pin_num=p%16;
	GPIO_TypeDef * gpio= (GPIO_TypeDef *)(AHB2PERIPH_BASE + 0x400*porta);
	
	RCC->AHB2ENR |=1<<porta;
	gpio->MODER &= ~(3<<pin_num*2);
	gpio->MODER |= d<<pin_num*2;
	gpio->PUPDR &= ~(3<<pin_num*2);
	gpio->PUPDR |= (ud<<pin_num*2);
}

//-----------------------------------------------------------------------------------------
// imposto un pin come HIGH o LOW
// INPUT:  pin e stato
// OUTPUT: //
// AUTORE: Stefano Pagano
// 13/05/21  1.0  Versione iniziale
//-----------------------------------------------------------------------------------------
void digitalWrite(pin p, digitalState s){
	int porta=p/16;
	int pin_num=p%16;
	GPIO_TypeDef * gpio= (GPIO_TypeDef *)(AHB2PERIPH_BASE + 0x400*porta);
	gpio->ODR &=~1<<pin_num;
	gpio->ODR |=s<<pin_num;
}

//-----------------------------------------------------------------------------------------
// leggo lo stato di un pin
// INPUT:  pin
// OUTPUT: //
// AUTORE: Stefano Pagano
// 13/05/21  1.0  Versione iniziale
//-----------------------------------------------------------------------------------------
digitalState digitalRead(pin p){
	int porta=p/16;
	int pin_num=p%16;
	GPIO_TypeDef * gpio= (GPIO_TypeDef *)(AHB2PERIPH_BASE + 0x400*porta);
	return (gpio->IDR & 1<<pin_num) >> pin_num;
}

//-----------------------------------------------------------------------------------------
// leggo lo stato di un pin, se e' HIGH aspetto fino al passaggio in LOW e ritorno il tempo
// necessario per questa operazione
// INPUT:  pin e stato
// OUTPUT: tempo per il passaggio di stato
// AUTORE: Stefano Pagano
// 13/05/21  1.0  Versione iniziale
//-----------------------------------------------------------------------------------------
uint32_t  pulseIn(pin p, digitalState stato,int timeout){
//	uint32_t t0,tf,durata;
//	t0=millis();
//	tf=t0;
//	do{
//		tf=millis();
//		durata=tf-t0;
//	}
//	while((digitalRead(p)!=stato) && durata<timeout);
//		if(durata>timeout)
//			return 0;
//		else
//			t0=millis();
//	while(digitalRead(p)==stato);
//	tf=millis();
//	return (tf-t0);
}

//-----------------------------------------------------------------------------------------
// *VECCHIA VERSIONE* configuro un pin come input/output
// INPUT:  pin e modalita'
// OUTPUT: //
// AUTORE: Stefano Pagano
// 13/05/21  1.0  Versione iniziale
//-----------------------------------------------------------------------------------------
void PinModeOld(char *pin,char *mode){
	if(!strcmp("B2",pin)){
		if(!strcmp("OUTPUT",mode))
			LedRossoInit();
	}
	else if(!strcmp("E8",pin)){
		if(!strcmp("OUTPUT",mode))
			LedVerdeInit();
	}
	else if(!strcmp("A0",pin)){
		if(!strcmp("INPUT",mode))
			SwCenterInit();
	}
	else if(!strcmp("A1",pin)){
		if(!strcmp("INPUT",mode))
			SwLeftInit();
	}	
	else if(!strcmp("A2",pin)){
		if(!strcmp("INPUT",mode))
			SwRightInit();
	}	
	else if(!strcmp("A3",pin)){
		if(!strcmp("INPUT",mode))
			SwUpInit();
	}	
	else if(!strcmp("A5",pin)){
		if(!strcmp("INPUT",mode))
			SwDownInit();
	}	
}

//-----------------------------------------------------------------------------------------
// *VECCHIA VERSIONE* imposto un pin come HIGH o LOW
// INPUT:  pin e stato
// OUTPUT: //
// AUTORE: Stefano Pagano
// 13/05/21  1.0  Versione iniziale
//-----------------------------------------------------------------------------------------
void DigitalWriteOld(char *pin,char *mode){
		if(!strcmp("B2",pin)){
			if(!strcmp("HIGH",mode))
				LedRossoOn();
			else if(!strcmp("LOW",mode))
				LedRossoOff();
		}
		if(!strcmp("E8",pin)){
			if(!strcmp("HIGH",mode))
				LedVerdeOn();
			else if(!strcmp("LOW",mode))
				LedVerdeOff();
		}
}
void RilevaColore(void){
	
	pinMode(PA1, INPUT);
	//irDigital = … //lettura pin digitale
  Serial.println(irDigital);
  delay(500);  //Ritardo tra letture successive
}
