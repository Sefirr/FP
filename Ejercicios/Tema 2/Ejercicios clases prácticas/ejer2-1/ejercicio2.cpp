/* Escribe un programa que nos diga cuál es el volumen de un cono con un radio de
la base de 14,5 y una altura de 26,79. La fórmula que debes usar es:
Recuerda que el valor (aproximado) de pi es 3,141592. */

#include <iostream>
using namespace std;

int main()
{
	double radio, altura, volumen;
	radio = 14.5;
	altura = 26.79;
	volumen = (3.141592*(radio*radio)*altura)/3;
	cout << "Volumen de un cono de radio " << radio << " y altura " << altura << " = "<< volumen;
	return 0;
}
