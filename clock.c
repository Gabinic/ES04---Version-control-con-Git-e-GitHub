//=== INCLUDES =============================================================================
#include "clock.h"
#include "stm32l4xx.h"                  // Device header


void MSIInit(uint8_t range){
	FLASH->ACR &= ~FLASH_ACR_LATENCY;
	FLASH->ACR |=  FLASH_ACR_LATENCY_2WS;
	RCC->CR |=  RCC_CR_MSION_Msk;
	while((RCC->CR & RCC_CR_MSION_Msk)==0);
	RCC->CFGR &= ~RCC_CFGR_SW_Msk;
	RCC->CFGR |= RCC_CFGR_SW_MSI;
	RCC->CR &= ~ RCC_CR_MSIRANGE_Msk;
	RCC->CR |=range<<RCC_CR_MSIRANGE_Pos;
	RCC->CR |=RCC_CR_MSIRGSEL;
	SystemCoreClockUpdate();
}

void pllInit(uint8_t M, uint8_t N, uint8_t R){
	uint32_t HSITrim;
	FLASH->ACR &= ~FLASH_ACR_LATENCY;
	FLASH->ACR |=  FLASH_ACR_LATENCY_2WS;
	RCC->CR |=  RCC_CR_HSION_Msk;
	while((RCC->CR & RCC_CR_HSION_Msk)==0);
	HSITrim = 16; // user-programmable trimming value that is added to HSICAL[7:0] in ICSCR.
	RCC->ICSCR &= ~RCC_ICSCR_HSITRIM;
	RCC->ICSCR |= HSITrim << RCC_ICSCR_HSITRIM_Pos;
	RCC->CR &= ~ RCC_CR_PLLON; //disabilito PLL
	while((RCC->CR & RCC_CR_PLLRDY_Msk)==RCC_CR_PLLRDY_Msk); //attendo
	RCC->PLLCFGR &= ~ RCC_PLLCFGR_PLLSRC_Msk; //
	RCC->PLLCFGR |= RCC_PLLCFGR_PLLSRC_HSI; //Seleziono HSI come sorgente PLL 
	RCC->PLLCFGR &= ~ RCC_PLLCFGR_PLLM_Msk; //M
	RCC->PLLCFGR |= M<<RCC_PLLCFGR_PLLM_Pos;
	RCC->PLLCFGR &= ~ RCC_PLLCFGR_PLLN_Msk; //N
	RCC->PLLCFGR |= N<<RCC_PLLCFGR_PLLN_Pos;
	RCC->PLLCFGR &= ~ RCC_PLLCFGR_PLLR_Msk; //R
	RCC->PLLCFGR |= R<<RCC_PLLCFGR_PLLR_Pos;
  
	RCC->CR |= RCC_CR_PLLON;
	while((RCC->CR & RCC_CR_PLLRDY_Msk)==0); //attivo PLL
	RCC->PLLCFGR |= 1<<RCC_PLLCFGR_PLLREN_Pos; //attivo uscita R
	RCC->CFGR &= ~ RCC_CFGR_SW;	
	RCC->CFGR |= RCC_CFGR_SW_PLL;
	SystemCoreClockUpdate();
	
}