// Examen parcial de Febrero 2013
// Hecho por Javier Villarreal Rodríguez
// Fernando Saavedra Hernandez 
// 51483482Y

//>>>>> No ignores los 'warning'
//>>>>> Te dicen que tienes una variable que no usas

#include <iostream>
using namespace std;
#include<fstream>

void menu (); //>>>>> ���No devuelve la opci�n???

bool apartado1 ();
bool generar (int max);
void apartado2 ();
void recorrer ();
bool esFeliz(int numero);
int sumaDigitos (int numero);
void apartado3 ();
bool buscar(int aError, int &linea, int &diferencia);
bool diferencia (int aError, int numero, int &diferencia, char modo, int numero1);

//>>>>> Incluye un comentario junto a cada prototipo explicando su utilidad y sus par�metros

int main () {
	menu(); //>>>>> No merece la pena hacer un subprograma que contenga todo lo que hay que hacer!!!

	return 0;
}


void menu () {
	int opcion = -1;
	bool secuencia = false;

	while (opcion != 0) {
		cout << "1 - Generar una secuencia" << endl
			<< "2 - Procesar la secuencia" << endl
			<< "3 - Buscar en la secuencia" << endl
			<< "0 - Salir" << endl
			<< "Opcion: ";
		cin >> opcion;
		if ((opcion < 0) || (opcion > 3)) {
			cout << "Opci�n no v�lida!" << endl << endl;
			opcion = -1;
		}
		else {//>>>>> ���else!!!

		switch (opcion) {
			case 1: { 
				cout << endl;
				secuencia = apartado1(); 
				break; 
			}
			case 2: { 
				cout << endl;
				if (secuencia) apartado2(); 
				else cout << "Ninguna secuencia generada" << endl;
				break; 
			}
			case 3: { 
				cout << endl;
				if (secuencia) apartado3(); 
				else cout << "Ninguna secuencia generada" << endl;
					
			}
		}
		}
	}
}
bool apartado1 () {
	int max;
	bool encontrado = false;
	cout << "Indique un valor máximo: ";
	cin >> max;
	if (generar(max)) encontrado = true;
	return encontrado;

}
bool generar (int max) {
	ofstream out;
	int numero = -1;
	bool generada = false;
	out.open("datos.txt");
	
	while (numero != 0) {
		cout << "Introduzca un número entero [0 para terminar]: ";
		cin >> numero;
		if ((numero > 0) && (numero <= max)) {
			out << numero << endl;
			generada = true;
		}
	}

	out << -1;

	out.close();
	return generada;
}
void apartado2 () {
	recorrer();
	cout << endl;
}
void recorrer () {
	ifstream in;
	int numero;
	bool feliz = false;
	in.open("datos.txt");

	in >> numero;
	while (numero != -1) {
		feliz = esFeliz(numero);
		cout << numero;
		if (feliz) cout << " es Feliz";
		else cout << " no es Feliz";
		cout << endl;
		in >> numero;
	}
   in.close();

}
bool esFeliz(int numero) {
	bool feliz = false;
	int aux;
	aux = sumaDigitos (numero);
	while (aux >= 10) aux = sumaDigitos(aux);
	if (aux == 1) feliz = true;

	return feliz;
}
int sumaDigitos (int numero) {
	int suma = 0, aux = 0;
	do {
		aux = numero % 10;
		numero /= 10;
		suma += aux * aux;
	} while (numero != 0);
	return suma;
}
void apartado3 () {
	int aError = 0, linea = 0, diferencia = 0;
	bool encontrado;
	cout << "Introduzca el error admisible: ";
	cin >> aError;
	encontrado = buscar(aError, linea, diferencia);

	if (encontrado) 
		cout << "Encontrado en linea " << linea << " (diferencia: " << diferencia << ")" << endl << endl;
	else 
		cout << "El número no ha sido encontrado" << endl;



}
bool buscar(int aError, int &linea, int &dif) {
	int aux, numero, numero1;
	bool encontrado = false;
	ifstream in;
	in.open("datos.txt"); 
	
	in >> numero;
	while ((numero != -1) && (!encontrado)) {
		linea++;
		in >> numero1;

		encontrado = diferencia(aError, numero, dif, '+', numero1);
		encontrado = diferencia(aError, numero, dif, '-', numero1);
	}

	in.close();

	return encontrado;
}
bool diferencia (int aError, int numero, int &diferencia, char modo, int numero1) {
	int aux; 
	bool encontrado = false;
	for(int i = 0; i < aError; i++) {
		if (modo == '+') aux = numero1 + i;
		else if (modo == '-') aux = numero1 - i;
		if (aux == numero) {
			encontrado = true;
			diferencia = i;
		}
	}

	return encontrado;

}
