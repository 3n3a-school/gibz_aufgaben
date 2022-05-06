// Zeichenkette_Zeiger.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <stdio.h>
#include <string.h>

#define MAX 80

int main()
{
	char txt1[MAX], txt2[MAX];

    //Eingabe txt1:
	printf("Bitte eine Zeichenkette eingeben>");
	scanf_s("%s", txt1, sizeof(txt1));

	//Kopieren von txt1 nach txt2 mti Zuweisung: Kompilierfehler
	//txt2 = txt1;
	
	//Kopieren von txt1 nach txt2 mit strcpy:
	strcpy_s(txt2, sizeof(txt2), txt1);
	printf("Kopieren mit strlen: txt1:%s, txt2:%s\n", txt1, txt2);
	
	//Kopieren von txt1 nach txt2, Zeichen fuer Zeichen:
	char *p1 = txt1, *p2 = txt2;
	do {
		*p2 = *p1;
		p1++;
		p2++;
	} while (*p1 != '\0');
	*p2 = *p1;  //Das letzte Null kopieren
	printf("Zeichen fuer Zeichen Kopieren: txt1:%s, txt2:%s", txt1, txt2);

}

