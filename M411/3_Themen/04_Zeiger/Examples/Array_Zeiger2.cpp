// Array_Zeiger2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "stdio.h"

#define MAX 10

int main()
{
	int list[MAX] = { 12, 34, 56, 78, 90 };
	// Der Name eines Arrays stellt immer eine Adresse zum ersten Element dar.
	// iptr zeigt auf das erste Element von list.
	int *iptr = list; //äquivalent: iptr=&list[0]

	printf("list:%p &list[0]:%p iptr:%p\n", list, &list[0], iptr);
	printf("list[0] = %d oder *iptr=%d\n\n", list[0], *iptr);  //*iptr ist äquivalent zu list[0] 

	
	iptr++;            //iptr++ zeigt auf das nächste Element
	*iptr = 99;        //äquivalent:list[1]=99;
	*(iptr++) = 66;    //äquivalent:list[2]=66;
	printf("list[2] = %d oder *iptr=%d\n\n", list[2], *iptr);

	// Ausgabe:
	printf("Das gesamte Array:\n");
	iptr = list;
	for (int i = 0; i < MAX; i++) {
		printf("list[%d] = %d oder %d\n", i, list[i], *(iptr+i));
	}


}