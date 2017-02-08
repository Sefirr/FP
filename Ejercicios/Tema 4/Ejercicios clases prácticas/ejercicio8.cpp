/* 8 - Escribe un programa que calcule cu�ntos n�meros triangulares hay en un
archivo de texto con enteros (cada n�mero en una l�nea y terminado en 0 como
centinela). Se dice que un n�mero es triangular si es igual a la suma de varios
enteros positivos consecutivos empezando desde 1. Por ejemplo 10 es triangular
(es igual a 1 + 2 + 3 + 4). */

#include <iostream>
using namespace std;
#include <fstream>

void numerosTriangulares() {

	ifstream entrada;
	int dato;
	int suma;
	int entero;
	bool triangular = false; 

	entrada.open("datos.txt");

	entrada >> dato;
	while (dato != 0) {
		suma = 0;
		entero = 0;
		while (suma < dato) {
			entero++;
			suma = suma + entero;
		}
		triangular = (suma == dato);
		cout << "El n�mero " << dato << " ";
		if (triangular)
			cout << "SI";
		else
			cout << "NO";
		cout << " es triangular";
		if (triangular)
			cout << " (1.." << entero << ")";
		cout << endl;
		entrada >> dato;
	}
	entrada.close();
}

int main() {

	numerosTriangulares();

	return 0;
}