/** ****************************************************************************************
* @file Puls.h
* @brief Libreria contenente tutte le funzoni utili per il clock
* 
* @author Stefano Pagano
* @date 23/11/21
* @version 1.0 23/11/21 inserite funzioni per gestire il clock
*/
//=== INCLUDES =============================================================================
#include <stdint.h>

//configurazione MSI
//0000: range 0 around 100 kHz
//0001: range 1 around 200 kHz
//0010: range 2 around 400 kHz
//0011: range 3 around 800 kHz
//0100: range 4 around 1M Hz
//0101: range 5 around 2 MHz
//0110: range 6 around 4 MHz (reset value)
//0111: range 7 around 8 MHz
//1000: range 8 around 16 MHz
//1001: range 9 around 24 MHz
//1010: range 10 around 32 MHz
//1011: range 11 around 48 MHz

 /** ****************************************************************************************
* @brief Inizializzazione MSI
* @author Stefano Pagano
* @date 23/11/21
* @version 1.0 23/11/21
*/
void MSIInit(uint8_t range);

//configurazione PLL
// fpll=fin/M*N/R  fin=4-16MHz  fpllmax=80MHz
//fin=16 MHz
//M
//0: PLLM = 1
//1: PLLM = 2
//2: PLLM = 3
//3: PLLM = 4
//4: PLLM = 5
//5: PLLM = 6
//6: PLLM = 7
//7: PLLM = 8

//N
//8: PLLN = 8
//9: PLLN = 9
//...
//85: PLLN = 85
//86: PLLN = 86

//R
//0: PLLR = 2
//1: PLLR = 4
//2: PLLR = 6
//3: PLLR = 8

 /** ****************************************************************************************
* @brief Modifico frequenza del clock
* @author Stefano Pagano
* @date 23/11/21
* @version 1.0 23/11/21
*/
void pllInit(uint8_t M, uint8_t N, uint8_t R);
