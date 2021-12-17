// Id3.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct Id3_tag {
	char titel[30];
	char kuenstler[30];
	char album[30];
	short jahr;
	char kommentar[30];
	char genere[30];
} Id3_t;

void output(Id3_t song) {
	printf("\n\nDer Song den Sie eingaben:\n");
	printf("Titel     :  %s\n", song.titel);
	printf("Künstler  :  %s\n", song.kuenstler);
	printf("Album     :  %s\n", song.album);
	printf("Jahr      :  %hd\n", song.jahr);
	printf("Kommentar :  %s\n", song.kommentar);
	printf("Genere    :  %s\n", song.genere);
}

int main(void) {
	Id3_t data1 = { "Kings and Queens",
					"30 Seconds to Mars",
					"This Is War",
					2009,
					"Komponist: Jared Leto",
					"Alternative"
				};

	Id3_t data2 = { "Kings and Queens",
					"30 Seconds to Mars"
	};
	// Daten der Struktur ausgeben
	output(data1);

	output(data2);
	return EXIT_SUCCESS;
}