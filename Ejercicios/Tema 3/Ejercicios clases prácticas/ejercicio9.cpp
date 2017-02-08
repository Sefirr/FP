/* Modifica el programa anterior de forma que si la suma de los d�gitos es mayor
que 9, repita el proceso sobre la propia suma, hasta obtener un valor entre 1 y 9.
�se es el que se conoce como d�gito m�gico del n�mero introducido. */

#include <iostream>
using namespace std;

int main()
{
	int num, suma = 0, valor, suma_;
	
	
	
	do
	{
		cout << "Introduzca un n�mero positivo: ";
		cin >> num;
		
		while(num > 0)
		{
			valor = num % 10;
			num = num / 10;
			suma += valor;
		}
		
		
	} while(num != 0);
	
	//D�gito m�gico
	while(suma > 9)
	{
		valor = suma % 10;
		suma = suma / 10;
		suma_ +=  suma;
	}
	cout << "El d�gito m�gico es " << suma << endl;
	return 0;
}