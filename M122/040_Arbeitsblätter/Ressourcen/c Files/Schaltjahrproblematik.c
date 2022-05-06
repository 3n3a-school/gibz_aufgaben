/*******************************************************************************
********************************************************************************
* Programm:   Schaltjahrproblematik
*
* Filename:   Schaltjahrproblematik.c
*
* Autor:      Roger Müller
*
* Version:    1.0
*
* Datum:      15.11.2010
*
* Entwicklungsablauf(Version, Datum, Autor, Entwicklungsschritt):
* 1.0   15.11.2010   rm   Gesamtes Programm erstellt
*
********************************************************************************
*
* Verwendungszweck: C-Schulung
*
*
* Beschreibung:
* Dieses Programm berechnet berechnet aus der eingegebenen Jahreszahl, ob 
* es sich um ein Schaltjahr handelt oder nicht.
* 
* 
* Precondition:
* -
*
* Postcondition:
* -
*
* Benötigte Libraries:
*
*
* Folgende Funktionen werden erzeugt:
* -
*
* Copyright (c) 2010 by R. Müller
********************************************************************************
*******************************************************************************/
/*******************************************************************************
*  Include Files
*******************************************************************************/
#include <stdlib.h> /* Funktionsbibliothek: Hilfsfunktionen */
#include <stdio.h>  /* Funktionsbibliothek: Standard Ein- Ausgabe */


/*******************************************************************************
*  Globale Deklarationen und Definitionen
*******************************************************************************/


/*******************************************************************************
*  Funktions-Deklarationen
*******************************************************************************/

/*******************************************************************************
******************************* HAUPTPROGRAMM **********************************
*******************************************************************************/


int main(void){
  int tstJahr, R4,R100,R400,Schaltjahr;

  printf("Dieses Programm berechnet berechnet aus der eingegebenen Jahreszahl, ob");
  printf("\n");
  printf("es sich um ein Schaltjahr handelt oder nicht.");
 
  do {
    printf("\n");
    printf("Bitte geben Sie das zu testende Jahr ein:");
    printf("\n");
      
    scanf("%d" ,&tstJahr);
  } while (tstJahr <= 0);
  
  R4  = tstJahr % 4;
  R100 =tstJahr % 100;
  R400 =tstJahr % 400;
  
  if (R400 == 0) {
    Schaltjahr = 1;
  }
  else {
    if ((R4==0) && (R100!=0)) {
      Schaltjahr =1;
    }
    else {
      Schaltjahr =0;
    }
  }
     
  if (Schaltjahr ==1) {
     printf("\n Bei dem eingegebenen Jahr handelt es sich um ein Schaltjahr!");
  }
  else {
     printf("\n Bei dem eingegebenen Jahr handelt es sich um kein Schaltjahr!");
  }
  
  system("PAUSE");	
  return 0;
}

