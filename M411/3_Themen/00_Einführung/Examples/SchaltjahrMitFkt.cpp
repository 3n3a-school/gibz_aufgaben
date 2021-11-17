/*******************************************************************************
********************************************************************************
* Programm:   Schaltjahrproblematik
* Filename:   M403_AP_00105 (Schaltjahrproblematik).c
* Autor:      Werner Odermatt
* Version:    1.0 (Detailierte Umsetzung mit Bedingungsangaben)
* Datum:      13.03.2019
*
********************************************************************************
*
* Verwendungszweck: C-Schulung
*
* Beschreibung:
* Mit diesem Programm kann festgestellt werden, ob es sich beim eingegebenen
* Jahr um ein Schaltjahr handelt oder nicht.
*
* Precondition:
* -
*
* Postcondition:
* -
*
* Benötigte Libraries:
* "stdio.h"   
*
* Copyright (c) 2019 by W.Odermatt, CH-6340 Baar
********************************************************************************
*******************************************************************************/

//*******************************************************************************
//*  Include Files
//*******************************************************************************/
#include <stdio.h>


/*******************************************************************************
*  Globale Deklarationen und Definitionen
*******************************************************************************/
/*******************************************************************************
* Funktion:   IstSchaljahr(int jahr)
*
* Precondition:
*           Parameter jahr ist ein Jahr
* Postcondition:
*           Der zurückgegebene Wert hat folgende Bedeutung:
*           0:     Das Jahr ist kein Schaltjahr.
*           sonst: Das Jahr ist ein Schaltjahr.
* Beschreibung:
*       Diese Funktion überprüft, ob es sich bei einem Jahr um ein Schaltjahr handelt oder nicht.
*
*
* Parameter: (I: Input, O: Output, U: Update)
* Name   i/o/u  Typ            Beschreibung
* jahr   i      int            das Jahr als ganze Zahl
*
* Return : int
*        True (<> 0) sonst False (0)
* Bemerkung:
* C hat keine eingebauten booleschen Typen. Integer-Wert wird normalerweise verwendet für booleschen Wert:
* Zero wird als false intepretiert, and alle andere (non-zero) als true.
*******************************************************************************/
int IstSchaljahr(int jahr) {
    int bedingung1;   /* 1. Schaltjahrbedingung */
    int bedingung2;   /* 2. Schaltjahrbedingung */
    int bedingung3;   /* 3. Schaltjahrbedingung */

    /* Schaltjahrbestimmungsregel */
    bedingung1 = jahr % 4 == 0;   /* Ist Jahr ohne Rest durch 4 teilbar? */
    bedingung2 = jahr % 100 == 0; /* Ist Jahr ohne Rest durch 100 teilbar? */
    bedingung3 = jahr % 400 == 0; /* Ist Jahr ohne Rest durch 400 teilbar? */

    return (bedingung1 && !bedingung2) || bedingung3;
}

/*******************************************************************************
******************************* HAUPTPROGRAMM **********************************
*******************************************************************************/
int main()
{

    /* lokale Variablen */
    int jahr;            /* Eingegebes Jahr fuer Schaltjahruntersuchung */ 
    int istSchaltjahr;   /* Schaltjahrvariable */

    /* Intro */
    printf("Dieses Programm findet bei einem eingegebenen Jahr heraus, ob es");
    printf("sich um ein Schaltjahr handelt oder nicht.\n\n");

    /* Eingabe */
    printf("Bitte geben Sie das Jahr in der Form: \"1976\" ein.   Jahr = ");
    scanf_s("%d", &jahr);

    /* Schaltjahrbestimmen */
    istSchaltjahr = IstSchaljahr(jahr);

    /* Ausgabe des Resultates */
    if (istSchaltjahr)
        printf("\n%4d ist ein Schaltjahr!\n\n\n", jahr);
    else
        printf("\n%4d ist kein Schaltjahr!\n\n\n", jahr);

    return (0);
}

