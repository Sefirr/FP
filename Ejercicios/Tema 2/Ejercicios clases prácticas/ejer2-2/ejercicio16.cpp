/* Escribe un programa que pida números al usuario, hasta que éste introduzca un
0, y que para cada uno, si es positivo, diga si es par o impar (si es negativo,
simplemente lo ignorará). */

#include <iostream>
using namespace std;

int main()
{
	int num;
	
	cout << "Introduzca un número: ";
	cin >> num;
	while(num != 0){
		if(num > 0) {
			if(num % 2 == 0)		
				cout << "El número es par." << endl;
			else
				cout << "El número es impar";
			cout << endl;
		}
		cout << "Introduce un número (0 para terminar): ";
		cin >> num;
	}
	return 0;
}