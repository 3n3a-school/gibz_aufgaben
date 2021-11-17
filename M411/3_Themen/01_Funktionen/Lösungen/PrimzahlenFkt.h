#pragma once
/***  Funktions-Deklarationen *************************************************/

/*******************************************************************************
* Funktion:   IstPrimzahl(zahl)
*
*
* Beschreibung:
*       Diese Funktion testet ob die eingegebene natürliche Zahl Zahl eine Primzahl ist.
*       Es retorniert TRUE(1) falls zahl eine Primzahl ist, sonst FALSE(0).
*
* 
*
* Parameter: (I: Input, O: Output, U: Update)
* zahl: Input, die positive ganze Zahl
* 
* Return:
*        TRUE(1) falls zahl eine Primzahl ist, sonst FALSE(0)
*******************************************************************************/
int IstPrimzahl(unsigned int zahl);

/*******************************************************************************
* Funktion:   NextPrimzahl(zahl)
*
*
* Beschreibung:
*       Diese Funktion gibt die naechste auf 'zahl' folgende Primzahl zurueck.
*
*
*
* Parameter: (I: Input, O: Output, U: Update)
* zahl: Input, die positive ganze Zahl
*
* Return:
*        die naechste auf 'zahl' folgende Primzahl
*******************************************************************************/
unsigned int NextPrimzahl(unsigned int zahl);

/*******************************************************************************
* Funktion:   printPrimfaktoren(zahl)
*
*
* Beschreibung:
*       Diese Funktion zerlegt die übergebene Zahl in ihre Primfaktoren und 
*       gibt sie auf dem Bildschirm aus.
* 
* Parameter: (I: Input, O: Output, U: Update)
* zahl: Input, die positive ganze Zahl
*
* Return:
*******************************************************************************/
void printPrimfaktoren(unsigned int zahl);
bool IstPrimzahl2(unsigned int zahl);
