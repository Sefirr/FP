// Hecho por el grupo 23
// Ejercicios clase práctica 19/02/2013
#include <iostream>
using namespace std;
#include <cmath>

const int N = 3;
typedef double tVector[N];

//Prototipos
void pedirDatos(tVector A, tVector B);
void pedirDatos2(tVector A);
void mostrar(tVector vector);
int menu();
void suma(tVector vector1, tVector vector2, tVector resultado);
void resta(tVector vector1, tVector vector2, tVector resultado);
double producto(tVector vector1, tVector vector2);
double modulo(tVector vector);
void normalizacionVector(tVector vector, tVector resultado);
double componenteMayor(tVector vector);

int main() {

	system("chcp 1252");

	tVector vector1, vector2, resultado;

	int opcion;
	double mayor;

	do {
		
		opcion = menu();
		
		switch(opcion) {
		case 0: break;
		case 1:
			pedirDatos(vector1 , vector2);
			suma(vector1,vector2, resultado); 
			break;
		case 2:
			pedirDatos(vector1 , vector2);
			resta(vector1, vector2, resultado); 
			break;
		case 3: 
		    pedirDatos2(vector1);

			cout << "Modulo del vector = ";
			modulo(vector1);
			break;
		case 4: 
			pedirDatos(vector1, vector2);
			mostrar(vector1);
			cout << " * ";
			mostrar(vector2);
			cout << " = " << producto(vector1,vector2); 
			break;
		case 5:
			pedirDatos2(vector1);
			cout << "Resultado = ";
			normalizacionVector(vector1, resultado);
			break;
		case 6:
			pedirDatos2(vector1);           
			mayor = componenteMayor(vector1);           
			cout << "La componente mayor es: " << mayor;
			break;
		default: cout << "Opción no válida" << endl;

		}
	} while(opcion != 0);

	return 0;
}

int menu() {

	int opcion;

	cout << endl << "1. Suma de vectores" << endl;
	cout << "2. Resta de vectores" << endl;
	cout << "3. Módulo de un vector" << endl;
	cout << "4. Producto escalar de 2 vectores" << endl;
	cout << "5. Normalización de un vector" << endl;
	cout << "6. Obtención de la componente de mayor valor" << endl;
	cout << "0. Salir" << endl;
	cout << "Opción: ";
	cin >> opcion;

	return opcion;
}

void pedirDatos(tVector A, tVector B) {
	 cout << "Escribe las componentes del vector A: " << endl;
	 for (int i = 0; i < N; i++) {
		 cout << "Componente " <<  i + 1 << " del vector: " << endl;
		 cin >> A[i];
	 }
	  cout << "Escribe las componentes del vector B: " << endl;
	 for (int i = 0; i < N; i++) { 
		 cout << "Componente " <<  i + 1 << " del vector: " << endl;
		 cin >> B[i];
	 }
}

void pedirDatos2(tVector A) {
	 cout << "Escribe las componentes del vector A: " << endl;
	 for (int i = 0; i < N; i++) {
		 cout << "Componente " <<  i + 1 << " del vector: " << endl;
		 cin >> A[i];
	 }
	 
}



void mostrar(tVector vector) {
	cout << "(";
	for(int i = 0; i < N - 1; i++) {
		cout << vector[i] << ", ";
	}
	cout << vector[N - 1] << ")";
}

void suma(tVector vector1, tVector vector2, tVector resultado) {

	for(int i = 0; i < N; i++) {
		resultado[i] = vector1[i] + vector2[i];
	}
	mostrar(vector1);
	cout << " + ";
	mostrar(vector2);
	cout << " = ";
	mostrar(resultado);
}

void resta(tVector vector1, tVector vector2, tVector resultado) {

	for(int i = 0; i < N; i++) {
		resultado[i] = vector1[i] - vector2[i];
	}

	mostrar(vector1);
	cout << " - ";
	mostrar(vector2);
	cout << " = ";
	mostrar(resultado);
}

double modulo(tVector vector) {
	double modulo;
	double suma = 0;

	for(int i = 0; i < N; i++)  {
		suma += vector[i] * vector[i];
	}

	modulo = sqrt(suma);

	return modulo;
}

double producto(tVector vector1, tVector vector2) {
	double escalar = 0;

	for(int i = 0; i < N; i++) {
		escalar += vector1[i] * vector2[i];
	}

	return escalar;
}

void normalizacionVector(tVector vector, tVector resultado) {     
	double modulovector;    
	modulovector = modulo(vector);     
	for (int i = 0; i < N; i++)        
		resultado[i] = vector[i] / modulovector;       
} 

double componenteMayor(tVector vector) {     
	double mayor;    

	if (vector[0] > vector[1]) 
		mayor = vector[0];    
	else 
		mayor = vector[1];    
	if (vector[1] > vector[2])       
		mayor = vector[1];   
	else
		mayor = vector[2];     

	return mayor; 
}

