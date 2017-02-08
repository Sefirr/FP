// Control de diciembre de 2012

#include <iostream>
using namespace std;
#include <fstream>
#include <iomanip>

int main() {
   ifstream entrada;
   ofstream salida;
   int dato, opcion = -1, buscado, linea;
   bool esPrimo, encontrado;
   
   system("chcp 1252");

   while (opcion != 0) {
      cout << "1 - Crear la secuencia" << endl;
      cout << "2 - Procesar la secuencia" << endl;
      cout << "3 - Buscar en la secuencia" << endl;
      cout << "0 - Salir" << endl;
      cout << "Opción: ";
      cin >> opcion;

      switch (opcion) {
         case 1:
            salida.open("datos.txt");
            cout << "Entero positivo (0 para terminar): ";
            cin >> dato;
            while (dato != 0) {
               if ((dato >= 1) && (dato <= 1000))
                  salida << dato << endl;
               cout << "Entero positivo (0 para terminar): ";
               cin >> dato;
            }
            salida << -1;
            salida.close();
            break;

         case 2:
            entrada.open("datos.txt");
            if (!entrada.is_open())
               cout << "¡Error al abrir el archivo!" << endl;
            else {
               entrada >> dato;
               while (dato != -1) {
                  cout << setw(4) << dato << " ";
                  esPrimo = true;
                  for (int i = 2; i <= dato / 2; i++) {
                     if (dato % i == 0)
                        if (esPrimo) { // Primer divisor encontrado
                           esPrimo = false;
                           cout << "no es primo (" << i;
                        }
                        else // No es el primer divisor
                           cout << ", " << i;
                  }
                  if (esPrimo)
                     cout << "es primo";
                  else
                     cout << ")";
                  cout << endl;
                  entrada >> dato;
               }
               entrada.close();
            }
            break;
            
         case 3:
            entrada.open("datos.txt");
            if (!entrada.is_open())
               cout << "¡Error al abrir el archivo!" << endl;
            else {
               cout << "Cuadrado a buscar: ";
               cin >> buscado;
               encontrado = false;
               linea = 1;
               entrada >> dato;
               while ((dato != -1) && !encontrado)
                  if ((dato * dato >= buscado - 10) && (dato * dato <= buscado + 10))
                     encontrado = true;
                  else {
                     entrada >> dato;
                     linea++;
                  }
               entrada.close();
               if (encontrado)
                  cout << "Encontrado en la línea " << linea << ": " << dato 
                       << " (cuadrado: " << dato * dato << ")" << endl;
               else
                  cout << "¡Ninguno mayor o igual que el buscado!" << endl;
            }
            break;
            
         default:
            cout << "Opción incorrecta. Inténtalo de nuevo..." << endl;
      }
   }

   return 0;
}
