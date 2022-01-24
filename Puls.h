/** ****************************************************************************************
* @file Puls.h
* @brief Libreria contenente tutte le funzoni utili per utilizzare e gestire i pulsanti
* 
* @author Stefano Pagano
* @date 23/11/21
* @version 1.0 23/11/21 inserite funzioni per gestire i pulsanti
*/


 /** ****************************************************************************************
* @brief Inizializzazione dei 5 pulsanti
* @author Stefano Pagano
* @date 23/11/21
* @version 1.0 23/11/21
*/
void SwInit(void);

 /** ****************************************************************************************
* @brief Inizializzazione pulsante centrale
* @author Stefano Pagano
* @date 23/11/21
* @version 1.0 23/11/21
*/
void SwCenterInit(void);

 /** ****************************************************************************************
* @brief Inizializzazione pulsante sinistro
* @author Stefano Pagano
* @date 23/11/21
* @version 1.0 23/11/21
*/
void SwLeftInit(void);

 /** ****************************************************************************************
* @brief Inizializzazione pulsante destro
* @author Stefano Pagano
* @date 23/11/21
* @version 1.0 23/11/21
*/
void SwRightInit(void);

 /** ****************************************************************************************
* @brief Inizializzazione pulsante superiore
* @author Stefano Pagano
* @date 23/11/21
* @version 1.0 23/11/21
*/
void SwUpInit(void);

 /** ****************************************************************************************
* @brief Inizializzazione pulsante inferiore
* @author Stefano Pagano
* @date 23/11/21
* @version 1.0 23/11/21
*/
void SwDownInit(void);

 /** ****************************************************************************************
* @brief Verifica pressione pulsante centrale
* @retval return=1 pulsante premuto, return=0 pulsante non premuto
* @author Stefano Pagano
* @date 23/11/21
* @version 1.0 23/11/21
*/
int SwCenterPress(void);

 /** ****************************************************************************************
* @brief Verifica pressione pulsante sinistro
* @retval return=1 pulsante premuto, return=0 pulsante non premuto
* @author Stefano Pagano
* @date 23/11/21
* @version 1.0 23/11/21
*/
int SwLeftPress(void);

 /** ****************************************************************************************
* @brief Verifica pressione pulsante destro
* @retval return=1 pulsante premuto, return=0 pulsante non premuto
* @author Stefano Pagano
* @date 23/11/21
* @version 1.0 23/11/21
*/
int SwRightPress(void);

 /** ****************************************************************************************
* @brief Verifica pressione pulsante superiore
* @retval return=1 pulsante premuto, return=0 pulsante non premuto
* @author Stefano Pagano
* @date 23/11/21
* @version 1.0 23/11/21
*/
int SwUpPress(void);

 /** ****************************************************************************************
* @brief Verifica pressione pulsante inferiore
* @retval return=1 pulsante premuto, return=0 pulsante non premuto
* @author Stefano Pagano
* @date 23/11/21
* @version 1.0 23/11/21
*/
int SwDownPress(void);

 /** ****************************************************************************************
* @brief Test dei 5 pulsanti
* @author Stefano Pagano
* @date 23/11/21
* @version 1.0 23/11/21
*/
void SwTest(void);

 /** ****************************************************************************************
* @brief *VECCHIA VERSIONE* Verifico click pulsante sinistro (click=pressione+rilascio)
* @retval return=1 pulsante premuto, return=0 pulsante non premuto
* @author Stefano Pagano
* @date 23/11/21
* @version 1.0 23/11/21
*/
int SwLeftClickOld(void);

 /** ****************************************************************************************
* @brief *VECCHIA VERSIONE* Verifico click pulsante destro (click=pressione+rilascio)
* @retval return=1 pulsante premuto, return=0 pulsante non premuto
* @author Stefano Pagano
* @date 23/11/21
* @version 1.0 23/11/21
*/
int SwRightClickOld(void);		   //click = pressione e rilascio

 /** ****************************************************************************************
* @brief Verifico click pulsante destro (click=pressione+rilascio)
* @retval return=1 pulsante premuto, return=0 pulsante non premuto
* @author Stefano Pagano
* @date 23/11/21
* @version 1.0 23/11/21
*/
int SwRightClick(void);

 /** ****************************************************************************************
* @brief Verifico click pulsante sinistro (click=pressione+rilascio)
* @retval return=1 pulsante premuto, return=0 pulsante non premuto
* @author Stefano Pagano
* @date 23/11/21
* @version 1.0 23/11/21
*/
int SwLeftClick(void);

 /** ****************************************************************************************
* @brief Verifico click pulsante sinistro (click=pressione+rilascio) con variabili globali
* @author Stefano Pagano
* @date 23/11/21
* @version 1.0 23/11/21
*/
void SwLeftClickTask(void);

 /** ****************************************************************************************
* @brief Verifico doppio click pulsante destro (click=pressione+rilascio)
* @retval return=1 pulsante premuto, return=0 pulsante non premuto
* @author Stefano Pagano
* @date 23/11/21
* @version 1.0 23/11/21
*/
int SwRight2Click(void);		 //doppio click

 /** ****************************************************************************************
* @brief *VECCHIA VERSIONE* Verifico doppio click pulsante destro (click=pressione+rilascio)
* @retval return=1 pulsante premuto, return=0 pulsante non premuto
* @author Stefano Pagano
* @date 23/11/21
* @version 1.0 23/11/21
*/
int SwRight2ClickOld(void);		 //doppio click

 /** ****************************************************************************************
* @brief Verifico pressione lunga pulsante inferiore (pressione > 3s)
* @retval return=1 pulsante premuto, return=0 pulsante non premuto
* @author Stefano Pagano
* @date 23/11/21
* @version 1.0 23/11/21
*/
int SwDownLPress(void);     //pressione lunga > 3 sec

 /** ****************************************************************************************
* @brief Lampeggio del led con tempo base 2000ms, ad ogni click velocizzo di 100ms
* @author Stefano Pagano
* @date 23/11/21
* @version 1.0 23/11/21
*/
void LedVerdeSwTask(void);

 /** ****************************************************************************************
* @brief Testo le diverse pressioni dei pulsanti
* @author Stefano Pagano
* @date 23/11/21
* @version 1.0 23/11/21
*/
void TestPressSw(void);
