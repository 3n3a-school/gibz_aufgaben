/*******************************************************************************
* Programm:
* Filename:   Ueberlauf.cpp
*
* Autor:      Xin Cheng
* Version:    1.0
* Datum:
*
* Entwicklungsablauf(Version, Datum, Autor, Entwicklungsschritt, Zeit):
* 1.0   09.10.2018   X.Cheng Erstellung
*
********************************************************************************
*
* Verwendungszweck: C-Schulung, M411
*
* Beschreibung:
*             Diese Datei enthält die Implementation eines Beispielprogramms,
*             welches den Effekt eines Array-Überlaufs demonstriert.
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
	int arr[] = { 1, 2, 3 }; //Definition and initialisation
	//int arr2[3] = { 1,2,3,4 };

	printf("Dieses Programm demonstriert den Effekt eines Array-Überlaufs:\n");
	printf("Inhalt von arr:");
	for (int i = 0; i < 10; i++) {  //Iteration durch alle Elemente 
		printf("%d ", arr[i]);
	}

	/*
	Mithilfe des Indizierungsoperators wurde auf einen nicht
	geschützten Bereich zugegriffen, was eine Schutzverletzung darstellt. Das
	weitere Verhalten des Programms ist undefiniert.
	*******************************/
	arr[3] = 4;
//	printf("\nNun arr[3]=", arr[3]);


	return 0;
}
