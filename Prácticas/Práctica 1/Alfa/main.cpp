//Práctica 1 - Versión Alfa
//Hecha por Javier Villarreal Rodríguez y Jorge Utrilla Olivera
#include <iostream>
#include <string>
using namespace std;
#include <cstdlib>
#include <ctime>

int main() 
{
	srand(time(NULL));

	//Definimos tipo enumerado
	typedef enum {piedra, papel, lagarto, tijeras, spock} tElemento;
	
	//Variables del tipo definido por el usuario
	tElemento eleccionJugador;

	//Variable necesaria para ejecutar rand() % 5 para decidir la elección de la máquina
	int NumelementoComputadora;

	//Variables necesarias para mostrar en una cadena de texto la eleccion de la máquina y la elección del jugador
	string elementoJugador, elementoComputadora;

	//Es necesario que se inicialicen a 0 para que las estadísticas funcionen correctamente ya que utilizan operadores monarios
	int empates = 0;
	int perdidas = 0;
	int ganadas = 0;
	int partidas;

	int opcion = -1; //Necesario para forzar a entrar nuevamente en el menú cada vez que se selecciona una opcion y ésta termina.
   
	bool elementoCorrecto;
	
	while(opcion != 0){

		cout << endl << "1. Jugar" << endl;
		cout << "0. Salir" << endl;
		cout << "Elige una opción: ";
		cin >> opcion;

		if(opcion == 1) {

			NumelementoComputadora = rand() % 5; // Elección máquina en tipo entero
			
			//Conversión del elemento de computadora de tipo entero a cadena de texto y así, mostrarlo en pantalla
			if(NumelementoComputadora == 0)  
				elementoComputadora = "piedra"; 
			if(NumelementoComputadora == 1) 
				elementoComputadora = "papel"; 
			if(NumelementoComputadora == 2) 
				elementoComputadora = "lagarto";
			if(NumelementoComputadora == 3) 
				elementoComputadora = "tijeras";
			if(NumelementoComputadora == 4) 	 
				elementoComputadora = "spock";
			
			elementoCorrecto = false;
			while (elementoCorrecto == false) {
				//El usuario introduce su elección en forma de cadena de texto
				cout << "Elementos(Piedra, Papel, Tijeras, lagarto, Spock): ";
				cin >> elementoJugador;
				elementoCorrecto = true;
				//Comprobación de que el elemento que ha introducido el usuario es correcto
				if(elementoJugador != "piedra") {
				   if(elementoJugador != "papel") {
					  if(elementoJugador != "tijeras") { 
						 if(elementoJugador != "lagarto")
							if(elementoJugador != "spock") {
							   elementoCorrecto = false;
							   cout << "Elemento desconocido. Inténtelo de nuevo." << endl;
								}
							}
						}
					}
			 }
			
			//Si el elemento introducido por el usuario es correcto, se realiza la conversion de cadena de texto al tipo enumerado
			if(elementoJugador == "piedra")  eleccionJugador = piedra; 
			if(elementoJugador == "papel") 	 eleccionJugador = papel; 
			if(elementoJugador == "lagarto") eleccionJugador = lagarto;
			if(elementoJugador == "tijeras") eleccionJugador = tijeras;
			if(elementoJugador == "spock") 	 eleccionJugador = spock;
			
			//Elección de la máquina y del usuario
			cout << "Tu elección: " << elementoJugador << endl;
			cout << "Mi elección: " << elementoComputadora << endl;
			
			cout << "........." << endl;
			//Casos posibles
			switch (NumelementoComputadora) {
			//Elemento - caso piedra
			case 0: 
				if(eleccionJugador == papel || eleccionJugador == spock){
				cout << "Tú ganas!" << endl;
				ganadas++;
				}
				if(eleccionJugador == lagarto || eleccionJugador == tijeras){
				cout << "Gano yo!" << endl;
				perdidas++;
				}
				
				break;
			
			//Elemento - caso papel
			case 1: 
				if(eleccionJugador == piedra || eleccionJugador == spock){
				cout << "Gano yo!" << endl;
				perdidas++;
				if(eleccionJugador == lagarto || eleccionJugador == tijeras){
				cout << "Tú Ganas!" << endl;
				ganadas++;
				}
				
				break;
			
			//Elemento - caso lagarto
			case 2: 
				if(eleccionJugador == piedra || eleccionJugador == tijeras){
				cout << "Tú Ganas!" << endl;
				ganadas++;
				}
				if(eleccionJugador == papel || eleccionJugador == spock){
				cout << "Gano yo!" << endl;
				perdidas++;
				}
				
				break;
			
			//Elemento - caso tijeras	
			case 3: 
				if(eleccionJugador == piedra || eleccionJugador == spock){
				cout << "Tú ganas!" << endl;
				ganadas++;
				}
				if(eleccionJugador == papel || eleccionJugador == lagarto){
				cout << "Gano yo!" << endl;
				perdidas++;
				}
				
				break;
			
			//Elemento - caso spock
			case 4: 
				if(eleccionJugador == piedra || eleccionJugador == tijeras){
				cout << "Gano yo!" << endl;
				perdidas++;
				}
				if(eleccionJugador == papel || eleccionJugador == lagarto){
				cout << "Tú ganas!" << endl;
				ganadas++;
				}
				
				break;
			}

			//Elementos iguales
			if(NumelementoComputadora == eleccionJugador){
				cout << "........." << endl << "Empate! " << endl;
				empates++;
			}
						
			}
		}
		
		//Estadísticas
		if(opcion == 0){		
			partidas = ganadas + perdidas + empates;
			cout << endl << "Estadísticas " << endl;
			cout << "Partidas jugadas: " << partidas << endl;
			cout << "Partidas ganadas: " << ganadas << endl;
			cout << "Partidas perdidas: " << perdidas << endl;
			cout << "Empates: " << empates << endl;			
			}
			
	}
	
	return 0;

}