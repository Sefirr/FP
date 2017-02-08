/* Matem�ticamente se puede demostrar que todos los n�meros perfectos son,
adem�s, triangulares. Escribe un programa que compruebe emp�ricamente que
esto es cierto para todos los n�meros perfectos menores de 100.000. */
#include <iostream>
using namespace std;
#include <fstream>

bool esPerfecto(int dato);
bool esTriangular(int dato);

int main() {
	cout << "N�meros perfectos: " << endl;
	for(int i = 1; i <= 100000; i++) {
		if(esPerfecto(i) && esTriangular(i))
			
			cout << i << endl; 
	}

	return 0;
}

bool esTriangular(int dato) {

	int suma = 0;
	int entero = 1;

	while (suma < dato) {
		entero++;
		suma = suma + entero;
	}
	return (suma == dato);

}

bool esPerfecto(int dato) {

	int suma = 0;
	int entero = 0;
	while (suma < dato) {
		entero++;
		if(dato % entero == 0)
			suma = suma + entero;
	}
	return (suma == dato);
}