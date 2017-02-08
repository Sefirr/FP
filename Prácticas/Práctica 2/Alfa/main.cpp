#include <iostream>
#include <string>
using namespace std;
#include <cstdlib>
#include <fstream>
#include <ctime>

// Prototipos
int menu();
int registro();

int main()
{

	int opcion = -1; //Necesario para forzar a entrar nuevamente en el menú cada vez que se selecciona una opcion y ésta termina.
	int fallos;

	srand(time(NULL));

	system("chcp 1252");
	
	fallos = registro();
	
	while (opcion != 0 && fallos < 2) {
		opcion = menu();		
		switch (opcion) {
			case 0: // Opción 0 - Estadísticas
			break;
			case 1: // Opción 1 - Intrucciones de Rock-Paper-Lizzard-Spock
			break;
			case 2: // Opción 2 - Juego Rock-Paper-Lizzard-Spock		
			break;
			
			case 3: // Opción 3 - Instrucciones de Voltear el dado
			break;

			case 4: // Opción 4 - Juego Voltear el dado
			break;
			default: cout << "Opción no válida";
		
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
	cout << "Opción: ";
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

	//Logueo de usuarios y registro, si el usuario no está registrado
	cout << "Por favor, introduce tu apodo: ";
	cin >> nombre1;
	cout << "Contraseña: ";
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
				cout << "Contraseña no válida. Vuelve a introducirla ( quedan "<< intrest << " intentos): " ;
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