/* Modifica el programa anterior de modo que los caracteres se introduzcan todos
en la misma l�nea acabados en salto de l�nea (Intro) (no en asterisco). �Y que
cuente tambi�n los espacios en blanco! */
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
	
	cout << endl << "N�mero de d�gitos: " << digit << endl;
	cout << "N�mero de letras may�sculas: " << upper << endl;
	cout << "N�mero de letras min�sculas: " << lower << endl;
	cout << "N�mero de espacios en blanco: " << spacewhite << endl;

	return 0;

}