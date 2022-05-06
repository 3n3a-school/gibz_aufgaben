// Dereferzierung.cpp : This file contains the 'main' function.Program execution beginsand ends there.
//

#include <stdio.h>

/***********************************************************************
* Über den Zeiger kann man mithilfe des Inhaltsoperators * die Variable, 
* auf die er verweist, auslesen oder ändern.
* 
*********************************************************************/

int main()
{	
	int val = 255;
	int *ptr = &val;

	// Wert ausgeben
	printf("*ptr  :  %d   val :  %d\n", *ptr, val);

	// val neuen Wert zuweisen
	*ptr = 128;   //äquivalent zu val=128

	// Wert ausgeben
	printf("*ptr  :  %d   val :  %d\n", *ptr, val);

	//Test: uninitialised pointer
	int *ptr2;
	
	//	ptr = ptr2;  //Kompilierfehler
//	printf("ptr2  :  %p  \n", *ptr2); //Kompilierfehler
//	printf("*ptr2  :  %d  \n", *ptr2); //Kompilierfehler

	return 0;
}
