#include <iostream>
using namespace std;
#include <fstream>

const int ALUMNOS = 10;
typedef double tCalif[ALUMNOS];

//Prototipos
void leer(tCalif notas);
void mostrar(const tCalif notas);
double media(const tCalif notas);
int suspensos(const tCalif notas);

int main() {
	tCalif calificaciones;
	leer(calificaciones);
	mostrar(calificaciones);

	return 0;
}

void leer(tCalif notas) {

	for(int i = 0; i < ALUMNOS; i++) {
		do {
		cout << "Introduce la nota del estudiante " << i + 1 << ": ";
		cin >> notas[i];
		if((notas[i] < 0 || notas[i] > 10))
			cout << "Debe estar entre 0 y 10!" << endl;
		} while((notas[i] < 0) || (notas[i] > 10));
	}
	cout << endl;
}

void mostrar(const tCalif notas) {

	int susp;

	for(int i = 0; i < ALUMNOS; i++) {
		cout << "Nota del estudiande " << i + 1 << ": " << notas[i] << endl;
	}
	cout << endl;
	cout << "Nota media = " << media(notas) << endl;
	susp = suspensos(notas);
	cout << ALUMNOS - susp << " aprobados y " << susp << " suspensos. " << endl;

}

double media(const tCalif notas) {
	double media = 0;

	for(int i = 0; i < ALUMNOS; i++) {
		media = media + notas[i];
	}
	media = media / ALUMNOS;

	return media;
}

int suspensos(const tCalif notas) {
	int cont = 0;

	for(int i = 0; i < ALUMNOS; i++) {
		if(notas[i] < 5)
			cont++;
	}

	return cont;
}