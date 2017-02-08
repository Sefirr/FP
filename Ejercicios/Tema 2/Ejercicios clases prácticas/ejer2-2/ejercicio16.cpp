/* Escribe un programa que pida n�meros al usuario, hasta que �ste introduzca un
0, y que para cada uno, si es positivo, diga si es par o impar (si es negativo,
simplemente lo ignorar�). */

#include <iostream>
using namespace std;

int main()
{
	int num;
	
	cout << "Introduzca un n�mero: ";
	cin >> num;
	while(num != 0){
		if(num > 0) {
			if(num % 2 == 0)		
				cout << "El n�mero es par." << endl;
			else
				cout << "El n�mero es impar";
			cout << endl;
		}
		cout << "Introduce un n�mero (0 para terminar): ";
		cin >> num;
	}
	return 0;
}