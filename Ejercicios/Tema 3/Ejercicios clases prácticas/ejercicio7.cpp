/* Modifica el programa anterior de modo que los caracteres se introduzcan todos
en la misma línea acabados en salto de línea (Intro) (no en asterisco). ¡Y que
cuente también los espacios en blanco! */
#include <iostream>
using namespace std;
#include <cctype>

int main()
{
	char caracter;
	int digit = 0, upper = 0, lower = 0, spacewhite = 0;
		
	do
	{
		cin.get(caracter);
		if(c != '\n')
			if(isdigit(caracter))
				digit++;
				else if(isupper(caracter))
					upper++;
				else if(islower(caracter))
					lower++;
				else if(caracter = ' ')
					spacewhite++;
		
	}
		
	}
	while(caracter != '\n');
	
	cout << endl << "Número de dígitos: " << digit << endl;
	cout << "Número de letras mayúsculas: " << upper << endl;
	cout << "Número de letras minúsculas: " << lower << endl;
	cout << "Número de espacios en blanco: " << spacewhite << endl;

	return 0;

}