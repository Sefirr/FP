// Examen de Abril Curso 2012/13
// Hecho por Javier Villarreal Rodríguez
// DNI: 06030112-H

#include <iostream>
#include <string>
using namespace std;
#include <fstream>
//>>>>> Falta incluir iomanip

//>>>>> Estilo correcto. Sin comentar.

const int N = 20;
const int Max_ES = 100;
typedef struct {
	int codigo;
	string nombre;
} tLista;

typedef tLista tListaProd[N];

typedef struct {
	tListaProd coches;
	int cont;
} tCoches;

typedef struct {
	int codigo;
	string fecha;
	int dias;
} tList;

typedef tList tListaRent[Max_ES];

typedef struct {
	tListaRent renta;
	int cont;
} tRenta;

//>>>>> Algunos nombres son algo confusos

//Protótipos
bool leerModelos(tCoches &coches);
bool leerAlquileres(tRenta &renta);
void mostrar(tCoches coches, tRenta renta);
void ordenar(tListaRent &renta);
int buscar(tCoches coches, tListaRent renta); //>>>>> Sólo la de coches, pero además el código a buscar!


int main() {
	tCoches coches;
	tRenta renta;

	system("chcp 1252");
	leerModelos(coches);
	leerAlquileres(renta);
   
   //>>>>> ¿Se han leído bien?

	for(int i = 0; i < Max_ES; i++) {
	ordenar(renta.renta);
   //>>>>> ¿?¿?¿?¿? Se ordena siempre la misma (única) lista!!!!!
	}
	mostrar(coches, renta);

	return 0;
}

bool leerModelos(tCoches &coches) {
	bool ok = true;
	tLista coches_E;
	ifstream archivo;

	archivo.open("coches.txt");
	coches.cont = 0;

	if(!archivo.is_open())
		ok = false;
	else {
		archivo >> coches_E.codigo;
		while((coches_E.codigo != -1) && (coches.cont < N)) {
			getline(archivo, coches_E.nombre);

			coches.coches[coches.cont] = coches_E;
			coches.cont++;
			
			archivo >> coches_E.codigo;
		}
		archivo.close();
	}

	return ok;
}

bool leerAlquileres(tRenta &renta) {
	bool ok = true;
	tList renta_E;
	ifstream archivo;

	archivo.open("rent.txt");
	renta.cont = 0;

	if(!archivo.is_open())
		ok = false;
	else {
		archivo >> renta_E.codigo;
		while((renta_E.codigo != -1) && (renta.cont < Max_ES)) {
			archivo >> renta_E.fecha;
			archivo >> renta_E.dias;

			renta.renta[renta.cont] = renta_E;
			renta.cont++;

			archivo >> renta_E.codigo;
		}
		archivo.close();
	}

	return ok;
}

void ordenar(tListaRent &renta) {

	bool inter = true;
	int i = 0;

	while((i < N - 1) && inter) {
   //>>>>> NO!!! Hasta el contador de la lista!!!

		inter = false;
		for(int j =	N - 1; j > i; j--) //>>>>> Ídem!!!

			if(renta[j].fecha < renta[j - 1].fecha) {
				tList tmp;
				tmp = renta[j];
				renta[j] = renta[j - 1];
				renta[j - 1] = tmp;
				inter = true;

					if(inter)
						i++;

			}
	}
}


void mostrar(tCoches coches, tRenta renta) {

	bool encontrado = false;
	int i = 0;
	while((i < renta.cont)) {
		int j = 0;
		while((renta.renta[i].codigo != coches.coches[j].codigo) && (j < coches.cont)) {
      //>>>>> Usar buscar()!!!!!

			if(renta.renta[i].codigo == coches.coches[j].codigo)
				encontrado = true;
			else
				j++;
		}
		i++;
		if(encontrado) {
			cout << renta.renta[i].fecha << " ";
			cout << coches.coches[j].nombre << " ";
			cout << renta.renta[i].dias << "día(s)" << endl;
			//>>>>> No quedan alineados!

		}
		else
			cout << "ERROR: ¡¡¡Modelo inexistente!!!" << endl;
		
	}
}

