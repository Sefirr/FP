// Juego Voltear el dado
// Hecho por Javier Villarreal Rodríguez
#include <iostream>
#include <string>
using namespace std;	
#include <cstdlib>
#include <ctime>

int main() {	

	// Puntuacion tras el sorteo, variable necesaria para el sorteo y variable de puntuación.
	int puntuacion, sorteo;
	
	//Cadena de eleccion de punto cardinal que decide el giro y, por tanto, la puntuación por jugada de cada uno.
	string eleccion;
	
	//Tipos enumerados
	typedef enum {norte, sur, este, oeste} tGiro;
	tGiro giro; 
	
	//Eleccion de la computadora trás sorteo
	int eleccionComputadora;
	
	//Caras del dado
	int superior, frontal, lateral;
	
	//Variable necesaria para voltear el dado y hacer el giro correspondiente.
	int aux = 0;
	
	int ganadasVoltear = 0;
	int perdidasVoltear = 0;
	int partidas;
	
	bool turnojugador = false;
	bool turnocomputadora = false;
	bool elementoCorrecto;
	
	srand(time(NULL));
	system("chcp 1252");
	
	// Sorteo jugador - computadora
	sorteo = rand() % 2;

	// Puntuación del ganador elegido en el sorteo
	superior = 1 + rand() % 6;
	
	switch(superior) {
		case 1:
			frontal = 4;
			lateral = 2;
			break;
		case 2:
			frontal = 6;
			lateral = 3;
			break;
		case 3:
			frontal = 6;
			lateral = 5;
			break;		
		case 4:
			frontal = 5;
			lateral = 6;
			break;
		case 5:
				frontal = 6;
				lateral = 4;
				break;
		case 6:
			frontal =  4;
			lateral = 5;
			break;
	}
	
	puntuacion = superior;

	cout << "-----------------------" << endl;
	cout << "|  BIENVENIDO AL JUEGO | " << endl;
	cout << "|    VOLTEAR EL DADO   | " << endl;
	cout << "-----------------------" << endl;
			
	cout << "COMIENZA EL JUEGO... ¿Quién empieza?" << endl << endl;
			
			
	if (sorteo == 0) {
		cout << "Empiezas tú." << endl;
		cout << "Tu tirada ha sido" << endl;
		turnocomputadora = true;
		turnojugador = false;
	}
	else {
		cout << "Empiezo yo." << endl;
		cout << "Mi tirada del dado ha sido" << endl << endl << endl;
		turnojugador = true;
		turnocomputadora = false;
	}
	
	cout << "   __    " << endl;
			cout << " / " << superior << " / | " << endl;
			cout << " -- |" << lateral << " | " << endl;
			cout << "| " << frontal << " | /  " << endl;
			cout << " --	  " << endl;
			
	cout << "Contador = " << puntuacion << endl;
	
					
	do {
		if(turnojugador) {
			elementoCorrecto = false;
		while (elementoCorrecto == false && eleccion != "0") {
				//El usuario introduce su elección en forma de cadena de texto
				cout << endl << endl << "Te toca elegir jugada" << endl << endl << endl;
				cout << "Indica el giro que quieres hacer mediante un punto cardinal (N, S, E, O)" 
				<< " (Si quieres ver las instrucciones pulsa 1. Si quieres terminar pulsa 0.) " << endl;
				cout << "Elección: ";
				getline(cin, eleccion);
				elementoCorrecto = true;
				//Comprobación de que el elemento que ha introducido el usuario es correcto
				if(eleccion != "N") {
				   if(eleccion != "S") {
					  if(eleccion != "E") { 
						 if(eleccion != "O") {
							   elementoCorrecto = false;
							}
						}
					}
			}
		}
			
			turnojugador = false;
			turnocomputadora = true;
		}
		else if(turnocomputadora) {
			cout << endl << "Me toca a mí" << endl;
			cout << "Mi jugada es ";

			eleccionComputadora = rand() % 4;

			if(eleccionComputadora == 0) {
				eleccion = "N";
				cout << "Norte";
			}
			else if (eleccionComputadora == 1) {
					eleccion = "S";
					cout << "Sur";
			}
			else if (eleccionComputadora == 2) {
				eleccion = "E";
				cout << "Este";
			}
			else if (eleccionComputadora == 3) {
				eleccion = "O"; 
				cout << "Oeste";
			}
			
			turnojugador = true;
			turnocomputadora = false;
			}
			cout << endl << endl << endl;	
					
			if(eleccion == "N")
				giro = norte;
			if(eleccion == "S")
				giro = sur;
			if(eleccion == "E")
				giro = este;
			if(eleccion == "O")
				giro = oeste;
				
			// Para hacer los giros, simplemente se sustituyen las variables mediante auxiliares. Y se calculan las caras que faltan gracias a que las caras opuestas suman 7.
			
			if(giro == norte) {
				aux = frontal; 
				frontal = superior;
				superior = 7 - aux;	
			}
			else if(giro == sur) {
				aux = superior;
				superior = frontal;
				frontal = 7 - aux;
				
			}
			else if(giro == este) {
				aux = lateral;
				lateral = superior;
				superior = 7 - aux;
			}
			else if(giro == oeste) {
				aux = superior;
				superior = lateral;
				lateral = 7 - aux;
			}
			

			cout << "   __    " << endl;
			cout << " / " << superior << " / | " << endl;
			cout << " -- |" << lateral << " | " << endl;
			cout << "| " << frontal << " | /  " << endl;
			cout << " --	  " << endl;
			
			puntuacion = puntuacion + superior;


			cout << endl << "Contador = " << puntuacion << endl;
		} while(puntuacion < 50 && eleccion != "0");	
		
		if(!turnojugador) {
			perdidasVoltear++;
			cout << "Has perdido! " << endl;
		}
		else if(!turnocomputadora) {
			ganadasVoltear++;
			cout << "Has ganado! " << endl;
		}
		
	return 0;
}