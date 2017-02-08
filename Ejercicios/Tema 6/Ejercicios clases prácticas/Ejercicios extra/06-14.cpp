/*
Ejercicio 06-14
Hecho por Javier Villarreal Rodríguez y Jorge Utrilla Olivera - Grupo 23
____________________________________________________________________________________________________________________________________________
En un archivo de	texto se encuentran	grabados los resultados	correspondientes a unas	elecciones autonómicas.
Cada línea de dicho	archivo	almacena los datos de una comunidad	(máximo 15 comunidades). Éstos son:	
 Número de	la comunidad autónoma.	
 Número de	partidos políticos que han obtenido escaños en el parlamento regional correspondiente (máx.	10 partidos).	
 Por cada uno de los partidos:	
 Nombre (una palabra)	
 Número de	escaños	obtenidos	
Como los nombres de los partidos no pueden tener espacios intermedios nos basta un espacio para separar los	distintos campos:
1 4 Azul 3 Rojo 4 Verde 1 Negro 1
2 3 Rojo 1 Azul 3 Rosa 1
3 5 Negro 2 Azul 3 Rojo 3 Verde 1 Amarillo 1
4 3 Verde 1 Azul 2 Rojo 1
5 4 Rojo 3 Verde 2 Azul 3 Rosa 1
‐1
Escribe	 un	 programa que muestre los nombres de los partidos vencedores en	cada una de	las comunidades autónomas, así como el porcentaje de	 
escaños	obtenidos. En caso de empate se escribirán los nombres de los partidos empatados. 

Anotación: La parte de que salgan los partidos empatados no me sale, pero el resto funciona correctamente.
*/
#include <iostream>
#include <string>
using namespace std;
#include <fstream>

const int MAX_PARTIDOS = 10;
const int N = 10;
const int MAX_COMUNIDADES = 15;

typedef struct {
	string nombre;
	int puntuacion;
} tPartidos;

typedef tPartidos tPartido[MAX_PARTIDOS];

typedef struct {
	int NUM_COMUNIDAD;
	int NUM_PARTIDOS;
	tPartido partido;
} tComunidades;


typedef tComunidades tComunidad[MAX_COMUNIDADES];
typedef bool partido_ganador[N];

void mostrarGanador(int i, tComunidad comunidad, string partido1, string partido2, string resultado);

int main() {
	int NUM_COMUNIDADES;
	tComunidad comunidad;
	string partido1, partido2, resultado;
	ifstream archivo;

	archivo.open("partidos.txt");
	for(int i = 0; i < MAX_COMUNIDADES; i++) {
		archivo >> comunidad[i].NUM_COMUNIDAD;
		archivo >> comunidad[i].NUM_PARTIDOS;
		for(int j = 0; j < comunidad[i].NUM_PARTIDOS; j++){
			archivo >> comunidad[i].partido[j].nombre;
			archivo >> comunidad[i].partido[j].puntuacion;
		}
		cout << endl;
	}

	for(int i = 0; i < 5; i++) {
		mostrarGanador(i, comunidad, partido1, partido2, resultado);
	}

	return 0;
}

void mostrarGanador(int i, tComunidad comunidad, string partido1, string partido2, string resultado) {
	bool vencedor, empate;
	for(int j = 0; j < comunidad[i].NUM_PARTIDOS - 1; j++) {
		//porcentaje = escaños del partido ganador / total_escaños * 100;
		if(comunidad[i].partido[j].puntuacion > comunidad[i].partido[j + 1].puntuacion) {
			resultado = comunidad[i].partido[j].nombre;	
			vencedor = true;

		}
		else if(comunidad[i].partido[j].puntuacion == comunidad[i].partido[j + 1].puntuacion) {
			partido1 = comunidad[i].partido[j].nombre;
			partido2 = comunidad[i].partido[j + 1].nombre;
			empate = true;
		}
	}
		cout << "Comunidad " << comunidad[i].NUM_COMUNIDAD << " = ";
		if(vencedor)
			cout << "Partido vencedor: " << resultado << endl;
		else if(empate)
			cout << "Partidos empatados: " << partido1 << " y " << partido2 << endl;

		

}