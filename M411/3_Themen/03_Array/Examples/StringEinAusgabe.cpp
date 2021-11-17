// StringEinAusgabe.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

/*******************************************************************************
* Programm:
* Filename:   StringEinAusgabe.cpp
* Autor:      Xin Cheng
* Version:    1.0
* Datum:
*
* Entwicklungsablauf(Version, Datum, Autor, Entwicklungsschritt, Zeit):
* 1.0   02.11.2020   X.Cheng Erstellung
*
********************************************************************************
*
* Verwendungszweck: C-Schulung, M411
*
* Beschreibung:
*             Diese Datei demonstriert die Verwendung von Bibliothekesfunktionen für die Ein- 
*             bzw. Ausgabe von Zeichenketten.
*             
* Precondition:  -
*
* Postcondition: -
*
* Benötigte Libraries:
* - stdio.h
*
*******************************************************************************/

/***  Include Files: Das ist die vorkompilierte Header-Datei******************/
#include <stdio.h>

/***  Globale Deklarationen und Definitionen **********************************/


/*******************************************************************************
******************************* HAUPTPROGRAMM **********************************
*******************************************************************************/

int main()
{
	/* lokale Variablen */
	char name[6], zeile[100], c;
	
	/* Intro */
	printf("Dieses Programm demonstriert die Verwendung von Bibliothekesfunktionen fuer die Ein- bzw. Ausgabe von Zeichenketten. ...\n");

	printf("Geben Sie den Namen ein>\n");

	//Eingabe einer Zeichenkette:
	//https://msdn.microsoft.com/en-us/library/w40768et.aspx :
	// Achtung: scanf liest nur bis zum ersten Whitespace 
	
	scanf_s("%s", name, sizeof(name)); //Buffersize=6 Falls die Anzahl Zeichen>Buffersize-1, Nichts wird eingelesen.	
	printf("Der Name ist %s\n", name);

	/*
	scanf liest nur so viele Zeichen wie sie benötigt, und lässt den Rest im Eingabepuffer.
	Sobald die Funktion auf ein Zeichen trifft welches sie nicht verarbeiten kann, bricht sie ab
	und belässt das Zeichen im Eingabepuffer. Deshalb sollte man den Eingabepuffer nach dem Aufruf
	von scanf() immer leeren.
	*/
	//fflush(stdin); // fflush() is only used with output streams	
	//while ((c = getchar()) != '\n'); 
	while (getchar() != '\n');//Puffer leeren (Lesen bis Zeilenvorschub)

	//Eine ganze Zeile einlesen mit scanf()
	printf("Geben Sie eine Zeile ein>");
	//Die folgende Formattierung legt fest, 
	//dass scanf so lange weiterlesen soll, wie es kein Neuzeile-Zeichen findet:
	scanf_s("%[^\n]", zeile, sizeof(zeile));  
	printf("Eingelesen:%s\n", zeile);
	getchar();//Puffer leeren (Lesen bis Zeilenvorschub)

	//Eine ganze Zeile einlesen mit gets()
	printf("Geben Sie eine Zeile ein>");
	gets_s(zeile, sizeof(zeile));
	//ganze Zeile ausgeben 
	puts(zeile);
	

	return 0;
}