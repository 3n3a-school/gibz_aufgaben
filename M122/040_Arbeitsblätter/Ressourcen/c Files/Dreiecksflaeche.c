/*******************************************************************************
********************************************************************************
* Programm:   Dreiecksflaeche
*
* Filename:   Dreiecksflaeche.c
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
* Dieses Programm berechnet berechnet aus drei Seiten eines beliebigen Dreiecks 
* die Fläche
* 
* Die drei Seiten sollen mit Leerschlag getrennt eingegeben werden
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
#include <math.h>   /* Funktionsbibliothek: Mathematik */

/*******************************************************************************
*  Globale Deklarationen und Definitionen
*******************************************************************************/


/*******************************************************************************
*  Funktions-Deklarationen
*******************************************************************************/

/*******************************************************************************
******************************* HAUPTPROGRAMM **********************************
*******************************************************************************/


int main(void)
{
  float SeiteA,SeiteB,SeiteC,HilfsgroesseS,Flaeche;

  do {
  
     printf("Dieses Programm berechnet berechnet aus drei Seiten eines beliebigen Dreiecks die Fläche");
     printf("\n");
     printf("Bitte geben Sie die drei Seiten a, b, c");
     printf("\n");
     printf("durch ein Leerschlag getrennt ein");
     printf("\n");
       
     scanf("%f %f %f" ,&SeiteA,&SeiteB,&SeiteC);
     
          
  } while (!((SeiteA > 0) && (SeiteB > 0) && (SeiteC > 0)));
  
  HilfsgroesseS = (SeiteA + SeiteB + SeiteC) / 2;
  Flaeche = sqrt(HilfsgroesseS * (HilfsgroesseS - SeiteA) * (HilfsgroesseS - SeiteB) * (HilfsgroesseS - SeiteC));  
  
 
  printf("\n");  
  printf("Die Fläche beträgt: \n"
        "   A = %4g mm^2\n"
        "   a = %4g \n"
        "   b = %4g \n"
        "   c = %4g \n",Flaeche,SeiteA,SeiteB,SeiteC);
  
  
  system("PAUSE");	
  return 0;
}
