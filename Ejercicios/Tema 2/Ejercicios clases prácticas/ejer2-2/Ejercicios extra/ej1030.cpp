// Tema 2 - Ejercicio extra de la clase del 30/10
// Preparado para la clase del 06/11 (inicialmente incorrecto)

#include <iostream>
#include <string>
using namespace std;
// Un s?lo using... para ambas bibliotecas

#include <iomanip>
// Las que no tienen espacios de nombres, despues de using...

int main()
{
   // Constantes y variables para la opci?n 1:
   const double CmPorPulgada = 2.54;
   const double MPorMilla = 1609.344;
   const double LPorGalon = 4.5461;
   const double GrPorOnza = 28.349523125;
   const double KgPorLibra = 0.45359237;
   // No declaramos constante para la conversi?n de grados Fahrenheit
   
   double medida, convertida;
   char unidad; // Las unidades de entrada son todas de una sola letra
   string unidadSalida; // No nos vale un s?lo car?cter (cm, gr, ?C, ...)
   
   // Variables para la opci?n 2:
   int num, i;
   bool ok; // Para comprobar si es un n?mero v?lido (entre 1 y 100)
   
   // Variables para la opci?n 3:
   double op1, op2, resultado;
   char operador;
   
   int opcion = -1; // Para forzar a entrar en el bucle la primera vez

   system("chcp 1252");
   
   while (opcion != 0) {
      cout << endl;
      cout << "1. Conversor de medidas" << endl;
      cout << "2. Tabla de multiplicar" << endl;
      cout << "3. Calculadora" << endl;
      cout << "0. Salir" << endl;
      cout << "Opción: ";
      cin >> opcion;
      cout << endl;
      
      if (opcion == 1) { // ?Cuidado! Para comparar se utiliza ==, NO =
         cout << "Unidades: pulgadas (p), millas (m), ?F (f), galones (g), onzas (o), libras (l)" << endl;
         cout << "Introduce una medida (cantidad seguida de letra de unidad; 0 para terminar):" << endl;
         cin >> medida;
         // Leemos primero la medida y vemos si es 0.
         // Si no lo es, entonces leeremos la unidad...
         
         while (medida != 0) {
            cin >> unidad;
            
            if (unidad == 'p') {
               convertida = medida * CmPorPulgada;
               unidadSalida = "cm";
            }
            if (unidad == 'm') {
               convertida = medida * MPorMilla;
               unidadSalida = "m";
            }
            if (unidad == 'f') {
               convertida = (medida - 32 ) * 5 / 9; // ?Ojo con la divisi?n entera!
               unidadSalida = "ºC";
            }
            if (unidad == 'g') {
               convertida = medida * LPorGalon;
               unidadSalida = "l";
            }
            if (unidad == 'o') {
               convertida = medida * GrPorOnza;
               unidadSalida = "gr";
            }
            if (unidad == 'l') {
               convertida = medida * KgPorLibra;
               unidadSalida = "kg";
            }
		
            
            cout << "Equivalente a " << convertida << " " << unidadSalida << endl;
            // Ojo! No repitas código en todos los if.
            // En lugar de mostrar el resultado en cada uno, muestralo despues de ellos.
            
            // Leemos la siguiente medida...
            cout << "Introduce una medida (cantidad seguida de letra de unidad; 0 para terminar):" << endl;
            cin >> medida;
			}
		}
      
      if (opcion == 2) {
         ok = false;
         // Cuidado! Ha de inicializarse cada vez que se elija esta opción.
         // Comprueba qué ocurre si en lugar de inicializar aquí, lo haces sólo en la declaración

         while (ok == false) {
            cout << "Introduce un número: ";
            cin >> num;
            if (num >= 1)
               if (num <= 100)
                  ok = true; // Sólo salimos del bucle si esté entre 1 y 100
         }
         
         while (i < 11) {
         // Usamos manipuladores de formato:
            cout << setw(3) << i << "  x  " 
               << setw(4) << num << "  =  "
               << setw(5) << i * num << endl;
            i++;
         }
      }
      
      if (opcion == 3) {
         cout << "Operando Operador Operando (0 para terminar): ";
         cin >> op1;
         // Leemos primero el primer operando y vemos si es 0.
         // Si no lo es, entonces seguimos leyendo...
         
         while (op1 != 0) {
            cin >> operador >> op2;
            if (operador == '+')
               resultado = op1 + op2;
            if (operador == '-')
               resultado = op1 - op2;
            if (operador == '*') 
               resultado = op1 * op2;
            if (operador == '/')
               resultado = op1 / op2;
            cout << op1 << " " << operador << " " << op2
               << " = " << resultado << endl;
            // Ojo! No repitas código en todos los if.
            // En lugar de mostrar el resultado en cada uno, muestralo despues de ellos.
            
            // Leemos el siguiente primer operando...
            cout << "Operando Operador Operando (0 para terminar): ";
            cin >> op1;
			}
		}
	
	}	
	
	
   return 0;

}
   
    