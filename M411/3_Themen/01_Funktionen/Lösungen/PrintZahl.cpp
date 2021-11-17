// PrintZahl.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <stdio.h>

void PrintZahl(unsigned int zahl);
int main()
{
    unsigned int zahl;

    printf("PrintZahl started ...\n");
    printf("Geben Sie eine positive Ganzzahl ein>\n");
    scanf_s("%d", &zahl);

    printf("Die Zahl:");
    PrintZahl(zahl);
}

/*******************************************************************************
* Funktion:   PrintZahl()
*
*
* Beschreibung:
*       Diese Funktion gibt die einzelne Ziffer in der richtigen Reihenfolge aus.
*
* 
* Parameter: (I: Input, O: Output, U: Update)
* Name   i/o/u  Typ            Beschreibung
* zahl   i      int            die ganze Zahl
*
* Return:  
*******************************************************************************/
void PrintZahl(unsigned int zahl) {
    if (zahl > 9) {
        PrintZahl(zahl / 10);
    }
    printf("%1d", zahl % 10);   //Einerziffer ausgeben

}

