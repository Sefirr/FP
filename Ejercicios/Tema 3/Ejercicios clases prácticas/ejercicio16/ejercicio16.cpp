/* Escribe	 un	 programa	 que	 genere	 un	 archivo output.txt	 en	 el	 que	 aparezcan	 invertidos	 
los n�meros	 enteros	 positivos	 que	 haya	 en	 otro archivo input.txt. Cada l�nea de input.txt
contendr�	un	n�mero	entero	y	 terminar�	en	una	l�nea	con	un	0	(centinela). */


#include <iostream>
using namespace std;
#include <fstream>

int main() {
   int valor;
   ifstream archivoEntrada;
   ofstream archivoSalida;

   archivoEntrada.open("input.txt"); // Apertura archivo entrada
   if (!archivoEntrada.is_open())
      cout << "NO HAY ARCHIVO DE ENTRADA" << endl;
   else {
      archivoSalida.open("output.txt"); // Crear archivo salida
      if (!archivoSalida.is_open()) {
         cout << "ERROR DE ARCHIVO DE SALIDA" << endl;
      }
      else { // Abiertos ambos archivos...
         archivoEntrada >> valor; // Lectura del primer n�mero
         while (valor != 0) { // Mientras no sea el 0 final
            if (valor > 0) { // Si no negativo...
               while (valor != 0) {
                  archivoSalida << valor % 10;
                  valor = valor / 10;
               }
               archivoSalida << endl;
            }
            archivoEntrada >> valor; // Lectura del siguiente
         }
         // Cierre de los archivos
         archivoEntrada.close();
         archivoSalida.close();
	  }

      }
   


	return 0;
}