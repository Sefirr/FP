/* Escribe un programa que a trav�s de la consola consiga dos n�meros enteros
positivos y muestre su producto usando s�lo sumas. */

#include <iostream>
using namespace std;

int main()
{
	int num1, num2, resultado = 0;

		cout << "Introduzca un n�mero(positivo): ";
		cin >> num1;
		cout << endl << "Introduzca otra n�mero(positivo): ";
		cin >> num2;
		cout << "�Cu�ntes veces quieres multiplicarlo? ";
		
		if(num1 > 0 && num2 > 0){
		for(int i = 1;i <= num2; i++)
		resultado = resultado + num1;
		
		cout << "Resultado = " << num1 << " * " << num2 << " = " << resultado;
		}
		else
		cout << "El n�mero tiene que ser positivo";
	
	return 0;

}