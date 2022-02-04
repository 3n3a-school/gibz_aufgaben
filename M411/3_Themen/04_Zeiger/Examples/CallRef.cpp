// CallRef.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <stdio.h>

void Modify(int* p, int c)
{
    c += 2;
    *p = *p + c; /* Veraendert Wert, auf den p zeigt */
}

int main()
{
    int x = 3, y = 7;

    printf("Vor dem Aufruf: x=%d, y=%d\n", x, y);
    Modify(&x, y);   /* x wird veraendert, y nicht */
    printf("Nach dem Aufruf: x=%d, y=%d\n", x, y);

    return 0;
}
