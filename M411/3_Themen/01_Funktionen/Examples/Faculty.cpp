/*******************************************************************************
* Programm : Fakultät Berechnen
* Filename : Faculty.cpp
*             
* Autor : Xin Cheng
* Version : 1.0
* Datum :
*
* Entwicklungsablauf(Version, Datum, Autor, Entwicklungsschritt, Zeit) :
* 1.0   19.09.2018   X.Cheng Erstellung
*
********************************************************************************
*
* Verwendungszweck : C-Schulung, M411
*
* Beschreibung :
* This function calculates the faculty of a given number.
*
* Precondition : -
*
* Postcondition : -
*
* Benötigte Libraries :
* -stdio.h
*
******************************************************************************* /

/***  Include Files: Das ist die vorkompilierte Header-Datei******************/
#include <stdio.h>

/***  Globale Deklarationen und Definitionen **********************************/
/***  Funktions-Deklarationen *************************************************/
int CalculateFaculty(unsigned int number);


/*******************************************************************************
******************************* HAUPTPROGRAMM **********************************
*******************************************************************************/

int main()
{
	int number = 4; //
	printf("The faculty of the number %d is %d.", number, CalculateFaculty(number));
	return 0;
}

/*******************************************************************************
*************************** FUNKTIONS-DEFINITIONEN *****************************
*******************************************************************************/

/*******************************************************************************
* Funktion:  CalculateFaculty
* Source: 	 CalculateFaculty.c
*
* Autor:
* Version:   1.0
* Datum:
*
* Entwicklungsablauf(Version, Datum, Autor, Entwicklungsschritt):
* 1.0
********************************************************************************
*
* Verwendungszweck: C-Schulung, M411
*
* Beschreibung:
*    This function calculates the faculty of a given number.
*
*
* Parameter: (I: Input, O: Output, U: Update)
*
* int value I
* Copyright (c) 201x by
*******************************************************************************/

int CalculateFaculty(unsigned int value) // calculate faculty
{
	int faculty = 1;
	while (value > 1)
	{
		faculty *= value;
		value--;
	}
	return faculty;
}

