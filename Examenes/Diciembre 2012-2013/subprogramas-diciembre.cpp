// Control de diciembre de 2012

#include <iostream>
using namespace std;
#include <fstream>
#include <iomanip>


void menu(int &opcion) {
	cout << "1 - Crear la secuencia" << endl;
	cout << "2 - Procesar la secuencia" << endl;
	cout << "3 - Buscar en la secuencia" << endl;
	cout << "0 - Salir" << endl;
	cout << "Opción: ";
	cin >> opcion;
}

void generar() {
	ifstream entrada;
	ofstream salida;
	int dato;

	salida.open("datos.txt");
			cout << "Entero positivo (0 para terminar): ";
			cin >> dato;
			while (dato != 0) {
				if ((dato >= 1) && (dato <= 1000))
					salida << dato << endl;
				cout << "Entero positivo (0 para terminar): ";
				cin >> dato;
			}
			salida << -1;
			salida.close();
}

void Primo(int dato) {
	
	bool esPrimo = true;
	cout << setw(4) << dato << " ";

		for (int i = 2; i <= dato / 2; i++) {
			if (dato % i == 0)
				if (esPrimo) { // Primer divisor encontrado
					esPrimo = false;
					cout << "no es primo (" << i;
				}
				else // No es el primer divisor
					cout << ", " << i;
		}
		if (esPrimo)
			cout << "es primo";
		else
			cout << ")";
		cout << endl;
}

void procesar() {
		ifstream entrada;
		int dato;
		entrada.open("datos.txt");
			if (!entrada.is_open())
				cout << "¡Error al abrir el archivo!" << endl;
			else {
				entrada >> dato;
				while (dato != -1)  {
					Primo(dato);
					entrada >> dato;
				}
				}
		entrada.close();
}

void buscar() {
	ifstream entrada;
	int dato, buscado, linea;
	bool encontrado;
	
	entrada.open("datos.txt");
            if (!entrada.is_open())
               cout << "¡Error al abrir el archivo!" << endl;
            else {
               cout << "Cuadrado a buscar: ";
               cin >> buscado;
               encontrado = false;
               linea = 1;
               entrada >> dato;
               while ((dato != -1) && !encontrado)
                  if ((dato * dato >= buscado - 10) && (dato * dato <= buscado + 10))
                     encontrado = true;
                  else {
                     entrada >> dato;
                     linea++;
                  }
               entrada.close();
               if (encontrado)
                  cout << "Encontrado en la línea " << linea << ": " << dato 
                       << " (cuadrado: " << dato * dato << ")" << endl;
               else
                  cout << "¡Ninguno mayor o igual que el buscado!" << endl;
            }
}

int main() {
	int opcion = -1;

	cout << endl;
	while (opcion != 0) {
		menu(opcion);
		switch(opcion) {
			case 0: break;
			case 1: generar(); break;
			case 2: procesar(); break;
			case 3: buscar(); break;
			default: cout << "Opción no válida" << endl;
		}
	}

	return 0;
}