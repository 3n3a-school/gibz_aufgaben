/*******************************************************************************
********************************************************************************
* Programm:   Verkehrszaehlung
*
* Filename:   Verkehrszaehlung.c
*
* Autor:      Roger M�ller
*
* Version:    1.0
*
* Datum:      20.09.2010
*
* Entwicklungsablauf(Version, Datum, Autor, Entwicklungsschritt):
* 1.0   20.09.2010   rm   Gesamtes Programm erstellt
*
********************************************************************************
*
* Verwendungszweck: C-Schulung
*
*
* Beschreibung:
* Es wird eine Verkehrsz�hlung durchgef�hrt:
* Annhand der Eingabe kann zwischen Motorrad (M), PKW(P), LKW(L) und Bus (B) 
* unterschieden werden
* Ausserdem werden schweizer(C)- von ausl�ndische(A) Fahrzeugen unterschieden
* Bei Ausl�ndischen Fahrzeug ist zudem die Kategorie Gross(G) und Klein(K) relevant
* 
* Precondition:
* -
*
* Postcondition:
* -
*
* Ben�tigte Libraries:
*
*
* Folgende Funktionen werden erzeugt:
* -
*
* Copyright (c) 2010 by R. M�ller
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

int main(void)
{
  // lokale Variablen
 
  char Fahrzeug;
  int Motorrad = 0;
  int PW = 0;
  int LW = 0;
  int Bus = 0;
  int Fahrzeugunbekannt = 0;
  int Auslaendischgross = 0;
  int Verkehrszaehlung_aktiv = 1;
  float AuslaendischGrossprozent;
    
  do { //Solange Z�hlung l�uft
        printf("\n");
        printf ("Bitte geben Sie das naechste Fahrzeug ein: M=Motorrad, P=PW, L=LW,B=Bus");      
        scanf("%c",&Fahrzeug); 
        fflush(stdin);             //L�schen des Standartinputs

        //Zuteilung der Fahrzeuge
        switch (Fahrzeug) {
           case 'M':    Motorrad++;
                        break;
           case 'P':    PW++;
                        break;
           case 'L':    LW++;
                        break;
           case 'B':    Bus++;
                        break;
           default:     Fahrzeugunbekannt++;
        }
        
        printf ("\nHandelt es sich um ein schweizeriSches (C) oder um ein ausl�ndisches Fahrzeug(A)?");  
        scanf("%c",&Fahrzeug);
        fflush(stdin);
        if (Fahrzeug == 'A') {         //Ausl�ndisches Fahrzeug? Standart:CH
           printf ("\nHandelt es sich um ein Fahrzeug der grossen Kategorie(G) oder Klein (K)");
           scanf("%c",&Fahrzeug);
           fflush(stdin);
           if (Fahrzeug == 'G') {        //Fahrzeug gross oder klein? Standart:klein
              Auslaendischgross++;
           }
        }
        
        
        printf ("Weitere Fahrzeuge vorhanden?J=Ja, N=Nein");  
        scanf("%c",&Fahrzeug);
        fflush(stdin);
        if 	(Fahrzeug=='N') {
            Verkehrszaehlung_aktiv =0;
        }
  
  } while (Verkehrszaehlung_aktiv > 0);
  
  printf("Folgende Fahrzeuge wurden gez�hlt: Motorrad=%d, PW=%d, LW=%d, Bus=%d, Unbekannte Fahrzeuge=%d",Motorrad,PW,LW,Bus,Fahrzeugunbekannt); 
  AuslaendischGrossprozent = 100 * Auslaendischgross / (Motorrad+PW+LW+Bus+Fahrzeugunbekannt);    //Prozentuale berechnung
  printf("\nDavon waren %6.2f%% auslaendische Fahrzeuge der grossen Kategorie",AuslaendischGrossprozent); 
 
  system("PAUSE");	
  return 0;
}
