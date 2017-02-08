// Version BETA
// Pr�ctica hecha por Javier Villarreal Rodr�guez y Jorge Utrilla Olivera - GRUPO 23
#include <iostream>
#include <string>
using namespace std;
#include <cstdlib>
#include <ctime>
#include <fstream>

int main() 
{
   //Definimos tipo enumerado
   typedef enum {piedra, papel, lagarto, tijeras, spock} tElemento;

   //Variables del tipo definido por el usuario
   tElemento eleccionComputadora, eleccionJugador;

   //Variable necesaria para ejecutar rand() % 5 para decidir la elecci�n de la m�quina
   int NumelementoComputadora;

   //Variables necesarias para mostrar en una cadena de texto la eleccion de la m�quina y la elecci�n del jugador
   string elementoJugador, elementoComputadora, reglasjuego, f, d, nick;

   //Es necesario que se inicialicen a 0 para que las estad�sticas funcionen correctamente ya que utilizan operadores monarios
   int empates = 0;
   int perdidas = 0;
   int ganadas = 0;
   int partidas;

   int opcion; //Necesario para forzar a entrar nuevamente en el men� cada vez que se selecciona una opcion y �sta termina.

   bool elementoCorrecto, encontrado = false;

   ifstream regread, reglas;
   ofstream regwrite;

   srand(time(NULL));

   system("chcp 1252");

   cout << "Introduce un apodo: ";
   cin >> nick;
   // regwrite.open("registro.txt");
   regread.open("registro.txt");
   do {
      regread >> d;
      if (d == nick)
         encontrado = true;
   } while ((d!= "XXX") && !encontrado);
   regread.close();
   if (!encontrado) {
      regread.open("registro.txt");
      regwrite.open("tmp.txt");
      regread >> d;
      while (d != "XXX") {
         regwrite << d << endl;
         regread >> d;
      }
      regwrite << "XXX";
      regwrite.close();
      regread.close();

      regread.open("tmp.txt");
      regwrite.open("registro.txt");
      regread >> d;
      while (d != "XXX") {
         regwrite << d << endl;
         regread >> d;
      }
      regwrite << nick << endl;
      regwrite << "XXX";
      regwrite.close();
      regread.close();
   }

   do
   {
      cout << endl << "1. Jugar" << endl; 
      cout << "2. Reglas" << endl;
      cout << "0. Salir" << endl;
      cout << "Elige una opci�n: ";
      cin >> opcion;

      switch(opcion){
      case 0:
         //Estad�sticas
         partidas = ganadas + perdidas + empates;
         cout << endl << "Estad�sticas " << endl;
         cout << "Partidas jugadas: " << partidas << endl;
         cout << "Partidas ganadas: " << ganadas << endl;
         cout << "Partidas perdidas: " << perdidas << endl;
         cout << "Empates: " << empates << endl;		
         break;

      case 1:

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
            cout << "Elementos(piedra, papel, tijeras, lagarto, spock): ";
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
         case piedra: 
            if((eleccionJugador == papel) || (eleccionJugador == spock)){
               cout << "T� ganas!" << endl;
               ganadas++;
            }
            if((eleccionJugador == lagarto) || (eleccionJugador == tijeras)){
               cout << "Gano yo!" << endl;
               perdidas++;
            }

            break;

            //Elemento - caso papel
         case papel: 
            if((eleccionJugador == piedra) || (eleccionJugador == spock)){
               cout << "Gano yo!" << endl;
               perdidas++;
               if((eleccionJugador == lagarto) || (eleccionJugador == tijeras)){
                  cout << "T� Ganas!" << endl;
                  ganadas++;
               }

               break;

               //Elemento - caso lagarto
         case lagarto: 
            if((eleccionJugador == piedra) || (eleccionJugador == tijeras)){
               cout << "T� Ganas!" << endl;
               ganadas++;
            }
            if((eleccionJugador == papel) || (eleccionJugador == spock)){
               cout << "Gano yo!" << endl;
               perdidas++;
            }

            break;

            //Elemento - caso tijeras	
         case tijeras: 
            if((eleccionJugador == piedra) || (eleccionJugador == spock)){
               cout << "T� ganas!" << endl;
               ganadas++;
            }
            if((eleccionJugador == papel) || (eleccionJugador == lagarto)){
               cout << "Gano yo!" << endl;
               perdidas++;
            }

            break;

            //Elemento - caso spock
         case spock: 
            if((eleccionJugador == piedra) || (eleccionJugador == tijeras)){
               cout << "Gano yo!" << endl;
               perdidas++;
            }
            if((eleccionJugador == papel) || (eleccionJugador == lagarto)){
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
         break;
      case 2:
         reglas.open("reglas.txt");

         if(!reglas.is_open())
            cout << "No se ha abierto el archivo";
         else {			
            do
            {
               getline(reglas,d);
               if(d != "XXX")
                  reglasjuego = reglasjuego + d + '\n';

            } while(d != "XXX");

            cout << reglasjuego << endl;
            reglas.close();		
         }
         break;

      default: cout << endl << "Opci�n no v�lida" << endl;
      }

   } while(opcion != 0);


   return 0;
}