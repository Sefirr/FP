/* Conversiones de tipos: Prueba el siguiente programa en tu compilador (copia y
pega). Comprueba los problemas que se generan en las conversiones inseguras. */

#include <iostream>
using namespace std;
int main() {
double real;
int entero;
short int corto;
char caracter;
// Conversiones "hacia arriba" (seguras)
cout << "Introduce un carácter: ";
cin >> caracter;
corto = caracter;
cout << "Entero corto: " << corto << endl;
entero = corto;
cout << "Entero: " << entero << endl;
real = entero;
cout << "Real: " << real << endl;
// Conversiones "hacia abajo" (inseguras)
cout << "Introduce un real muy grande: ";
cin >> real;
entero = real;
cout << "Entero: " << entero << endl;
corto = entero;
cout << "Entero corto: " << corto << endl;
caracter = corto;
cout << "Carácter: " << caracter << endl;
return 0;
}

// Da errores en las conversiones inseguras: se pierde información 
// en la conversión de entero a entero con un rango de valores más corto
// y en la conversión de entero corto a carácter.