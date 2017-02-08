//////////////////////////////////////////////////////////////////////////////////////
//																					//
//  Grupo 23: Hecho por Javier Villarreal Rodríguez y Jorge Utrilla Olivera			//
//  Implementa un programa que permita realizar operaciones sobre matrices de NxN.	//
//  El programa debe permitir al usuario la selección de alguna de las siguientes	//
//  operaciones:																	//
//  a) Sumar 2 matrices.															//
//  b) Restar 2 matrices.															//
//  c) Multiplicar 2 matrices.														//
//  d) Trasponer una matriz.														//
//  e) Mostrar una matriz señalando cuáles son los puntos de silla (los puntos de	//
//  silla de una matriz son aquellos elementos de la misma que cumplen ser el		//
//  mínimo de su fila y el máximo de su columna).									//
//  Habrá también dos subprogramas para leer del teclado o mostrar en la pantalla	//
//  una matriz.																		//
//																					//
//////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

const int N = 3;
typedef int tMatriz[N][N];

int menu(tMatriz matriz1, tMatriz matriz2, tMatriz resultado);
void leerMatriz(tMatriz matriz);
void mostrarMatriz(const tMatriz matriz);
void suma(tMatriz matriz1, tMatriz matriz2, tMatriz resultado);
void resta(tMatriz matriz1, tMatriz matriz2, tMatriz resultado);
void multiplicacion(tMatriz matriz1, tMatriz matriz2, tMatriz resultado);
void trasponer(tMatriz matriz, tMatriz resultado);
void mostrarPuntoSilla(tMatriz matriz);

int main() {
	tMatriz matriz1, matriz2, resultado;
	int opcion;

	cout << "Componentes de las matrices A: " << endl;
	leerMatriz(matriz1);
	cout << endl;
	cout << "Componentes de las matrices B: " << endl;
	leerMatriz(matriz2);
	cout << endl;

	cout << "Matriz A: " << endl;
	mostrarMatriz(matriz1);
	cout << endl << endl;
	cout << "Matriz B: " << endl;
	mostrarMatriz(matriz2);
	cout << endl << endl;

	opcion = menu(matriz1, matriz2, resultado);

	return 0;
}

int menu(tMatriz matriz1, tMatriz matriz2, tMatriz resultado) {
	int opcion;

	do {
		cout << "1 - Suma de matrices" << endl;
		cout << "2 - Resta de matrices" << endl;
		cout << "3 - Multiplicar matrices" << endl;
		cout << "4 - Trasponer matrices" << endl;
		cout << "5 - Mostrar matrices señalando puntos silla" << endl;
		cout << "Opción: ";
		cin >> opcion;
		cout << endl;

		switch(opcion) {
		case 0: break;
		case 1: 
			// Suma de matrices
			suma(matriz1, matriz2, resultado);
			break;
		case 2: 
			// Resta de matrices
			resta(matriz1, matriz2, resultado);
			break;
		case 3:
			// Multiplicación de matrices
			multiplicacion(matriz1, matriz2,resultado);
			break;
		case 4: 
			//Trasposición
			cout << "Matriz traspuesta de A: " << endl;
			trasponer(matriz1, resultado);
			cout << endl << endl;
			cout << "Matriz traspuesta de B: " << endl;
			trasponer(matriz2, resultado);
			cout << endl << endl;
			break;
		case 5: 
			//Puntos silla
			cout << "Puntos silla de la matriz A: " << endl;
			mostrarPuntoSilla(matriz1);
			cout << endl << endl;
			cout << "Puntos silla de la matriz B: " << endl;
			mostrarPuntoSilla(matriz2);
			cout << endl << endl;
			break;
		default: cout << "Opción no válida" << endl;
		}
		cout << endl;
	} while(opcion != 0);

	return opcion;
}

void leerMatriz(tMatriz matriz) { 
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			cout << "Componente[" << i + 1 << "," << j + 1 << "] = ";
			cin >> matriz[i][j];
		}
	}
}

void mostrarMatriz(const tMatriz matriz) {
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			cout << matriz[i][j] << " ";
		}
		cout << endl;
	}
}

void suma(tMatriz matriz1, tMatriz matriz2, tMatriz resultado) {

	cout << "Resultado de sumar las matrices A y B: " << endl;
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			resultado[i][j] = matriz1[i][j] + matriz2[i][j];

	mostrarMatriz(resultado);
}

void resta(tMatriz matriz1, tMatriz matriz2, tMatriz resultado) {
	cout << "Resultado de restar las matrices A y B: " << endl;
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++) 
			resultado[i][j] = matriz1[i][j] - matriz2[i][j];

	mostrarMatriz(resultado);
}

void multiplicacion(tMatriz matriz1, tMatriz matriz2, tMatriz resultado) {

	cout << "Resultado de multiplicar A por B: " << endl;
	for (int fil = 0; fil < N; fil++) {
		for (int col = 0; col < N; col++) {
			resultado[fil][col] = 0;
			for (int k = 0; k < N - 1;k++) {
				resultado[fil][col] += matriz1[fil][k] * matriz2[k][col];
			}
		}

	}

	mostrarMatriz(resultado);
}

void trasponer(tMatriz matriz, tMatriz resultado) {
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			resultado[i][j] = matriz[j][i];
		}
	}
	mostrarMatriz(resultado);
}

void mostrarPuntoSilla(tMatriz matriz) {
	for(int j = 0; j < N; j++) {
		cout << "Componente[1," << j << "] = " << matriz[1][j] << endl;
	}
}