#include <iostream>
using namespace std;
#include <cctype>

int main()
{
	char caracter;
	bool encontrado = false;
	
	cout << "Introduce caracteres(. para leer caracteres y * para terminar): ";
	cin.get(caracter);
	
	while(caracter != '.') {
		int digito = 0;
		int letra = 0;
		int space = 0;
		
		while(caracter != '.' && !encontrado)
		{
			if(caracter == '(')
				encontrado = true;
			else
				cin.get(caracter);
		}
				
		if(!encontrado)
			cout << "No había ningún paréntesis (" << endl;
		else {
			encontrado = false;
			while( caracter != '.' && !encontrado)
			{
				if(caracter == ')')
					encontrado = true;
				else
				{
					cin.get(caracter);
					if(isdigit(caracter))
						digito++;
					if(isalpha(caracter))
						letra++;
					if(caracter == ' ')
						space++;
				}
			}
			
		}

		cout << "Blancos: " << space << endl;
		cout << "Letras: " << letra << endl;
		cout << "Dígitos: " << digito << endl;
		
		cin.sync();
		
		cout << "Introduce caracteres(. para leer caracteres y * para terminar): ";
		cin.get(caracter);	
		
	}
	
			
	return 0;
}