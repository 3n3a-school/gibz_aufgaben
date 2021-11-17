// LB1GallikerAuf4.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//Cod von Jan Galliker


#include <stdio.h>

float bruchZuQuotient(unsigned int bruch);

int main()
{
    unsigned int bruch;
    printf("Bitte geben sie einen positiven, ganzzahligen Bruch im Format zzzzznnn an, wobei z fuer Zaehler und n fuer Nenner steht.\nDabei muss der Nenner 3 Stellen gross sein und der Zaehler kann dafuer bis zu 5 Stellen gross sein.\n");
    scanf_s("%d", &bruch);
    float result = bruchZuQuotient(bruch);
    printf("Der Quotient des Angegebenen Bruches ist: %f", result);
}

float bruchZuQuotient(unsigned int bruch)
{
    float result;
    int zaehler = bruch / 1000;
    int nenner = bruch - (zaehler * 1000);
    if (nenner == 0)
    {
        result = -1;
    }
    else
    {
        result = (float)zaehler / (float)nenner;
    }
    return result;
}