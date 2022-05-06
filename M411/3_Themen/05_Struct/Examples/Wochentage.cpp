// Wochentage.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <stdio.h>
typedef enum  {
    monday = 1, tuesday, wednesday,
    thursday, friday, saturday,
    sunday
} Day;
void printDay(Day day);

int main()
{
    Day wd = monday;
    printDay(wd);
    wd = (Day)10;
    printDay(wd);
}

void printDay(Day day) {
    switch (day) {
    case monday:
    case tuesday:
    case wednesday:
    case thursday:
    case friday:
        printf("Go to work\n");
        break;
    case saturday:
    case sunday:
        printf("Sleep well it's weekend\n");
        break;
    default:
        printf("Unknown day %d\n", day);
        
    };
}
