// StructDef1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>

// Deklaration einer Struktur:
struct Koordinate
{
	int x;
	int y;
};

int main()
{
	//Definition und Initilisierung einer Strukturvariablen vom Typ struct Koordinate
	//Die Initilisierung erfolgt in der selben Reihenfolge wie die Auflistung der Felder in der Definition
	struct Koordinate p = { 10, 20 };

	printf("Structdef1 strated ...\n ");
	//Mit dem Punktoperator kann man auf einzelnes Element (Feld) einer Struktur zugreifen:
	printf("P:(%d, %d)\n", p.x, p.y);
	//Inkrement der x-Koordinate:
	p.x++;
	printf("Nach der Inkrementierung der X-Koordinate P:(%d, %d)\n", p.x, p.y);
	
	
	//struct Koordinate2
	//{
	//	int x;
	//	int y;
	//} p2 = { 10,10 };
	//printf("P2:(%d, %d)", p2.x, p2.y);

	return 0;
}