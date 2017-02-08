#include <iostream>
#include <cstring>
using namespace std;
#include <fstream>
#include <iomanip>



const int MAX = 100;
const int MAXNIF = 10;
const int MAXNOMDIR = 120;

typedef char cadNIF [MAXNIF];
typedef char cadNOM[MAXNOMDIR];
typedef char cadDIR[MAXNOMDIR];

typedef struct {
	cadNIF nif;
	cadNOM nombre;
	int edad;
	cadDIR direc;
	double sueldo;
	bool casado;
	int hijos;
} tEmpleado;

const int SIZE = sizeof(tEmpleado);

typedef tEmpleado *tEmpPtr;

typedef struct {
	tEmpPtr empleados;
	int cont;
} tLista;

void mostrar (tLista lista);
void leerTXT (tLista &lista);
void guardarDAT (tLista lista);
void leerDAT (tLista &lista);

int main() {
	system("chcp 1252");
	tLista lista;

	leerTXT(lista);
	mostrar(lista);
	leerDAT(lista);
	guardarDAT(lista);

	delete [] lista.empleados;
	return 0;
}


void mostrar (tLista lista){
	for(int i = 0; i < lista.cont; i++) {
		tEmpleado emp = lista.empleados[i];
		cout << emp.nif << " " << emp.nombre << endl;
		cout << emp.direc << endl;
		cout << emp.edad << " años, ";
		if(emp.casado)
			cout << "casado/a";
		else
			cout << "soletero/a";
		cout << ", " << emp.hijos << " hijo(s). Sueldo: " << fixed << setprecision(2) << emp.sueldo << " Eur." << endl << endl;
	}

}
void leerTXT (tLista &lista) {
	ifstream archivo;
	tEmpleado emp;
	int op;
	char aux;
	lista.cont = 0;
	lista.empleados = new tEmpleado[MAX];
	archivo.open("empleados.txt");
	if(archivo.is_open()) {

		archivo >> emp.nif;
		while ((strcmp(emp.nif,  "X") != 0) && (lista.cont < MAX)) {
			archivo.get(aux); //Para leer enteros y que pase al siguiente (intro)
			archivo.getline(emp.nombre, 120);
			archivo >> emp.edad;
			archivo.get(aux);
			archivo.getline(emp.direc, 120);
			archivo >> emp.sueldo;
			archivo >> op;
			if (op == 1)
				emp.casado = true;
			else
				emp.casado = false;
			archivo >> emp.hijos;
			lista.empleados[lista.cont] = emp;
			lista.cont++;
			archivo >> emp.nif;
		
		}
		archivo.close();
	}

}
void guardarDAT (tLista lista) {
	fstream archivo;
	archivo.open("empleados.dat", ios::out | ios::binary | ios::trunc);
	for(int i = 0; i < lista.cont; i++){
		archivo.write( (char *) &lista.empleados[i], SIZE);
	}
	archivo.close();
}
void leerDAT (tLista &lista){
	fstream archivo;
	archivo.open("empleados.dat", ios::in |ios::binary);
	if (!archivo.is_open()){
		archivo.seekg(0, ios::end);
		int pos = archivo.tellg();
		int numReg = pos /SIZE;
		lista.cont = numReg;
		lista.empleados = new tEmpleado[MAX];
		archivo.seekg(0, ios::beg);
		for (int i = 0; i < numReg; i++) {
			archivo.read( (char *) &lista.empleados[i], SIZE);
		}
	archivo.close();
	}
}