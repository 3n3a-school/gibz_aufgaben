// EinAusgabe1.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <stdio.h>

int main()
{
    int zahl1 = 0, zahl2 = 0;

    printf("Geben Sie die erste Zahl ein: ");
    //scanf_s("%3d", &zahl1);
    scanf_s("%d", &zahl1);

    //fflush(stdin);

    printf("Geben Sie nun die zweite Zahl ein: ");
    scanf_s("%d", &zahl2);

    printf("\nDie eingegebenen Zahlen waren:\n");
    printf("zahl1: %d\nzahl2: %d\n", zahl1, zahl2);

    int val1, val2;
    printf("Enter two numbers:\n");
    scanf_s("%d %d", &val1, &val2);
    printf("sum = %d", val1 + val2);

    return 0;
}

