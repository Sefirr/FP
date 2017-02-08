#include <iostream>
using namespace std;
#include <fstream>
#include <iomanip>

const int Max = 10;

typedef int *tIntPtr;

typedef struct {
	tIntPtr punt;
	int capacidad;
	int cont;
} tLista;


bool cargar(tLista &lista);
void muestra(tLista lista);
void ampliar(tLista &lista);

int main() {
	tLista lista;

	//Creación del array dinámico
	lista.punt = new int[Max];

	//Carga del archivo...
	if(!cargar(lista))
		cout << "Error..." << endl;
	else {
		muestra(lista);
	}

	delete [] lista.punt;

	return 0;
}

//No ampersant porque el puntero no cambia. Cambia solo aquello a lo q apunta.
bool cargar(tLista &lista) {
	bool correcto = true;
	ifstream archivo;

	lista.punt = new int[Max];
	lista.capacidad = Max;
	lista.cont = 0;

	archivo.open("enteros.txt");

	if(!archivo.is_open())
		correcto = false;
	else {
		int elem;
		archivo >> elem;
		while(elem != -1)  //&& lista.cont < MAX
		{
			lista.punt[lista.cont] = elem;
			lista.cont++;
			if(lista.cont == lista.capacidad)
				ampliar(lista);
			archivo >> elem;
		}
		archivo.close();
	}

	return correcto;
}

void muestra(tLista lista) {
	for(int i = 0; i < lista.cont; i++) {
		cout << setw(3) << i + 1 << " - " << lista.punt[i] << endl;
	}
}
void ampliar(tLista &lista){
	cout << "Ampliando el array dinámico..." << endl;
	tIntPtr aux = new int[lista.capacidad + Max];
	for(int i = 0; i < lista.cont; i++)
		aux[i] = lista.punt[i];

	tIntPtr p = aux;
	aux = lista.punt;
	lista.punt = p;

	delete [] aux;
	lista.capacidad = lista.capacidad + Max;

}