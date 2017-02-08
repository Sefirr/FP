/* Escribe un programa que a través de la consola consiga dos números enteros
positivos y muestre su producto usando sólo sumas. */

#include <iostream>
using namespace std;

int main()
{
	int num1, num2, resultado = 0;

		cout << "Introduzca un número(positivo): ";
		cin >> num1;
		cout << endl << "Introduzca otra número(positivo): ";
		cin >> num2;
		cout << "¿Cuántes veces quieres multiplicarlo? ";
		
		if(num1 > 0 && num2 > 0){
		for(int i = 1;i <= num2; i++)
		resultado = resultado + num1;
		
		cout << "Resultado = " << num1 << " * " << num2 << " = " << resultado;
		}
		else
		cout << "El número tiene que ser positivo";
	
	return 0;

}