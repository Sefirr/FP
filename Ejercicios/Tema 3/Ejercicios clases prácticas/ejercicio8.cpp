/* Escribe un programa que lea un n�mero entero positivo del teclado y muestre la
suma de sus d�gitos. Por ejemplo, si el entero es 932, mostrar� 14 (9 + 3 + 2). */

#include <iostream>
using namespace std;

int main()
{
	int num, suma = 0, valor;
	
	
	
	do
	{
		cout << "Introduzca un n�mero positivo: ";
		cin >> num;
		
		while(num > 0){
		valor = num % 10;
		num = num / 10;
		suma += valor;
		}
	} while(num != 0);
	cout << "La suma de sus d�gitos es " << suma << endl;
	return 0;
}