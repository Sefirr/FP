/* Modifica el programa anterior de forma que si la suma de los dígitos es mayor
que 9, repita el proceso sobre la propia suma, hasta obtener un valor entre 1 y 9.
Ése es el que se conoce como dígito mágico del número introducido. */

#include <iostream>
using namespace std;

int main()
{
	int num, suma = 0, valor, suma_;
	
	
	
	do
	{
		cout << "Introduzca un número positivo: ";
		cin >> num;
		
		while(num > 0)
		{
			valor = num % 10;
			num = num / 10;
			suma += valor;
		}
		
		
	} while(num != 0);
	
	//Dígito mágico
	while(suma > 9)
	{
		valor = suma % 10;
		suma = suma / 10;
		suma_ +=  suma;
	}
	cout << "El dígito mágico es " << suma << endl;
	return 0;
}