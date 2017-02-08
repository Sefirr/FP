/* Ejercicio 6 - Escribe una funci�n lecturaConLimites() que reciba como par�metros dos
valores de tipo int. La funci�n pedir� al usuario que introduzca un n�mero
entero tantas veces como sea necesario hasta que el n�mero suministrado se
encuentre dentro del intervalo determinado por los datos de entrada (puede
darle pistas). La funci�n devolver� el �ltimo n�mero le�do. Escribe un programa
principal que use dicha funci�n para pedir al usuario un n�mero entre 10 y 20. */
#include <iostream>
using namespace std;

int lecturaConLimites(int min, int max) {
	int num;
	
	cout << "Introduzca un n�mero entero: ";
	cin >> num;
	while(num > min || num < max) {
		if(num < min)
		cout << "El n�mero tiene que ser mayor que " << min << "." << endl;
		else if (num > max)
		cout << "El n�mero tiene que ser menor que " << max << "." << endl;
	cout << "Introduzca un n�mero entero: ";
	cin >> num;
	}

	

	return num;
}

int main()  {

	lecturaConLimites(10,20);
	
	return 0;
}