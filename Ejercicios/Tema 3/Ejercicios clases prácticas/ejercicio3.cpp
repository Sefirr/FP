/* Escribe un programa que solicite un car�cter por teclado e informe de si es
alfanum�rico o no (letra o d�gito). En caso de ser alfanum�rico deber� indicar si
es una letra o un d�gito. En caso de ser una letra deber� informar de si es
min�scula o may�scula. Para resolver este ejercicio no se deben usar las
funciones isalnum(), isalpha(), isdigit(), islower() o isupper(). */

#include <iostream>
using namespace std;

int main()
{
	char caracter;
	int num;
	
	cout << endl << "Inserte un car�cter: ";
	cin >> caracter;
	num = caracter;
	cout << endl;
	
	if((num >= 48 && num < 58) || (num >= 65 && num < 91) || (num >= 97 && num < 123) || (num >= 48 && num < 57))
	cout << "Es alfanum�rico." << endl;
	else
	cout << "No es alfanumerico." << endl;
	
	if(num >= 65 && num < 91 || num >=97 && num < 123)
	cout << "Es una letra" << endl;;
	if(num >= 65 && num < 91)
	cout << "Es una may�scula." << endl;
	if(num >= 97 && num < 123)
	cout << "Es una min�scula." << endl;
	if(num >= 48 && num < 57)
	cout << "Es un d�gito" << endl;

	return 0;
	
}