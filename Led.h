/** ****************************************************************************************
* @file Led.h
* @brief Libreria contenente tutte le funzoni utili per utilizzare e gestire i led
* 
* @author Stefano Pagano
* @date 23/11/21
* @version 1.0 23/11/21 inserite funzioni per gestire i led
*/

 /** ****************************************************************************************
* @brief Inizializzazione dei 2 led
* @author Stefano Pagano
* @date 23/11/21
* @version 1.0 23/11/21
*/
void LedInit(void);

 /** ****************************************************************************************
* @brief Inizializzazione del led rosso
* @author Stefano Pagano
* @date 23/11/21
* @version 1.0 23/11/21
*/
void LedRossoInit(void);

 /** ****************************************************************************************
* @brief Inizializzazione del led verde
* @author Stefano Pagano
* @date 23/11/21
* @version 1.0 23/11/21
*/
void LedVerdeInit(void);

 /** ****************************************************************************************
* @brief Accensione led rosso
* @author Stefano Pagano
* @date 23/11/21
* @version 1.0 23/11/21
*/
void LedRossoOn(void);

 /** ****************************************************************************************
* @brief Spegnimento led rosso
* @author Stefano Pagano
* @date 23/11/21
* @version 1.0 23/11/21
*/
void LedRossoOff(void);

 /** ****************************************************************************************
* @brief Inversione stato led rosso
* @author Stefano Pagano
* @date 23/11/21
* @version 1.0 23/11/21
*/
void LedRossoToggle(void);

 /** ****************************************************************************************
* @brief Accensione led verde
* @author Stefano Pagano
* @date 23/11/21
* @version 1.0 23/11/21
*/
void LedVerdeOn(void);

 /** ****************************************************************************************
* @brief Spegnimento led verde
* @author Stefano Pagano
* @date 23/11/21
* @version 1.0 23/11/21
*/
void LedVerdeOff(void);

 /** ****************************************************************************************
* @brief Inversione stato led verde
* @author Stefano Pagano
* @date 23/11/21
* @version 1.0 23/11/21
*/
void LedVerdeToggle(void);

 /** ****************************************************************************************
* @brief Lampeggio led rosso con parametri
* @param  ritardo=distanza tra lampeggi(in ms), ncicli=num lampeggi
* @author Stefano Pagano
* @date 23/11/21
* @version 1.0 23/11/21
*/
void LedRossoBlink(int ritardo,int ncicli);

 /** ****************************************************************************************
* @brief Lampeggio led verde con parametri
* @param  ritardo=distanza tra lampeggi(in ms), ncicli=num lampeggi
* @author Stefano Pagano
* @date 23/11/21
* @version 1.0 23/11/21
*/
void LedVerdeBlink(int ritardo,int ncicli);

 /** ****************************************************************************************
* @brief Testo i due led (10 lampeggi ogni 100ms)
* @author Stefano Pagano
* @date 23/11/21
* @version 1.0 23/11/21
*/
void LedTest(void);

 /** ****************************************************************************************
* @brief Lampeggio led verde con parametri
* @param  Ton=tempo led accesso(ms), T=tempo totale(acceso+spento)
* @author Stefano Pagano
* @date 23/11/21
* @version 1.0 23/11/21
*/
void LedRossoTask(int Ton,int T);

 /** ****************************************************************************************
* @brief Lampeggio led verde con parametri
* @param  Ton=tempo led accesso(ms), T=tempo totale(acceso+spento)
* @author Stefano Pagano
* @date 23/11/21
* @version 1.0 23/11/21
*/
void LedVerdeTask(int Ton,int T);

 /** ****************************************************************************************
* @brief Lampeggio led verde con parametro
* @param  startTime=delay per il lampeggio del led verde
* @author Stefano Pagano
* @date 23/11/21
* @version 1.0 23/11/21
*/
void LedVerdeBlinkTask(int startTime);

 /** ****************************************************************************************
* @brief Lampeggio led verde con parametro
* @param  startTime=delay per il lampeggio del led rosso
* @author Stefano Pagano
* @date 23/11/21
* @version 1.0 23/11/21
*/
void LedRossoBlinkTask(int startTime);
