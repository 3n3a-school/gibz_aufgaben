// StructDef2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
typedef unsigned int uint;  //uint ist ein Alias für unsigned int.

//Deklaration einer eigenen Datentyp: Koordinate
typedef struct
{
	uint x;
	uint y;
} Koordinate;

int main()
{
	//Definition und Initilisierung einer Strukturvariablen vom Datentyp Koordinate
	Koordinate p = { 10, 20 };

	printf("Structdef2 strated ...\n ");
	//Mit dem Punktoperator kann man auf einzelnes Element (Feld) einer Struktur zugreifen:
	printf("P:(%d, %d)\n", p.x, p.y);
	
	//Werten in die Strukturvariable schreiben 
	p.x = 30;
	p.y = 40;

	//Inkrement der x-Koordinate:
	p.x++;
	printf("Nach der Inkrementierung der X-Koordinate P:(%d, %d)\n", p.x, p.y);

	return 0;
}