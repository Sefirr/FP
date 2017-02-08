//Práctica 3
// Hecha por Javier Villarreal Rodríguez y Jorte Utrilla Olivera - Grupo 23
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
typedef int tContador[NB];

//Protótipos
/*La funcion entera menu representa al menu del juego, la cual tiene 3 parametros pasados por referencia ya que:
- El parámetro juego es modificado para incrementar los turnos(juego.turnos) y para devolver el ultimo movimiento realizado(juego.ult_movimiento). 
- El parámetro direccion devuelve la direccion en la que se quiere girar el tablero y, que por tanto, debe ser modificado en cada turno para que las bolas se desplazen.
- El parámetro terminado  debe ser modificado para que el juego termine una vez entre una bola en un agujero.*/
int menu(tJuego &juego, tDireccion &direccion, bool &terminado);
/* El procedimiento inicializar da la direccion del tablero que se quiere cargar y lo guarda en el parametro juego, el cual es modificado (juego.nombre_archivo).*/
void inicializar(tJuego &juego);
/* La función booleana datos_OK comprueba si los datos del tablero son válidos, es por ello que no modifica el parametro. Si es así, devuelte tru y sino false.*/
bool datos_OK(tJuego &juego);
/* La función booleana validarFronteras comprueba que el tablero tenga fronteras, es decir, que halla bordes a los lados del tablero. Si es asi, devuelve true y sino false.
Al comprobar solo, no está modificando el parametro. */
bool validarFronteras(tJuego juego);
/* La función booleana cargar llama a las funciones datos_OK y validarFronteras, y, en función de lo q le devuelvan esas funciones, determina si hay un error en el tablero o no.
Y al pasarla a main, notifica el error en caso de que exista.*/
bool cargar(tJuego &juego);
/* El procedimiento mostrarTablero, muestra el tablero y codifica los valores del tablero, para que el tablero sea apto para jugar. Es por ello, que el parametro juego, no lo modifica, 
ya que solo muestra. */
void mostrarTablero(const tJuego juego);
/*La función booleana valida, valida las casillas del tablero para determinar si la bola puede avanzar o no. Los parametros que tiene son los siguientes:
- El parámetro juego no se modifica porque simplemente esta haciendo una comprobacion para saber si se puede avanzar a esa casilla o no.
- Los parámetros fila y columna simplemente sirven para que la casilla del tablero sea perfectamente identificida, por así decirlo. De manera, que se pueda
determinar si se puede avanzar a esa casilla o no.*/
bool valida(tJuego juego, int fila, int columna);
/* El procedimiento inclinaTablero inclina el tablero en la direccion indicada para que las bolas puedan ser desplazadas. Los parámetros que tiene son los siguientes:
- El parámetro juego, es modificado ya que las funciones a las que se llaman dentro de esta funcion modifican el parámetro, permitiendo así que la bola pueda desplazarse correctamente.
- El parámetro direccion, no se modifica ya que la direccion ya ha sido dada en el menu, simplemente permite que las bolas se desplazen en el lugar indicado.
- El parametro terminado indica cuando una bola entra en el agujero. Cuando entra, el parametro es modificaso. Si entra una bola en un agujero da true y sino, permanece en false.
*/
void inclinaTablero(tJuego &juego, tDireccion direccion, bool &terminado);
/* Los procedimientos desplazarArriba, desplazarAbajo etc. cumplen la misma función, es decir, mueven la bola en la direccion indicada por el usuario.
Por tanto, procederé a explicarlas como si fueran una sola.
Los parámetros que tiene son los siguientes:
- El parámetro juego es modificado ya que la función mueve la bola en la dirección indicada por el usuario, por ello son llamadas en inclinaTablero.
Además, guarda el valor de la bola en una variable auxiliar. Para que una vez despues de ser ejecutada la funcion desplazaBola, que veremos más
adelante, la bola se desplace, borrando la bola de sus posiciones anteriores para crear la sensación de movimiento(en el desplazaBola).
- El parámetro aux es modificado ya que debemos de mover más de una. Por lo tanto, para que se puedan desplazar todas las bolas es necesario modificarlo.
- Los parámetros fila y columna son modifacion en función de la direccion modificada para que los bucles encuentren las bolas, llamen a la función desplazaBola 
y la bola pueda ser desplazada.*/
void desplazarArriba(tJuego &juego, int &aux, int &fila, int &columna, tDireccion direccion, bool &terminado);
void desplazarAbajo(tJuego &juego, int &aux, int &fila, int &columna, tDireccion direccion, bool &terminado);
void desplazarIzquierda(tJuego &juego, int &aux, int &fila, int &columna, tDireccion direccion, bool &terminado);
void desplazarDrcha(tJuego &juego, int &aux, int &fila, int &columna, tDireccion direccion, bool &terminado);
/* El procedimiento desplazaBola modifica los valores de fila y columna en la direccion indicada hasta que llega una casilla del tablero a la que
no se puede acceder(bola o pared). Además, borra la bola de las posiciones anteriores. Los parámetros que tiene son los siguientes:
- El parámetro juego es modificado ya que modifica el array bidimentsional tablero.
- Los parámetros fila y columna, como ya dije son modificados, para permitir el desplazamiento de las bolas.
- El parámetro direccion no es modifcado ya que la dirección es dada por el usuario y no debe ser modificada, hasta que, nuevamente, el usuario
indique una direccion diferente en el turno siguiente.*/
void desplazaBola(tJuego &juego, int &fila, int &columna, tDireccion direccion);
/* La funcion cadena codifica el ultimo movimiento que ha hecho el usuario para que pueda ser visto por el usuario. Una vez, finalizado el turno
y comenzado el siguiente. El parámetro juego no es modificado, ya que en base al ultimo movimiento realizado por el usuario, lo unico que hace
es codificarlo en una variable, que posteriormente, será devuelta para que el usuario entienda el ultimo movimiento y no se muestro con un número
debido a que juego. ult_movimiento es de tipo tDireccion(enumerado). */
string Cadena(tJuego juego);

int main() {

	bool error;
	int opcion= -1;
	tJuego juego;
	tDireccion direccion;
	bool terminado = false;

	inicializar(juego);
	error = cargar(juego);

	if(!error) { 
		while(!terminado && (opcion != 0)) {
			cout << "Turno: " << juego.turnos << endl;
			cout << "Ultimo movimiento: " << Cadena(juego) << endl;
			mostrarTablero(juego);
			opcion = menu(juego, direccion, terminado);
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

	juego.ult_movimiento = NULO;

}

int menu(tJuego &juego, tDireccion &direccion, bool &terminado) {

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
	case 1: 
		direccion = DERECHA;
		inclinaTablero(juego, DERECHA, terminado);
		juego.turnos++;
		break;
	case 2: 
		direccion = ARRIBA;
		inclinaTablero(juego, ARRIBA, terminado);
		juego.turnos++;
		break;
	case 3: 
		direccion = IZQUIERDA;
		inclinaTablero(juego, IZQUIERDA, terminado);
		juego.turnos++;
		break;
	case 4: 
		direccion = ABAJO;
		inclinaTablero(juego, ABAJO, terminado);
		juego.turnos++;
		break;
	case 5: 
		direccion = NULO;
		cargar(juego);
		break;
	case 6: 
		direccion = NULO;
		inicializar(juego);
		cargar(juego);
		break;
	}

	juego.ult_movimiento = direccion;

	return opcion;
}

bool datos_OK(tJuego &juego) {

	bool datos = false;
	int dato;
	int fila, columna;
	ifstream entrada;

	entrada.open(juego.nombre_archivo);
	entrada >> juego.num_bolas;

	if(juego.num_bolas <= NB) {
		fila = 0;
		while((fila < DIM) && !datos) {
			columna = 0;
			while((columna < DIM) && !datos) {
				entrada >> dato;
				if(dato >= AGUJERO && dato <= juego.num_bolas - 1) {
					juego.tablero[fila][columna] = dato;
					columna++;
				}
				else
					datos = true;
			}
			if(!datos)
				fila++;
		}
	}
	return datos;
}

bool validarFronteras(tJuego juego) {
	bool comprobar_fronteras = false;

	for(int k = 0; k < DIM; k++) {
		// Comprobar los bordes del tablero para ver si el tablero es apto para jugar.
		if((juego.tablero[0][k] == PARED) && (juego.tablero[DIM - 1][k] == PARED) && (juego.tablero[k][0] == PARED) && (juego.tablero[k][DIM - 1] == PARED))
			comprobar_fronteras = false;
		else
			comprobar_fronteras = true;
	}

	return comprobar_fronteras;
}

bool cargar(tJuego &juego) {

	tBolasMarcadas bolas;
	tContador contador;
	bool error = false; 
	juego.turnos = 0;

	bool datos = datos_OK(juego);
	bool fronteras = validarFronteras(juego);
	error = (datos && fronteras);

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

	int fila, columna;
	int aux;


	switch(direccion) {
	case DERECHA: desplazarDrcha(juego, aux, fila, columna, direccion, terminado);
		break;
	case ARRIBA: desplazarArriba(juego, aux, fila, columna, direccion, terminado);
		break;
	case IZQUIERDA: desplazarIzquierda(juego, aux, fila, columna, direccion, terminado);
		break;
	case ABAJO: desplazarAbajo(juego, aux, fila, columna, direccion, terminado);
		break;
	}

}

bool valida(tJuego juego, int fila, int columna) {
	bool resultado = true;   /* Se supone inicialmente valida */

	/* Controla si la posicion es pared o bola */
	if (juego.tablero[fila][columna] == PARED )
		resultado = false;
	if(juego.tablero[fila][columna] >= 0)
		resultado = false;

	return resultado;
}

void desplazarArriba(tJuego &juego, int &aux, int &fila, int &columna, tDireccion direccion, bool &terminado) {
	fila = 0;
	while((fila < DIM) && !terminado) {
		columna = 0;
		while((columna < DIM) && !terminado) {
			if(juego.tablero[fila][columna] >= 0) {
				aux = juego.tablero[fila][columna];
				while(valida(juego, fila - 1, columna) && !terminado) {
					desplazaBola(juego, fila, columna, direccion);
					if(juego.tablero[fila][columna] == LIBRE) 
						juego.tablero[fila][columna] = aux;
					else if(juego.tablero[fila][columna] == AGUJERO && juego.tablero[fila - 1][columna] == PARED)
						terminado = true;
					else if(juego.tablero[fila][columna] == AGUJERO && juego.tablero[fila - 1][columna] == LIBRE) {
						fila--;
						juego.tablero[fila][columna] = aux;
					}
				}

			}
			columna++;
		}
		fila++;
	}
}

void desplazarAbajo(tJuego &juego, int &aux, int &fila, int &columna, tDireccion direccion, bool &terminado) {
	fila = DIM - 1;
	while((fila >= 0) && !terminado)  {
		columna = 0;
		while((columna < DIM) && !terminado) {
			if(juego.tablero[fila][columna] >= 0) {
				aux = juego.tablero[fila][columna];
				while(valida(juego, fila + 1, columna) && !terminado) {
					desplazaBola(juego, fila, columna, direccion);
					if(juego.tablero[fila][columna] == LIBRE) 
						juego.tablero[fila][columna] = aux;
					else if(juego.tablero[fila][columna] == AGUJERO && juego.tablero[fila + 1][columna] == PARED)
						terminado = true;
					else if(juego.tablero[fila][columna] == AGUJERO && juego.tablero[fila + 1][columna] == LIBRE) {
						fila++;
						juego.tablero[fila][columna] = aux;
					}
				}

			}
			columna++;
		}
		fila--;
	}
}

void desplazarIzquierda(tJuego &juego, int &aux, int &fila, int &columna, tDireccion direccion, bool &terminado) {
	columna = 0;
	while((columna < DIM) && !terminado) {
		fila = 0;
		while((fila < DIM) && !terminado) {
			if(juego.tablero[fila][columna] >= 0) {
				aux = juego.tablero[fila][columna];
				while(valida(juego, fila, columna - 1) && !terminado) {
					desplazaBola(juego, fila, columna, direccion);
					if(juego.tablero[fila][columna] == LIBRE) 
						juego.tablero[fila][columna] = aux;	
					else if(juego.tablero[fila][columna] == AGUJERO && juego.tablero[fila][columna - 1] == PARED)
						terminado = true;
					else if(juego.tablero[fila][columna] == AGUJERO && juego.tablero[fila][columna - 1] == LIBRE) {
						fila++;
						juego.tablero[fila][columna] = aux;
					}
				}

			}
			fila++;
		}
		columna++;
	}
}

void desplazarDrcha(tJuego &juego, int &aux, int &fila, int &columna, tDireccion direccion, bool &terminado) {
	columna = DIM - 1;
	while((columna >= 0) && !terminado) {
		fila = 0;
		while((fila < DIM) && !terminado) {
			if(juego.tablero[fila][columna] >= 0) {
				aux = juego.tablero[fila][columna];
				while(valida(juego, fila, columna + 1) && !terminado) {
					desplazaBola(juego, fila, columna, direccion);
					if(juego.tablero[fila][columna] == LIBRE) 
						juego.tablero[fila][columna] = aux;
					else if(juego.tablero[fila][columna] == AGUJERO && juego.tablero[fila][columna + 1] == PARED)
						terminado = true;
					else if(juego.tablero[fila][columna] == AGUJERO && juego.tablero[fila][columna + 1] == LIBRE) {
						columna++;
						juego.tablero[fila][columna] = aux;
					}
				}

			}
			fila++;
		}
		columna--;
	}
}

void desplazaBola(tJuego &juego, int &fila, int &columna, tDireccion direccion) {

	int incrFila, incrColumna;

	juego.tablero[fila][columna] = LIBRE;

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
		incrFila = 0;
		incrColumna = 1;
		break;
	}

	fila = fila + incrFila;
	columna = columna + incrColumna;  
}

string Cadena(tJuego juego) {

	string cadena;

	switch(juego.ult_movimiento) {
	case NULO: cadena = " NULO";
		break;
	case ARRIBA: cadena = " ARRIBA";
		break;
	case ABAJO: cadena = " ABAJO";
		break;
	case IZQUIERDA: cadena  = "IZQUIERDA";
		break;
	case DERECHA: cadena = " DERECHA";
		break;
	}

	return cadena;
}