/* Ejercicio 6 - Escribe una función lecturaConLimites() que reciba como parámetros dos
valores de tipo int. La función pedirá al usuario que introduzca un número
entero tantas veces como sea necesario hasta que el número suministrado se
encuentre dentro del intervalo determinado por los datos de entrada (puede
darle pistas). La función devolverá el último número leído. Escribe un programa
principal que use dicha función para pedir al usuario un número entre 10 y 20. */
#include <iostream>
using namespace std;

int lecturaConLimites(int min, int max) {
	int num;
	
	cout << "Introduzca un número entero: ";
	cin >> num;
	while(num > min || num < max) {
		if(num < min)
		cout << "El número tiene que ser mayor que " << min << "." << endl;
		else if (num > max)
		cout << "El número tiene que ser menor que " << max << "." << endl;
	cout << "Introduzca un número entero: ";
	cin >> num;
	}

	

	return num;
}

int main()  {

	lecturaConLimites(10,20);
	
	return 0;
}