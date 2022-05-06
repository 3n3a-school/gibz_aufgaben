// PersonMitDatum.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <stdio.h>

typedef struct {
    char tag;
    int monat;
    int jahr;
} Datum;

typedef struct  {
    char name[20];
    int gewicht;
    Datum geburtsdatum;
} Student;

void print(Student stud) {
    printf("Name:%s\n", stud.name);
    printf("Geburtstag: %02d.%02d.%4d\n", stud.geburtsdatum.tag, stud.geburtsdatum.monat,
        stud.geburtsdatum.jahr);
    printf("Gewicht: %d\n\n", stud.gewicht);
}
int main()
{
    Student dummkopf = { "Hans", 70, {1, 2, 1999} };
    Student me;

    print(dummkopf);
    printf("Geben Sie Ihren Name ein>");
    scanf_s("%s", me.name, sizeof(me.name));
    printf("Geben Sie Ihren Geburtsdatum ein (dd.mm.yyyy)>");
    scanf_s("%2d.%2d.%4d", &me.geburtsdatum.tag,
        &me.geburtsdatum.monat, &me.geburtsdatum.jahr);

    print(me);

}

