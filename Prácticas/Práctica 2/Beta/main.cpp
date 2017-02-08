#include <iostream>
#include <string>
using namespace std;
#include <cstdlib>
#include <fstream>
#include <ctime>

// Prototipos
int menu();
int registro();
void ins_spock();
void ins_voltear();
void juegospock(int &perdidasSpock, int &ganadasSpock, int &empatesSpock);
void volteardado( int &perdidasVoltear, int &ganadasVoltear);

int main()
{

	int opcion = -1; //Necesario para forzar a entrar nuevamente en el men� cada vez que se selecciona una opcion y �sta termina.
	int fallos;

	int ganadasSpock = 0;
	int perdidasSpock = 0;
	int empatesSpock = 0;

	int perdidasVoltear = 0;
	int ganadasVoltear = 0;

	int partidasSpock;
	int partidasVoltear;
	
	
	srand(time(NULL));

	system("chcp 1252");
	
	fallos = registro();
	
	while (opcion != 0 && fallos < 2) {
		opcion = menu();		
		switch (opcion) {
			case 0: 
			//Opci�n 0 - Estad�sticas
			partidasSpock = ganadasSpock + perdidasSpock + empatesSpock;
			cout << endl << "Estad�sticas de  Rock-Paper-Scissors-Lizzard-Spock " << endl;
			cout << "Partidas jugadas: " << partidasSpock << endl;
			cout << "Partidas ganadas: " << ganadasSpock << endl;
			cout << "Partidas perdidas: " << perdidasSpock << endl;
			cout << "Partidas empatadas: " << empatesSpock << endl;	
			
			partidasVoltear = ganadasVoltear + perdidasVoltear;
			cout << endl << "Estad�sticas de Voltear el dado " << endl;
			cout << "Partidas jugadas: " << partidasVoltear << endl;
			cout << "Partidas ganadas: " << ganadasVoltear << endl;
			cout << "Partidas perdidas: " << perdidasVoltear << endl;	

			break;
			
			case 1: 
				// Opci�n 1 - Intrucciones de Rock-Paper-Lizzard-Spock
				ins_spock();
			break;
			
			
			case 2: 
				// Opci�n 2 - Juego Rock-Paper-Lizzard-Spock
				juegospock(perdidasSpock, ganadasSpock, empatesSpock);
					
			break;
			
			case 3: 
				//Opci�n 3 - Instrucciones de Voltear el dado
				ins_voltear();
			break;

			case 4:
				// Opci�n 4 - Juego Voltear el dado
				volteardado(perdidasVoltear, ganadasVoltear);

			break;
			default: cout << "Opci�n no v�lida";
		
			cout << endl;
		}
	}

	return 0;
}

int menu()
{
	int opcion;
	cout << "-------------------------------------" << endl;
	cout << "BIENVENIDO AL PORTAL DE JUEGOS	  " << endl;
	cout << "-------------------------------------" << endl << endl;
	cout << "Elige lo que quieres hacer: " << endl;
	cout << "1. Ver instrucciones de Rock-Paper-Scissors-Lizard-Spock" << endl;
	cout << "2. Jugar a Rock-Paper-Scissors-Lizard-Spock" << endl;
	cout << "3. Ver instrucciones de Voltear el dado" << endl;
	cout << "4. Jugar a Voltear el dado" << endl;
	cout << "0. Salir" << endl;
	cout << "Opci�n: ";
	cin >> opcion;
	
	return opcion;
}

int registro() {
	
	string usuario, cont, contrasena1, nombre1;
	
	int intentos = 0, intrest = 2; 
	
	ifstream registro, reglas;
	ofstream temporal;
	
	bool encontrado = false;
	bool usuarioOK = false;
	bool usuarioOK2 = true;
	bool contraOK = false;


	srand(unsigned(time(NULL)));

	//Logueo de usuarios y registro, si el usuario no est� registrado
	cout << "Por favor, introduce tu apodo: ";
	cin >> nombre1;
	cout << "Contrase�a: ";
	cin >> contrasena1;	

	registro.open("registro.txt");
	
	if (!registro.is_open())
		cout << "Error: No encuentro registro.txt!" << endl;
	else {
		registro >> usuario;

		while ((usuario != "XXX") && !encontrado) {
				registro >> cont;

			if (nombre1 == usuario) {
				encontrado = true;
			}
			else if (nombre1 != usuario) 
				registro >> usuario;
		}
		
		registro.close();
		
		if (encontrado) {
			usuarioOK = true;
			while ((intentos < 2) && (contrasena1 != cont) ) {
				cout << endl;
				cout << "Contrase�a no v�lida. Vuelve a introducirla ( quedan "<< intrest << " intentos): " ;
				cin >> contrasena1;
				intentos++;
				intrest--;
				usuarioOK = (contrasena1 == cont);
			}
			if (intrest == 0 && usuarioOK == false) {
				cout << endl;
				cout << "Has fallado demasiadas veces, no puedes jugar!!" << endl;
				usuarioOK2 = false;
			}
		}	
		else if (!encontrado) {
			usuarioOK = true;
			registro.open("registro.txt"); //apertura 
			temporal.open("tmp.txt");
			
			registro >> usuario;
			registro >> cont;
			
			while (usuario != "XXX" && cont != "XXX") {
				temporal << usuario << endl;
				temporal << cont << endl;
				registro >> usuario;
				registro >> cont;
				
			}
			
			temporal << "XXX";
			registro.close();  // Cierre del archivo
			temporal.close();

			registro.open("tmp.txt"); 
			temporal.open("registro.txt");
			
			registro >> usuario;
			registro >> cont;
			while (usuario != "XXX" && cont != "XXX") {
			temporal << usuario << endl;
			temporal << cont << endl;
			registro >> usuario;
			registro >> cont;
			}
			temporal << nombre1 << endl << contrasena1 << endl << "XXX";
			
			registro.close();
			temporal.close();
		}
	}
	
	return intentos;
}

void ins_spock() {

	string reglas;
	ifstream lectura;

	lectura.open("reglasSpock.txt");
	getline(lectura, reglas);
		while(reglas != "XXX") {
			cout << reglas << endl;
			getline(lectura, reglas);
		}
	cout << endl << endl;
	
	lectura.close();
}
	
void ins_voltear() {

	string reglas;
	ifstream lectura;

	lectura.open("reglasVoltear.txt");
	getline(lectura, reglas);
		while(reglas != "XXX") {
			cout << reglas << endl;
			getline(lectura, reglas);
		}
	cout << endl << endl;
	
	lectura.close();
}

void juegospock(int &perdidasSpock, int &ganadasSpock, int &empatesSpock) {
	//Definimos tipo enumerado
	typedef enum {piedra, papel, lagarto, tijeras, spock} tElemento;
	
	//Variables del tipo definido por el usuario
	tElemento eleccionComputadora, eleccionJugador;

	//Variable necesaria para ejecutar rand() % 5 para decidir la elecci�n de la m�quina
	int NumelementoComputadora;

	//Variables necesarias para mostrar en una cadena de texto la eleccion de la m�quina y la elecci�n del jugador
	string elementoJugador, elementoComputadora;

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
}

void volteardado( int &perdidasVoltear, int &ganadasVoltear) {	
	// Puntuacion tras el sorteo, variable necesaria para el sorteo y variable de puntuaci�n.
	int puntuacion, sorteo;
	
	//Cadena de eleccion de punto cardinal que decide el giro y, por tanto, la puntuaci�n por jugada de cada uno.
	string eleccion;
	
	//Tipos enumerados
	typedef enum {norte, sur, este, oeste} tGiro;
	tGiro giro; 
	
	//Eleccion de la computadora tr�s sorteo
	int eleccionComputadora;
	
	//Caras del dado
	int superior, frontal, lateral;
	
	//Variable necesaria para voltear el dado y hacer el giro correspondiente.
	int aux = 0;
	
	bool turnojugador = false;
	bool turnocomputadora = false;
	bool elementoCorrecto;
	
	srand(time(NULL));
	system("chcp 1252");
	
	// Sorteo jugador - computadora
	sorteo = rand() % 2;

	// Puntuaci�n del ganador elegido en el sorteo
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
			
	cout << "COMIENZA EL JUEGO... �Qui�n empieza?" << endl << endl;
			
			
	if (sorteo == 0) {
		cout << "Empiezas t�." << endl;
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
				//El usuario introduce su elecci�n en forma de cadena de texto
				cout << endl << endl << "Te toca elegir jugada" << endl << endl << endl;
				cout << "Indica el giro que quieres hacer mediante un punto cardinal (N, S, E, O)" 
				<< " (Si quieres ver las instrucciones pulsa 1. Si quieres terminar pulsa 0.) " << endl;
				cout << "Elecci�n: ";
				getline(cin, eleccion);
				elementoCorrecto = true;
				//Comprobaci�n de que el elemento que ha introducido el usuario es correcto
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
			cout << endl << "Me toca a m�" << endl;
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
}
