//Práctica 3
#include <iostream>
#include <string>
using namespace std;
#include <fstream>

// Dimensión del tablero: DIM x DIM
const int DIM = 20;

// Codificación de las casillas del tablero
const int LIBRE = -1;
const int PARED = -2;
const int AGUJERO = -3;
const int EXITO = -4;

// Las casillas >= 0 son bolas
// Número máximo de bolas
const int NB = 10;

// Codificación de las inclinaciones
typedef enum { DERECHA, ARRIBA, IZQUIERDA, ABAJO, NULO } tDireccion;

// Array bidimensional para un tablero// Array bidimensional para un tablero
typedef int tTablero[DIM][DIM];

// Tipo cadena al estilo C
typedef char tCadena[20];

// Estructura para el juego
typedef struct {
	tTablero tablero;
	int num_bolas;
	string nombre_archivo;
	tDireccion ult_movimiento;
	int turnos;
} tJuego;

// Tipo auxiliar
typedef bool tBolasMarcadas[NB];

//Protótipos
int menu(tJuego &juego, bool &terminado);
void inicializar(tJuego &juego);
bool cargar(tJuego &juego);
void mostrarTablero(const tJuego juego);
void inclinaTablero(tJuego &juego, tDireccion direccion, bool &terminado);
bool valida(tJuego juego, int fila, int columna, bool &terminado);
void desplazaBola(tJuego &juego, int &fila, int &columna, tDireccion direccion, bool terminado);


int main() {

	bool error;
	int opcion= -1;
	bool terminado = false;
	tJuego juego;
	inicializar(juego);
	error = cargar(juego);

	if(!error) { 
		while(!terminado && (opcion != 0)) {
			mostrarTablero(juego);
			opcion = menu(juego, terminado);
		}
	}
	else
		cout << "Error al cargar el juego.";

	if(terminado)
		cout << "Felicidades! Has ganado el juego." << endl;

	return 0;
}

void inicializar(tJuego &juego) {
	cout << "Nombre del laberinto (Intro -> archivo por defecto `lab1.txt`): ";
	cin >> juego.nombre_archivo;
}

int menu(tJuego &juego, bool &terminado) {

	int opcion;

	cout << "1 - Inclinar hacia la derecha" << endl;
	cout << "2 - Inclinar hacia arriba" << endl;
	cout << "3 - Inclinar hacia la izquierda" << endl;
	cout << "4 - Inclinar hacia abajo" << endl;
	cout << "5 - Reiniciar el tablero" << endl;
	cout << "6 - Cargar nuevo tablero" << endl;
	cout << "0 - Salir" << endl;
	cout << "Opción: ";
	cin >> opcion;

	switch(opcion) {
	case 0: break;
	case 1: inclinaTablero(juego, DERECHA, terminado);
		break;
	case 2: inclinaTablero(juego, ARRIBA, terminado);
		break;
	case 3: inclinaTablero(juego, IZQUIERDA, terminado);
		break;
	case 4: inclinaTablero(juego, ABAJO, terminado);
		break;
	case 5: cargar(juego);
		break;
	case 6: inicializar(juego);
			cargar(juego);
			
		break;
	}
	return opcion;
}

bool cargar(tJuego &juego) {

	bool error = false;
	bool datos = false;
	bool comprobar_fronteras = false;
	int dato;
	int fila, columna;
	ifstream entrada;

	entrada.open(juego.nombre_archivo);
	entrada >> juego.num_bolas;

	if(juego.num_bolas <= NB) {
		fila = 0;
		while((fila < DIM) && !error) {
			columna = 0;
			while((columna < DIM) && !error) {
				entrada >> dato;
				if(dato >= AGUJERO && dato <= juego.num_bolas - 1) {
					juego.tablero[fila][columna] = dato;
					columna++;
				}
				else
					datos = true;
			}
			if(!error)
				fila++;
		}

		//FIN COMPROBAR VALORES VALIDOS EN EL TABLERO

		for(int k = 0; k < DIM; k++) {
			// Comprobar los bordes del tablero para ver si el tablero es apto para jugar.
			if((juego.tablero[0][k] == PARED) && (juego.tablero[DIM - 1][k] == PARED) && (juego.tablero[k][0] == PARED) && (juego.tablero[k][DIM - 1] == PARED))
				comprobar_fronteras = false;
			else
				comprobar_fronteras = true;
		}

		//FIN COMPROBAR FRONTERAS
	}

	error = (datos && comprobar_fronteras);

	return error;
}

void mostrarTablero(const tJuego juego) {
	for(int fila = 0; fila < DIM; fila++) {
		for(int columna = 0;  columna < DIM; columna++) {
			if(juego.tablero[fila][columna] == PARED)
				cout << char(219) << char(219) << char(219);
			else if(juego.tablero[fila][columna] == LIBRE)
				cout << "   ";
			else if(juego.tablero[fila][columna] == AGUJERO)
				cout << char(176) << char(176) << char(176);
			else if(juego.tablero[fila][columna] >= 0)
				cout << " " << juego.tablero[fila][columna] << " ";
		}
		cout << endl;
	}
}

void inclinaTablero(tJuego &juego, tDireccion direccion, bool &terminado) {

	int fila, columna, faux, caux;
	int aux, incrFila, incrColumna;


	switch(direccion) {
	case DERECHA: 
		incrFila = 0;
		incrColumna = 1;
		columna = 19; // DIM - 1
		while((columna >= 0) && !terminado) {
			fila = 0;
			while((fila < DIM) && !terminado) {
				if(juego.tablero[fila][columna] >= 0) {
					aux = juego.tablero[fila][columna];
               juego.tablero[fila][columna] = LIBRE;
               caux = columna;
               faux = fila;
               do {
                  faux = faux + incrFila;
                  caux = caux + increColumna;
               } while ((juego.tablero[faux][caux] == LIBRE) || (juego.tablero[faux][caux] == AGUJERO));
               caux--;
               if (juego.tablero[faux][caux] == AGUJERO)
                  terminado = true;
               else
                  juego.tablero[faux][caux] = aux;
				}
				fila++;
			}
			columna--;
		}
		break;
	case ARRIBA: 
		fila = 0;
		while((fila < DIM) && !terminado) {
			columna = 0;
			while((columna < DIM) && !terminado) {
				if(juego.tablero[fila][columna] >= 0) {
					aux = juego.tablero[fila][columna];
					while(valida(juego, fila - 1, columna, terminado) && !terminado) {
						desplazaBola(juego, fila, columna, direccion, terminado);
						juego.tablero[fila][columna] = aux;
					}
				}
				columna++;
			}
			fila++;
		}
		break;
	case IZQUIERDA: 
		columna = 0;
		while((columna < DIM) && !terminado) {
			fila = 0;
			while((fila < DIM) && !terminado) {
				if(juego.tablero[fila][columna] >= 0) {
					aux = juego.tablero[fila][columna];
					while(valida(juego, fila, columna - 1, terminado) && !terminado) {
						desplazaBola(juego, fila, columna, direccion, terminado);
						juego.tablero[fila][columna] = aux;
					}
				}
				fila++;
			}
			columna++;
		}
		break;
	case ABAJO:
		fila = 19;
		while((fila >= 0) && !terminado)  {
			columna = 0;
			while((columna < DIM) && !terminado) {
				if(juego.tablero[fila][columna] >= 0) {
					aux = juego.tablero[fila][columna];
					
					while(valida(juego, fila + 1, columna, terminado) && !terminado) {
						desplazaBola(juego, fila, columna, direccion, terminado);
						juego.tablero[fila][columna] = aux;
					}
				}
				columna++;
			}
			fila--;
		}
		break;


	}
}

bool valida(tJuego juego, int fila, int columna, bool &terminado) {
   bool resultado = true;   /* Se supone inicialmente valida */
    
   /* Controla si la posicion es pared o bola */
   if (juego.tablero[fila][columna] == PARED )
      resultado = false;
   if(juego.tablero[fila][columna] >= 0)
	   resultado = false;

   if(!resultado && juego.tablero[fila][columna] == AGUJERO)
	   terminado = true;
   
   return resultado;
}

void desplazaBola(tJuego juego, int &fila, int &columna, tDireccion direccion, bool terminado) {
	
	int incrFila, incrColumna;

	// juego.tablero[fila][columna] = LIBRE;

	switch (direccion) {
	case ARRIBA:
		incrFila = -1; 
		incrColumna = 0;
		break;
	case ABAJO:
		incrFila = 1; 
		incrColumna = 0;
		break;
	case IZQUIERDA:
		incrFila = 0; 
		incrColumna = -1;
		break;
	case DERECHA:
		break;
	}

	fila = fila + incrFila;
	columna = columna + incrColumna;
   
}