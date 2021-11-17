// FunkArraysApp.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
/*******************************************************************************
* Programm:
* Filename:   FunkArraysApp.cpp
* Autor:      Xin Cheng
* Version:    1.0
* Datum:
*
* Entwicklungsablauf(Version, Datum, Autor, Entwicklungsschritt, Zeit):
* 1.0   25.08.21   Xch  Gesamte Funktion erstellt
********************************************************************************
*
* Verwendungszweck: M411, Beispielprogramm fuer Array und Funktion
*
* Beschreibung:
*            Zeigt wie man einen Array als Parameter definiert.
*            Die Groessenangabe ist für die erste Dimension optional, und wird auch nicht überprüft, 
*            d.h. die Grösse des übergebenen Arrays muss nicht mit der Grösse in der Funktionsdefinition übereinstimmen.
* Precondition:  -
*
* Postcondition: -
*
* Benötigte Libraries:
* 
*
*******************************************************************************/

/***  Include Files: Das ist die vorkompilierte Header-Datei******************/
#include <stdio.h>


/***  Globale Deklarationen und Definitionen **********************************/
int Summe1(int a[10]);
int Summe2(int a[]);
void Modify(int a[10], int size);
void Modify_Unsafe(int a[]);

/*******************************************************************************
******************************* HAUPTPROGRAMM **********************************
*******************************************************************************/

int main()
{
	/* lokale Variablen */
	int b1[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int b2[3] = { 1, 2, 3 };
	int b3[15] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };
	

	/* Intro */
	printf("Testprogramm fuer Array und Funktion started ...\n\n");
	
	printf("Summe bilden ...\n");
	printf("Sum1(b1)=%d, Sum2(b1)=%d\n", Summe1(b1), Summe2(b1));
	printf("Sum1(b2)=%d, Sum2(b2)=%d\n", Summe1(b2), Summe2(b2));
	printf("Sum1(b3)=%d, Sum2(b3)=%d\n", Summe1(b3), Summe2(b3));
	
	printf("Das vierte Element modifizieren (Aufruf Modify)...\n");
	Modify(b1, 10);
	Modify(b2, 3);
	Modify(b3, 15);
	printf("b1[3]=%d, b2[3]=%d, b3[3]=%d \n", b1[3], b2[3], b3[3]);

	//printf("Das vierte Element modifizieren (Aufruf Modify_Unsafe)...\n");
	//Modify_Unsafe(b1);
	//Modify_Unsafe(b2);
	//Modify_Unsafe(b3);
	//printf("b1[3]=%d, b2[3]=%d, b3[3]=%d \n", b1[3], b2[3], b3[3]);

	return 0;
}

/*******************************************************************************
*************************** FUNKTIONS-DEFINITIONEN *****************************
*******************************************************************************/

/*
* Die Groessenangabe ist für die erste Dimension optional, und wird auch nicht überprüft.
*/
int Summe1(int a[10])
{
	int Summe = 0;
	for (int i = 0; i < 10; i++) { /* Summe ueber Array bilden */
		Summe += a[i];
	}
	return Summe;
}

int Summe2(int a[])
{
	int Summe = 0;
	for (int i = 0; i < 10; i++) { /* Summe ueber Array bilden */
		Summe += a[i];
	}
	return Summe;
}

/*---------------------------------------------------------------------------------
* Man übergibt besser auch die effektive Grösse des Arrays als weiteren Parameter.
**---------------------------------------------------------------------------------*/
void Modify(int a[], int size)
{
	if (size >= 4)
		a[3] = 17; /* Originalarray von Aufrufer wird verändert */
}

void Modify_Unsafe(int a[])
{
	
	a[3] = 17; /* Originalarray von Aufrufer wird verändert */
}
