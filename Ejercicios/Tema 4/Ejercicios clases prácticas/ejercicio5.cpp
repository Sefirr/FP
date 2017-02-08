#include <iostream>
using namespace std;

//Prototipos
bool esMinuscula(char c);
bool esMayuscula(char c);
bool esLetra(char c);
bool esDigito(char c);
bool esAlfanumerico(char c);

int main() {

	system("chcp 1252");

	char car;
	int minus = 0;
	int mayus = 0;
	int letra = 0;
	int digito = 0;
	int alfanumerico = 0;
	
	cout << "Introduce carácteres: ";
	
	cin.get(car);
	while(car != '\n') {
		if( esMinuscula(car) )
			minus++;
		if( esMayuscula(car) )
			mayus++;
		if( esLetra(car) )
			letra++;
		if( esDigito(car) )
			digito++;
		if( esAlfanumerico(car) )
			alfanumerico++;

		cin.get(car);
	}
	
	//Mostrar resultados
	cout << "Minúscula: " << minus << endl;
	cout << "Mayúscula: " << mayus << endl;
	cout << "Letras: " << letra << endl;
	cout << "Dígitos: " << digito << endl;
	cout << "Alfanumérico: " << alfanumerico << endl;
	

	return 0;
}

bool esMinuscula(char c) {

	return ( (c >= 'a') && ( c <= 'z') );
}

bool esMayuscula(char c) {

	return ( (c >= 'A') && ( c <= 'Z') );
}

bool esLetra(char c) {

	return ( esMinuscula(c) || esMayuscula(c) );
}

bool esDigito(char c) {

	return ( (c >= '0') && (c <= '9') ); 
}

bool esAlfanumerico(char c) {

	return ( esLetra(c) || esDigito(c) );
}