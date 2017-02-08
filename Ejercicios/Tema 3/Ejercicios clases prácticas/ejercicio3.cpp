/* Escribe un programa que solicite un carácter por teclado e informe de si es
alfanumérico o no (letra o dígito). En caso de ser alfanumérico deberá indicar si
es una letra o un dígito. En caso de ser una letra deberá informar de si es
minúscula o mayúscula. Para resolver este ejercicio no se deben usar las
funciones isalnum(), isalpha(), isdigit(), islower() o isupper(). */

#include <iostream>
using namespace std;

int main()
{
	char caracter;
	int num;
	
	cout << endl << "Inserte un carácter: ";
	cin >> caracter;
	num = caracter;
	cout << endl;
	
	if((num >= 48 && num < 58) || (num >= 65 && num < 91) || (num >= 97 && num < 123) || (num >= 48 && num < 57))
	cout << "Es alfanumérico." << endl;
	else
	cout << "No es alfanumerico." << endl;
	
	if(num >= 65 && num < 91 || num >=97 && num < 123)
	cout << "Es una letra" << endl;;
	if(num >= 65 && num < 91)
	cout << "Es una mayúscula." << endl;
	if(num >= 97 && num < 123)
	cout << "Es una minúscula." << endl;
	if(num >= 48 && num < 57)
	cout << "Es un dígito" << endl;

	return 0;
	
}