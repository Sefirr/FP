/* Escribe un programa que lea caracteres del teclado hasta que el usuario
introduzca un *. Los caracteres se solicitan e introducen uno a uno, cada uno en
una l�nea. El programa debe contar el n�mero de d�gitos, letras may�sculas y
letras min�sculas introducidas y, cuando haya finalizado la introducci�n de
datos, mostrar cu�ntos caracteres de cada tipo hab�a. */
#include <iostream>
using namespace std;
#include <cctype>

int main()
{
	char caracter;
	int digit = 0, upper = 0, lower = 0;

	do
	{
		cout << "Introduzca un car�cter: ";
		cin >> caracter;

		if(isalnum(caracter)){
			if(isdigit(caracter))
				digit++;
			else if(isalpha(caracter)){
				if(isupper(caracter))
					upper++;
				if(islower(caracter))
					lower++;
			}
		}

	}
	while(caracter != '*');

	cout << endl << "N�mero de d�gitos: " << digit << endl;
	cout << "N�mero de letras may�sculas: " << upper << endl;
	cout << "N�mero de letras min�sculas: " << lower << endl;

	return 0;

}