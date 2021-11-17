
#include <stdio.h>

#define TRUE 1
#define FALSE 0
/*******************************************************************************
* Funktion:   IstPrimzahl(zahl)
*
*
* Beschreibung:
*       Diese Funktion testet ob die eingegebene natürliche Zahl eine Primzahl ist.
*       Es retorniert TRUE(1) falls zahl eine Primzahl ist, sonst FALSE(0).
*
* Algorithmus:
*       https://de.wikipedia.org/wiki/Primzahltest
* Parameter: (I: Input, O: Output, U: Update)
* zahl: Input, die positive ganze Zahl
*
* Return:
*        TRUE(1) falls zahl eine Primzahl ist, sonst FALSE(0)
*******************************************************************************/
int IstPrimzahl(unsigned int zahl) {
	unsigned int teiler = 2;
	while (teiler * teiler < zahl && zahl % teiler > 0) {
		// teiler++;
		teiler += 1 + teiler % 2; // ungerade inkrementieren
	}
	return teiler * teiler > zahl && zahl > 1 ? TRUE : FALSE;
}

bool IstPrimzahl2(unsigned int zahl) {
	bool isPrim = zahl < 2 ? FALSE: TRUE;
	for (int teiler = 2; teiler*teiler <= zahl; teiler++) {
		if (zahl % teiler == 0) { //zahl ist durch teiler teilbar
			isPrim = FALSE;
			break;
		}
	}
	return isPrim;
}

unsigned int NextPrimzahl(unsigned int zahl) {
	if (zahl > 1)
	{
		//zahl = (zahl + 1) / 2 * 2 + 1; // Zahl auf die naechste ungerade Zahl setzen
		//printf("%u auf die naechste ungerade Zahl setzen", zahl);
		zahl += zahl % 2 + 1; // Zahl auf die naechste ungerade Zahl setzen
		//printf("-> %u\n", zahl);
		while (!IstPrimzahl(zahl))
			zahl += 2; // nur noch ungerade Zahlen testen
	}
	else
		zahl = 2; // Die Primzahlen sind: 2,3,5,7,11,...
	return(zahl);
}

/*******************************************************************************
* Funktion:   printPrimfaktoren(zahl)
*
*
* Beschreibung:
*       Diese Funktion zerlegt die übergebene Zahl in ihre Primfaktoren und
*       gibt sie auf dem Bildschirm aus.
* Algorithmus:
*       Jede ganze Zahl größer eins lässt sich als Produkt von Primzahlen darstellen, 
*       und diese Darstellung ist bis auf die Reihenfolge der Faktoren eindeutig. 
*       Man nennt sie die Primfaktoren der Zahl.
*       z.B. 882= 2 * 441
*               = 2 * 3 * 147
*               = 2 * 3 * 3 * 49
*               = 2 * 3 * 3 * 7 * 7
* Parameter: (I: Input, O: Output, U: Update)
* zahl: Input, die positive ganze Zahl
*
*******************************************************************************/

void printPrimfaktoren(unsigned int zahl) {
	int primzahl = 2;
	//printf(" %i =", zahl);
	while (zahl > 1)
	{
		if (zahl % primzahl == 0)
		{
			printf(" %u *", primzahl);
			zahl /= primzahl;
		}
		else
			primzahl = NextPrimzahl(primzahl);
	}
	printf("\b \n"); // \b: Gehe ein Zeichen zurück
}