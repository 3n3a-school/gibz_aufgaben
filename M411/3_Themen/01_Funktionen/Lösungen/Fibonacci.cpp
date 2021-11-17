// Fibonacci.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
#include <stdio.h>

unsigned long CalcFibonacci_Rekursion(unsigned long n);
unsigned long CalcFibonacci_Iteration(unsigned long n);

unsigned long CalcFibonacci_Rekursion2(unsigned long n);

int main()
{
	printf("Dieses Programm gibt die ersten 11 Fibonacci-Zahl aus\n\n");
	printf("Mit Rekursion:\n");
	for (int i = 0; i <= 10; i++) {
		printf("%lu,", CalcFibonacci_Rekursion(i));
	}
	printf("\nMit Iteration:\n");
	for (int i = 0; i <= 10; i++) {
		printf("%lu,", CalcFibonacci_Iteration(i));
	}

	return 0;
}

unsigned long CalcFibonacci_Rekursion(unsigned long n) {
	unsigned long fibo = n == 0 ? 0 : 1;
	if (n >= 2)
	{
		fibo = CalcFibonacci_Rekursion(n - 1) + CalcFibonacci_Rekursion(n - 2);
	}

	return fibo;
}

unsigned long CalcFibonacci_Rekursion2(unsigned long n) {
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else	
		return CalcFibonacci_Rekursion(n - 1) + CalcFibonacci_Rekursion(n - 2);
}

unsigned long CalcFibonacci_Iteration(unsigned long n) {
	unsigned long fn = n == 0 ? 0 : 1;
	int f0 = 0, f1 = 1;

	for (int i = 2; i <= n; i++) {
		fn = f0 + f1;
		f0 = f1;
		f1 = fn;
	}


	return fn;
}