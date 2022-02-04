// AdresseCopy.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <stdio.h>
#include <string.h>

typedef struct 
{
	char surname[31];
	char name[31];
	char street[41];
	int postcode;
	char place[31];
} Address;

int main()
{
	
	// Definition und gleichzeitige Initialisierung einer Strukturvariablen
	Address person1 = { "Meier", "Hans", "Sternmatt 11a", 6789, "Luzern" };
	// Definition
	Address person2, teacher;

	printf("person1: %s, %s, %s, %d\n", person1.surname, person1.name, person1.place, person1.postcode);
	//Einzelne Felder von person1 uebernehmen:
	strcpy_s(person2.surname, person1.surname);
	strcpy_s(person2.name, person1.name);
	strcpy_s(person2.street, person1.street);
	person2.postcode = person1.postcode;
	strcpy_s(person2.place, person1.place);
	printf("person2: %s, %s, %s, %d\n", person2.surname, person2.name, person2.place, person2.postcode);

	//Bei der Kopie einer Strukturvariablen werden alle Felder der Struktur kopiert:
	teacher = person2;
	printf("teacher> %s, %s, %s, %d\n", teacher.surname, teacher.name, teacher.place, teacher.postcode);
	
	return 0;
}

