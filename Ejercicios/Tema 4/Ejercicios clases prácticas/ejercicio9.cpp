/* Escribe un programa que calcule cuántos números perfectos hay en un archivo
de texto con enteros (cada número en una línea y terminado en 0 como
centinela). Se dice que un número (entero positivo) n es perfecto, si la suma de
los divisores de n entre 1 y n‐1 es igual a n. Por ejemplo, 6 es un número
perfecto, pues sus divisores, incluyendo el 1 pero no el propio 6, son 1, 2 y 3, y
sumados dan 6 */

#include <iostream>
using namespace std;
#include <fstream>

int main() {
	int dato;
	int suma;
	int entero;
	bool perfecto = false;
	ifstream entrada;
	entrada.open("datos.txt");

	entrada >> dato;
	while (dato != 0) {
		suma = 0;
		entero = 0;
		while (suma < dato) {
			entero++;
			if(dato % entero == 0)
				suma = suma + entero;
		}
		perfecto = (suma == dato);
		cout << "El número " << dato << " ";
		if (perfecto)
			cout << "SI";
		else
			cout << "NO";
		cout << " es perfecto";
		if (perfecto)
			cout << " (1.." << entero << ")";
		cout << endl;
		entrada >> dato;
	}
	entrada.close();

	return 0;
}
