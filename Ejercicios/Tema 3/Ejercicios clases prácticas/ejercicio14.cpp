/* Disponemos de cuatro variaciones del archivo de texto entrada.txt:
Caso 1   
134
12.4
14256.789
27.4
100
Caso 2
134 12.4 c 1 2
14256.789
Caso 3
13.4
12
.18.2 14.7
Caso 4
13.4
12


Indica el valor de cada una de las variables después de ejecutar dicho fragmento
de código con los cuatro ejemplos de archivo de entrada. ¡Sin ejecutar el código
con un compilador! 
Caso 1
entero1: 134
float1: 14256.789
double1: 12.4
car1: 0
car2: 0

Caso 2
entero1: 134
float1:  1
double1: 12.4
car1: c
car2: 2

Caso 3
entero1: 13
float1:  12
double1: 4
car1: 0
car2: .

Caso 4
entero1: 13
float1: 12
double1 4:
car1: 0
car2: 0

*/


#include <iostream>
using namespace std;
#include <fstream>

int main()
{

	int entero1;
	float float1;
	double double1;
	char car1, car2;
	ifstream archivo;

	archivo.open("entrada.txt"); // Apertura
	archivo >> entero1 >> double1 >> car1;
	archivo >> float1 >> car2;
	
	return 0; 
}