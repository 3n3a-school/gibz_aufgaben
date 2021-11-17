// Sinus.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
/*******************************************************************************
* Programm:
* Filename:   Sinus.cpp
* Autor:      Werner Odermatt
* Version:    3.0
* Datum:
*
* Entwicklungsablauf(Version, Datum, Autor, Entwicklungsschritt, Zeit):
* 1.0   06.11.05   WOd  Gesamte Funktion erstellt
* 2.0   13.06.16   WOd  Ueberarbeitung der Funktion
* 3.0   15.09.20   XCH  Ueberarbeitung der Funktion 
********************************************************************************
*
* Verwendungszweck: C-Schulung, M411
*
* Beschreibung:
*            Zeigt wie mittels der Reihenentwicklung eine Sinusfunktion nachgebildet werden
*            kann. Als Grundlage dient die folgende Reihenentwicklung:
*            sin(x) = x/1 - x^3/3! + x^5/5! - ....
*
* Precondition:  -
*
* Postcondition: -
*
* Benötigte Libraries:
* - stdio.h
*
*******************************************************************************/

/***  Include Files: Das ist die vorkompilierte Header-Datei******************/
#include <stdio.h>
#include <math.h>

/***  Globale Deklarationen und Definitionen **********************************/
#define ANZ_GLIEDER  12     // Bestimmt die Gliederanzahl der Reihenentwicklung
#define PI           3.1416 // PI-Konstante

double Sin1(float angle);
double Sin2(float angle);
double Sin_Rekursiv(float angle, unsigned int anzGlieder);
double CalcFaculty(unsigned int value);

/*******************************************************************************
******************************* HAUPTPROGRAMM **********************************
*******************************************************************************/

int main()
{
	/* lokale Variablen */
	float angleValue;

	/* Intro */
	printf("SINUS VALUE CALCULATION\n\n");
	printf("Program calculates the sine by a series expansion!\n");
	printf("Number of members of the series = %d\n\n\n", ANZ_GLIEDER);


	/* Eingabe */
	printf("Please enter the angle [DEG]. Angle = ");
	scanf_s("%f", &angleValue);
	puts("\n");

	// Output of the sine value by function call Sin1
	printf("Using Sin1()> The sine of angle: %.2f DEG is %f\n\n\n",
		angleValue, Sin1(angleValue));

	printf("Using Sin2()> The sine of angle: %.2f DEG is %f\n\n\n",
		angleValue, Sin2(angleValue));

	//Rekursion:
	angleValue = angleValue * PI / 180;   //Umrechnung von DEG zu RAD
	printf("Using recursion: Sin(%.6f)= %f\n\n\n",
		angleValue, Sin_Rekursiv(angleValue, ANZ_GLIEDER));
	return 0;
}

/*******************************************************************************
*************************** FUNKTIONS-DEFINITIONEN *****************************
*******************************************************************************/

/*******************************************************************************
* Funktion:   double Sin(float angle)
*
* Beschreibung:
*       Berechnet den Sinuswert eines uebergebenen Radialwinkels.
*
* Precondition:  angle ist die Winkel in Einheit im Grad (DEG)
*
* Postcondition: Der Sinuswert wird zurückgegebene.
*
* Parameter: (I: Input, O: Output, U: Update)
* - angle   I   float   angle in DEG
*
* Return : double
*        Der berechnete Sinuswert
*******************************************************************************/

double Sin1(float angle) {  

	int count, exponent, sign;
	double denominator;  //Nenner
	double numerator;    //Zaehler
	double sinusResult=0;

	// Start values
	angle = angle * PI / 180;   //Umrechnung von DEG zu RAD
	
	for (count = 1; count <= ANZ_GLIEDER; count++) {
		exponent = count * 2 - 1;
		sign = (count % 2 == 1) ? 1 : -1;                //ungerade positiv
		numerator = pow(angle, exponent);
		denominator = CalcFaculty(exponent);		
		sinusResult += sign * numerator / denominator;
		//printf("numerator=%f denominator=%f\n", numerator, denominator);
	}

	return (sinusResult);
}

double Sin2(float angle) {

	int count, power;
	double denominator;  //Nenner
	double numerator;    //Zaehler
	double sinusResult;

	// Start values
	angle = angle * PI / 180;   //Umrechnung von DEG zu RAD
	numerator = angle;
	denominator = 1.0;
	sinusResult = angle;

	for (count = 1; count < ANZ_GLIEDER; count++) {
		numerator = -numerator * angle * angle;
		power = count*2 + 1;
		denominator *= (power - 1) * power;
		sinusResult += numerator / denominator;
		//printf("numerator=%f denominator=%f\n", numerator, denominator);
	}

	return (sinusResult);
}

/*******************************************************************************
* Funktion:   double Sin_Rekursiv(float angle)
*
* Beschreibung:
*       Berechnet den Sinuswert eines uebergebenen Radialwinkels nach dem rekursiven Ansatz.
*
* Precondition:  angle ist die Winkel in Einheit im Grad (DEG)
*                anzGlieder >= 1
* Postcondition: Der Sinuswert wird zurückgegebene.
*
* Parameter: (I: Input, O: Output, U: Update)
* - angle   I   float   angle in RAD
* - anzGlieder  I unsigned int   Anzahl Glieder
* Return : double
*        Der berechnete Sinuswert
*******************************************************************************/

double Sin_Rekursiv(float angle, unsigned int anzGlieder) {
	unsigned int exponent = anzGlieder * 2 - 1;
	int sign = (anzGlieder % 2 == 1) ? 1 : -1;                //ungerade 
	double term = sign * pow(angle, exponent) / CalcFaculty(exponent);
	//printf("Exponent =%d anzGlieder=%i sign=%d pow=%lf fak=%lf term= %lf\n", exponent, anzGlieder, 
	//	sign, pow(angle, exponent), CalcFaculty(exponent), term);
	if (anzGlieder > 1) {
		return term + Sin_Rekursiv(angle, anzGlieder - 1);
	}
	else
		return term;

}

double CalcFaculty(unsigned int value) // calculate faculty
{
	double faculty = 1;
	while (value > 1)
	{
		faculty *= value;
		value--;
	}
	return faculty;
}