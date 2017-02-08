#include <iostream>
using namespace std;

void intercambia(double &valor1, double &valor2); // Prototipo

void intercambia(double &valor1, double &valor2)
// Intercambia los valores.
{
  double tmp; // Variable local (temporal)
  tmp = valor1;
  valor1 = valor2;
  valor2 = tmp;
}

int main() {
  double num1, num2;
  cout << "Valor 1: "; cin >> num1;
  cout << "Valor 2: "; cin >> num2;
  intercambia(num1, num2);
  cout << "Ahora el valor 1 es " << num1 
       << " y el valor 2 es " << num2 << endl;
  
  return 0;
}
