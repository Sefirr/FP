/* Escribe un programa que lea caracteres del teclado hasta que el usuario
introduzca un *. Los caracteres se solicitan e introducen uno a uno, cada uno en
una línea. El programa debe contar el número de dígitos, letras mayúsculas y
letras minúsculas introducidas y, cuando haya finalizado la introducción de
datos, mostrar cuántos caracteres de cada tipo había. */
#include <iostream>
using namespace std;
#include <cctype>

int main()
{
	char caracter;
	int digit = 0, upper = 0, lower = 0;

	do
	{
		cout << "Introduzca un carácter: ";
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

	cout << endl << "Número de dígitos: " << digit << endl;
	cout << "Número de letras mayúsculas: " << upper << endl;
	cout << "Número de letras minúsculas: " << lower << endl;

	return 0;

}