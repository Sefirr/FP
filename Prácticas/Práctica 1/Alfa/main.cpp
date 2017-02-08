//Pr�ctica 1 - Versi�n Alfa
//Hecha por Javier Villarreal Rodr�guez y Jorge Utrilla Olivera
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

	//Variable necesaria para ejecutar rand() % 5 para decidir la elecci�n de la m�quina
	int NumelementoComputadora;

	//Variables necesarias para mostrar en una cadena de texto la eleccion de la m�quina y la elecci�n del jugador
	string elementoJugador, elementoComputadora;

	//Es necesario que se inicialicen a 0 para que las estad�sticas funcionen correctamente ya que utilizan operadores monarios
	int empates = 0;
	int perdidas = 0;
	int ganadas = 0;
	int partidas;

	int opcion = -1; //Necesario para forzar a entrar nuevamente en el men� cada vez que se selecciona una opcion y �sta termina.
   
	bool elementoCorrecto;
	
	while(opcion != 0){

		cout << endl << "1. Jugar" << endl;
		cout << "0. Salir" << endl;
		cout << "Elige una opci�n: ";
		cin >> opcion;

		if(opcion == 1) {

			NumelementoComputadora = rand() % 5; // Elecci�n m�quina en tipo entero
			
			//Conversi�n del elemento de computadora de tipo entero a cadena de texto y as�, mostrarlo en pantalla
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
				//El usuario introduce su elecci�n en forma de cadena de texto
				cout << "Elementos(Piedra, Papel, Tijeras, lagarto, Spock): ";
				cin >> elementoJugador;
				elementoCorrecto = true;
				//Comprobaci�n de que el elemento que ha introducido el usuario es correcto
				if(elementoJugador != "piedra") {
				   if(elementoJugador != "papel") {
					  if(elementoJugador != "tijeras") { 
						 if(elementoJugador != "lagarto")
							if(elementoJugador != "spock") {
							   elementoCorrecto = false;
							   cout << "Elemento desconocido. Int�ntelo de nuevo." << endl;
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
			
			//Elecci�n de la m�quina y del usuario
			cout << "Tu elecci�n: " << elementoJugador << endl;
			cout << "Mi elecci�n: " << elementoComputadora << endl;
			
			cout << "........." << endl;
			//Casos posibles
			switch (NumelementoComputadora) {
			//Elemento - caso piedra
			case 0: 
				if(eleccionJugador == papel || eleccionJugador == spock){
				cout << "T� ganas!" << endl;
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
				cout << "T� Ganas!" << endl;
				ganadas++;
				}
				
				break;
			
			//Elemento - caso lagarto
			case 2: 
				if(eleccionJugador == piedra || eleccionJugador == tijeras){
				cout << "T� Ganas!" << endl;
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
				cout << "T� ganas!" << endl;
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
				cout << "T� ganas!" << endl;
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
		
		//Estad�sticas
		if(opcion == 0){		
			partidas = ganadas + perdidas + empates;
			cout << endl << "Estad�sticas " << endl;
			cout << "Partidas jugadas: " << partidas << endl;
			cout << "Partidas ganadas: " << ganadas << endl;
			cout << "Partidas perdidas: " << perdidas << endl;
			cout << "Empates: " << empates << endl;			
			}
			
	}
	
	return 0;

}