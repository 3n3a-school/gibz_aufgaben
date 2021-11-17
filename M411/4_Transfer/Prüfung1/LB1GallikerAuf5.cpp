// LB1GallikerAuf5.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//Code von Jan Galliker


#include <stdio.h>

void decimalToBinary(unsigned int decimalNumber);

int main()
{
	unsigned int decimalNumber;
	printf("Bitte geben sie eine Positive ganze Zahl ein, welche sie zu einer binaeren Zahl umgewandelt haben moechten:\n");
	scanf_s("%d", &decimalNumber);
	printf("Die binaere Zahl von %d ist: ", decimalNumber);
	decimalToBinary(decimalNumber);
}

void decimalToBinary(unsigned int decimalNumber)
{
	int binaryNumber = decimalNumber % 2;
	decimalNumber = decimalNumber / 2;
	if (decimalNumber != 0)
	{
		decimalToBinary(decimalNumber);
	}
	printf("%d", binaryNumber);
}