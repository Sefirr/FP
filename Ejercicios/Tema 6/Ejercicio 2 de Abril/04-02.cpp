#include <iostream>
#include <string>
using namespace std;
#include <fstream>
#include <iomanip>

const int MaxProd = 20;
const int MaxES = 100;
const string FileName = "datos.txt";

typedef struct {
	string fecha;
	char tipo; // E o S
	int unidades;
} tMov;

typedef tMov tArrayMov[MaxES];

typedef struct {
	tArrayMov elem;
	int cont;
} tListaES;

typedef struct {
	int codigo;
	string nombre;
	double precio;
	int unidades;
	tListaES listaES;
	bool actualizado;
} tProd;

typedef tProd tArrayProd[MaxProd];

typedef struct {
	tArrayProd productos;
	int cont;
} tListaProd;

bool leer(tListaProd &listaProd);
void ordenar(tListaES &lista);
int buscarProducto(tListaProd listaProd, int codigo);
int buscarES(tListaES lista, string fecha);
void mostrar(tListaProd listaProd);
void actualizar(tListaProd &listaProd);

int main() {
	tListaProd listaP;
	system("chcp 1252");
	leer(listaP);
	mostrar(listaP);
	cout << "-------------------------------------" << endl;
	for (int i = 0; i < listaP.cont; i++) {
		ordenar(listaP.productos[i].listaES);
	}
	mostrar(listaP);
	cout << "-------------------------------------" << endl;
	actualizar(listaP);
	mostrar(listaP);

	char c;
	cout << "Pulsa Intro para terminar...";
	cin.get(c);

	return 0;
}

bool leer(tListaProd &listaProd) {
	bool ok = true;
	tProd producto;
	tMov mov;
	ifstream archivo;
	char aux;
	listaProd.cont = 0;
	archivo.open(FileName.c_str());
	if (!archivo.is_open()) {
		ok = false;
	}
	else {
		// Leer el primer código
		archivo >> producto.codigo;
		// Mientras el código no sea -1 y la lista no esté llena
		while ((producto.codigo != -1) && (listaProd.cont < MaxProd)) {
			// Leer el resto de los datos del producto
			archivo.get(aux); // Saltar el Intro tras el código
			getline(archivo, producto.nombre);
			archivo >> producto.precio;
			archivo >> producto.unidades;
			producto.actualizado = false;
			producto.listaES.cont = 0;

			// Leer la primera fecha
			archivo >> mov.fecha;
			// Mientras la fecha sea distinta de "X" y la lista no esté llena
			while ((mov.fecha != "X") && (producto.listaES.cont < MaxES)) {
				// Leer el tipo y las unidades
				archivo >> mov.tipo;
				archivo >> mov.unidades;
				// Insertar el mov en la lista
				producto.listaES.elem[producto.listaES.cont] = mov;
				producto.listaES.cont++;
				// Leer la siguiente fecha
				archivo >> mov.fecha;
			}

			// Insertar el producto en la lista
			listaProd.productos[listaProd.cont] = producto;
			listaProd.cont++;

			// Leer el siguiente código
			archivo >> producto.codigo;
		}
		archivo.close();
	}
	return ok;
}

void ordenar(tListaES &lista) {
	bool inter = true;
	int i = 0;
	while ((i < lista.cont - 1) && inter) {
		// Desde el primer elemento hasta el penúltimo o no haya que seguir
		inter = false;
		for (int j = lista.cont - 1; j > i; j--)
			// Desde el último hasta el siguiente a i
			if (lista.elem[j].fecha < lista.elem[j - 1].fecha) {
				tMov tmp;
				tmp = lista.elem[j];
				lista.elem[j] = lista.elem[j - 1];
				lista.elem[j - 1] = tmp;
				inter = true;
			}
			if (inter)
				i++;
	}

}

int buscarProducto(tListaProd listaProd, int codigo) {
	int pos;
	bool encontrado = false;
	
	pos = 0;
	while ((pos < listaProd.cont) && !encontrado) {
		if (listaProd.productos[pos].codigo == codigo) {
			encontrado = true;
		}
		else {
			pos++;
		}
	}
	if (!encontrado) {
		pos = -1;
	}

	return pos;
}

int buscarES(tListaES lista, string fecha) {
	int pos;
	int ini = 0, fin = lista.cont - 1, mitad;
	bool encontrado = false;
	while ((ini <= fin) && !encontrado) {
		mitad = (ini + fin) / 2; // División entera
		if (fecha == lista.elem[mitad].fecha)
			encontrado = true;
		else if (fecha < lista.elem[mitad].fecha)
			fin = mitad - 1;
		else
			ini = mitad + 1;
	}
	if (encontrado)
		pos = mitad;
	else
		pos = -1;
	
	return pos;
}

void mostrar(tListaProd listaProd) {
	for (int i = 0; i < listaProd.cont; i++) {
		tProd prod = listaProd.productos[i];
		cout << "Código: " << prod.codigo << endl;
		cout << "Nombre: " << prod.nombre << endl;
		cout << fixed << setprecision(2) << prod.precio << " € - "
			<< prod.unidades << " unidades" << endl;
		for (int j = 0; j < prod.listaES.cont; j++) {
			cout << "El " << prod.listaES.elem[j].fecha << " ";
			if (prod.listaES.elem[j].tipo == 'E')
				cout << "entran ";
			else
				cout << "salen ";
			cout << prod.listaES.elem[j].unidades << " unidades" << endl;
		}
		cout << endl;
	}
}

void actualizar(tListaProd &listaProd) {
	for (int i = 0; i < listaProd.cont; i++) {
		// tProd prod = listaProd.productos[i];
		for (int j = 0; j < listaProd.productos[i].listaES.cont; j++) {
			if (listaProd.productos[i].listaES.elem[j].tipo == 'E')
				listaProd.productos[i].unidades = listaProd.productos[i].unidades + listaProd.productos[i].listaES.elem[j].unidades;
			else {
				listaProd.productos[i].unidades = listaProd.productos[i].unidades - listaProd.productos[i].listaES.elem[j].unidades;
				if (listaProd.productos[i].unidades < 0)
					cout << "ERROR: el " << listaProd.productos[i].listaES.elem[j].fecha 
					     << " salen más unidades de las existentes en el producto "
						 << listaProd.productos[i].codigo << endl;
			}
		}
		//listaProd.productos[i] = prod;
	}
}