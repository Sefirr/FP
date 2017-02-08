// Juego Rock-Paper-Scissor-Lizzard-Spock
// Hecho por Javier Villarreal Rodr�guez
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

	//Variable necesaria para ejecutar rand() % 5 para decidir la elecci�n de la m�quina
	int NumelementoComputadora;

	//Variables necesarias para mostrar en una cadena de texto la eleccion de la m�quina y la elecci�n del jugador
	string elementoJugador, elementoComputadora;

	//Es necesario que se inicialicen a 0 para que las estad�sticas funcionen correctamente ya que utilizan operadores monarios
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
	
	NumelementoComputadora = rand() % 5; // Elecci�n m�quina en tipo entero
			
			//Conversi�n del elemento de computadora de tipo entero a cadena de texto y as�, mostrarlo en pantalla.
			//Adem�s de darle valor a la variable enumerada para poder utilizarla en el switch y hacerla m�s legible en el c�digo.
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
					cout << "T� ganas!" << endl;
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