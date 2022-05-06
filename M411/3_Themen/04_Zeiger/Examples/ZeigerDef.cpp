#include <stdio.h>


int main()
{
	int *ptr;        //Definition: ptr ist ein Zeiger, welcher die Adresse einer int-Variablen speichert.
	int val = 255;
	ptr = &val;      //pt speichert die Adresse von val.

	//Die Adresse von val kann mit dem Adressoperator & ermittelt werden.
	//Das Formatierungszeichen %p ist für eine Adresse bestimmt.
	printf("Adresse von val: %p\n", &val); 

	//Die Adresse von val wurde in ptr gespeichert
	printf("Wert von ptr : %p\n", ptr);

	//Teil2:
	int* ptr1, ptr2; //ptr1 ist ein Zeiger, ptr2 ist ein int.
	ptr2 = val;
	ptr1 = &ptr2;
	printf("Wert von ptr1 und Adresse von ptr2 : %p, %p\n", ptr1, &ptr2);

}