/* a) Un subprograma que, dado un vector, mueva sus componentes un lugar a la
derecha. El último componente se moverá al 1er lugar.
b) Un subprograma que, dado un vector, calcule y devuelva la suma de los
elementos que se encuentran en las posiciones pares del vector.
c) Un subprograma que, dado un vector, encuentre y devuelva la componente
de mayor valor.
d) Un subprograma que, dados dos vectores, devuelva un valor que indique si
son iguales.
e) Un subprograma que obtenga si alguno de los valores almacenados en el
vector es igual a la suma del resto de los valores del mismo.
f) Un subprograma que obtenga si alguno de los valores almacenados en el
vector está repetido. */
#include <iostream>
using namespace std;

const int N = 3;
typedef int tVector[N];

void mostrarVector(const tVector vector);
void leerVector(tVector vector);
void MovRight(tVector vector);
int suma(tVector vector);

int main() {
	int sumares;
	tVector vector;
	system("chcp 1252");

	leerVector(vector);
	cout << "El vector leído es: ";
	mostrarVector(vector);
	cout << endl;
	sumares = suma(vector);
	cout << "Suma de componentes pares = " << sumares;
	cout << endl;
	
	MovRight(vector);
	cout << endl;
	mostrarVector(vector);
	cout << endl; 
	return 0;
}

void mostrarVector(const tVector vector) {
	cout << "(";
	for(int i = 0; i < N - 1; i++) 
		cout << vector[i] << ",";
	cout << vector[N - 1]  << ")";
}

void leerVector(tVector vector) {

	for(int i = 0; i < N; i++) {
		cout << "Componente " << i + 1 << " = ";
		cin >> vector[i];
	}

}

void MovRight(tVector vector) {
	int aux = vector[N - 1];

		for(int i = N - 1; i > 0; i--)
			vector[i] = vector[i - 1];
	vector[0] = aux;
}

int suma(tVector vector) {
	int resultado = 0;

	for(int i = 0; i < N; i++)
		if( i % 2 == 0)
			resultado = resultado + vector[i];

	return resultado;
}