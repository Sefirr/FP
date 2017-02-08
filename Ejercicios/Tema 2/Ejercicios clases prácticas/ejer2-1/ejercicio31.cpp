/* Escribe un programa que nos diga cuál es el volumen de un cono con un radio de
la base de 14,5 y una altura de 26,79. La fórmula que debes usar es:
Recuerda que el valor (aproximado) de pi es 3,141592. */

#include <iostream>
using namespace std;

int main()
{
	double fahrenheit, celsius;
	cout << "Grados Fahrenheit = ";
	cin >> fahrenheit;
	celsius = double(5) / 9 * (fahrenheit - 32);
	cout << "La conversion de grados fahrenheit "<< fahrenheit << " es " << celsius << endl;
	return 0;
}
