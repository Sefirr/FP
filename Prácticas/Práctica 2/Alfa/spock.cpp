// Juego Rock-Paper-Scissor-Lizzard-Spock
// Hecho por Javier Villarreal Rodríguez
#include <iostream>
#include <string>
using namespace std;
#include <cstdlib>
#include <ctime>

int main() {
	srand(time(NULL));
	
	system("chcp 1252");
	
	//Definimos tipo enumerado
	typedef enum {piedra, papel, lagarto, tijeras, spock} tElemento;
	
	//Variables del tipo definido por el usuario
	tElemento eleccionComputadora, eleccionJugador;

	//Variable necesaria para ejecutar rand() % 5 para decidir la elección de la máquina
	int NumelementoComputadora;

	//Variables necesarias para mostrar en una cadena de texto la eleccion de la máquina y la elección del jugador
	string elementoJugador, elementoComputadora;

	//Es necesario que se inicialicen a 0 para que las estadísticas funcionen correctamente ya que utilizan operadores monarios
	int empatesSpock = 0;
	int perdidasSpock = 0;
	int ganadasSpock = 0;
	int partidasSpock;

	bool elementoCorrecto;
	bool computadoragana;
	
	cout << "----------------------------------------" << endl;
	cout << "|          BIENVENIDO AL JUEGO          | " << endl;
	cout << "|    ROCK-PAPER-SCISSORS-LIZZARD-SPOCK  | " << endl;
	cout << "----------------------------------------" << endl;
	
	NumelementoComputadora = rand() % 5; // Elección máquina en tipo entero
			
			//Conversión del elemento de computadora de tipo entero a cadena de texto y así, mostrarlo en pantalla.
			//Además de darle valor a la variable enumerada para poder utilizarla en el switch y hacerla más legible en el código.
			if(NumelementoComputadora == 0)
			{
				elementoComputadora = "piedra";
				eleccionComputadora = piedra;
			}
			if(NumelementoComputadora == 1) 
			{
				elementoComputadora = "papel"; 
				eleccionComputadora = papel;
			}
			if(NumelementoComputadora == 2) 
			{
				elementoComputadora = "lagarto";
				eleccionComputadora = lagarto;
			}
			if(NumelementoComputadora == 3) 
			{
				elementoComputadora = "tijeras";
				eleccionComputadora = tijeras;
			}
			if(NumelementoComputadora == 4)
			{
				elementoComputadora = "spock";
				eleccionComputadora  = spock;
			}
			
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
			if (eleccionJugador != eleccionComputadora) {
				
				computadoragana = false;
				
				// sistema de eleccion de partidas. si gana la computadora, el booleano se pone a true, sino gana el jugador.
				switch (eleccionJugador) {				
				// Elemento - caso piedra
				case piedra:
					if (eleccionComputadora == papel || eleccionComputadora == spock) 
						computadoragana = true;
					break;
				// Elemento - caso papel
				case papel:
					if (eleccionComputadora == tijeras || eleccionComputadora == lagarto)
						computadoragana = true;
					break;
				// Elemento - caso tijeras
				case tijeras:
					if (eleccionComputadora == piedra || eleccionComputadora == spock)
						computadoragana = true;
					break;
				// Elemento - caso lagarto
				case lagarto:
					if (eleccionComputadora == piedra || eleccionComputadora == tijeras)
						computadoragana = true;
					break;
				// Elemento - caso spock
				case spock:
					if (eleccionComputadora == papel || eleccionComputadora == lagarto)
						computadoragana = true;
					break;
				}

				if (computadoragana) // Gana computadora
				{
					cout << "Gano yo!" << endl; 
					perdidasSpock++ ;
				}
				else // Gana jugador
				{
					cout << "Tú ganas!" << endl;
					ganadasSpock++ ;
				}
			}
			else //Empate
			{
				cout << "Empate!" << endl;
				empatesSpock++ ;
			}

		return 0;
}