// Ejercicio de la clase del 03/12

#include <iostream>
using namespace std;
#include <cstdlib>
#include <ctime>
#include <fstream>

int main() {
   ifstream entrada;
   ofstream salida;
   int dato, entero, suma, opcion = -1, buscado, linea;
   bool triangular, generada = false, encontrado, op2 = false, op3 = false;
   
   srand(time(NULL));
   
   while (opcion != 0) {
      if (op2 && op3) {
         generada = false;
         op2 = false;
         op3 = false;
      }
      
      cout << "1 – Generar una secuencia" << endl;
      cout << "2 – Procesar la secuencia" << endl;
      cout << "3 – Buscar en la secuencia" << endl;
      cout << "0 – Salir" << endl;
      cout << "Opción: ";
      cin >> opcion;

      switch (opcion) {
         case 1:
            salida.open("datos.txt");
            for (int i = 1; i <= 100; i++)
               salida << (rand() % 10000 + 1) << endl;
            salida << -1;
            salida.close();
            generada = true;
            break;

         case 2:
            if (!generada) 
               cout << "La secuencia todavía no se ha generado" << endl;
            else {
               entrada.open("datos.txt");
               if (!entrada.is_open())
                  cout << "¡Error al abrir el archivo!" << endl;
               else {
                  entrada >> dato;
                  while (dato != -1) {
                     suma = 0;
                     entero = 0;
                     while (suma < dato) {
                        entero++;
                        suma = suma + entero;
                     }
                     triangular = (suma == dato);
                     cout << "El número " << dato << " ";
                     if (triangular)
                        cout << "SI";
                     else
                        cout << "NO";
                     cout << " es triangular";
                     if (triangular)
                        cout << " (1.." << entero << ")";
                     cout << endl;
                     entrada >> dato;
                  }
                  entrada.close();
                  op2 = true;
               }
            }
            break;
            
         case 3:
            if (!generada) 
               cout << "La secuencia todavía no se ha generado" << endl;
            else {
               entrada.open("datos.txt");
               if (!entrada.is_open())
                  cout << "¡Error al abrir el archivo!" << endl;
               else {
                  cout << "Número a buscar: ";
                  cin >> buscado;
                  encontrado = false;
                  linea = 1;
                  entrada >> dato;
                  while ((dato != -1) && !encontrado)
                     if (dato >= buscado)
                        encontrado = true;
                     else {
                        entrada >> dato;
                        linea++;
                     }
                  entrada.close();
                  if (encontrado)
                     cout << "Encontrado el primer igual o mayor en la línea " << linea << endl;
                  else
                     cout << "¡Ninguno mayor o igual que el buscado!" << endl;
                  op3 = true;
               }
            }
            
            break;
            
         default:
            cout << "Opción incorrecta. Inténtalo de nuevo..." << endl;
      }
   }

   return 0;
}
