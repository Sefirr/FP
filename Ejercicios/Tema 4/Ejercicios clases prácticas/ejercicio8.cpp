/* 8 - Escribe un programa que calcule cuántos números triangulares hay en un
archivo de texto con enteros (cada número en una línea y terminado en 0 como
centinela). Se dice que un número es triangular si es igual a la suma de varios
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
		cout << "El número " << dato << " ";
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