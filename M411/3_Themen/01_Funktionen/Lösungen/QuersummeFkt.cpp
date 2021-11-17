
#include <stdio.h>
#include <stdlib.h>
/*******************************************************************************
*************************** FUNKTIONS-DEFINITIONEN *****************************
*******************************************************************************/


int CalcQuersumme(int zahl) {

	int summe = 0;
	int ziffer;
	while (zahl != 0) {
		ziffer = zahl % 10;  //Modulo-Operator
		summe += ziffer;
		zahl = zahl / 10;
	}

	return summe;

}


int CalcTQuersumme(int zahl) {

	int summe = zahl;
	while (abs(summe) > 9) {
		
		summe = CalcQuersumme(summe);
		//printf("CalcTQuersumme: summe=%d\n", summe);
	} 

	return summe;

}