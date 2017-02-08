/* Escribe un programa que lea un número entero positivo del teclado y muestre la
suma de sus dígitos. Por ejemplo, si el entero es 932, mostrará 14 (9 + 3 + 2). */

#include <iostream>
using namespace std;

int main()
{
	int num, suma = 0, valor;
	
	
	
	do
	{
		cout << "Introduzca un número positivo: ";
		cin >> num;
		
		while(num > 0){
		valor = num % 10;
		num = num / 10;
		suma += valor;
		}
	} while(num != 0);
	cout << "La suma de sus dígitos es " << suma << endl;
	return 0;
}