/*******************************************************************************
********************************************************************************
* Programm:   MWST
*
* Filename:   MWST.c
*
* Autor:      Roger Müller
*
* Version:    1.0
*
* Datum:      08.11.2010
*
* Entwicklungsablauf(Version, Datum, Autor, Entwicklungsschritt):
* 1.0   08.11.2010   rm   Gesamtes Programm erstellt
*
********************************************************************************
*
* Verwendungszweck: C-Schulung
*
*
* Beschreibung:
* Das Programm berechnet ihnen die MWST aufgrund der eingegeben MWST Art, 
* sowie das Gesamtergebnis der drei MWST Arten
* 
* MWST 1: Güter des täglichen Bedarfs 2.4%
* MWST 2: Beherbergungsleistungen 3.6%
* MWST 3: Normaler Steuersatz 7.6%
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
//#define cMWST1 0.024
#define cMWST2 0.036
#define cMWST3 0.076

const float cMWST1 = 0.024;

/*******************************************************************************
*  Funktions-Deklarationen
*******************************************************************************/

/*******************************************************************************
******************************* HAUPTPROGRAMM **********************************
*******************************************************************************/


int main(void)
{
  float SummeMWST1 =0.0;
  float SummeMWST2 =0.0;
  float SummeMWST3 =0.0;  

  float Nettopreis;
  int MWSTArt;
  
  printf("Das Programm berechnet ihnen die MWST aufgrund der eingegeben MWST Art, sowie das Gesamtergebnis der drei MWST Arten");
  printf("\n");
  printf("MWST 1: Güter des täglichen Bedarfs 2.4%");
  printf("\n");
  printf("MWST 2: Beherbergungsleistungen 3.6%");
  printf("\n");
  printf("MWST 3: Normaler Steuersatz 7.6%");
  
  do {
     printf("\n");
     printf("Bitte geben Sie den Nettopreis ein: ");
     scanf("%f" ,&Nettopreis);
     printf("Bitte geben Sie die Mehrwertsteuerart ein: ");
     scanf("%d" ,&MWSTArt);
          
  } while ((MWSTArt < 1) || (MWSTArt > 3));
  
    
  
  while (Nettopreis > 0.0) {
        
        if (MWSTArt == 1) {
                    SummeMWST1 = SummeMWST1 + (cMWST1 * Nettopreis);                  
        }
        else {
             if (MWSTArt == 2) {
                    SummeMWST2 = SummeMWST2 + (cMWST2 * Nettopreis);                  
             }
             else {
                  SummeMWST3 = SummeMWST3 + (cMWST3 * Nettopreis);                  
             }
        }
        do {
           printf("\n");
           printf("Bitte geben Sie den Nettopreis ein: ");
           scanf("%f" ,&Nettopreis);
           printf("Bitte geben Sie die Mehrwertsteuerart ein: ");
           scanf("%d" ,&MWSTArt);
        } while ((MWSTArt < 1) || (MWSTArt > 3));
  }
  
  printf("\n");  
  printf("MWST für die MWST Art 1 (2.4%):  %4.2f", SummeMWST1);
  printf("\n");
  printf("MWST für die MWST Art 2 (3.6%):  %4.2f", SummeMWST2);
  printf("\n");
  printf("MWST für die MWST Art 3 (7.6%):  %4.2f", SummeMWST3);
  printf("\n");
  
  printf("MWST für alle MWST Arten:  %4.2f Fr", SummeMWST1 + SummeMWST2 + SummeMWST3);
  printf("\n");
  
  
  system("PAUSE");	
  return 0;
}
