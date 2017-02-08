#include <iostream>
using namespace std;

void divisores(int valor); // Prototipo

void divisores(int valor)
// Muestra los divisores del valor entero.
{
  for (int i = 1; i <= valor; i++) // Variable local
    if (valor % i == 0)
      cout << i << "  ";
  cout << endl;
}

int main() {
  int num;
  cout << "Valor: "; cin >> num;
  cout << "Los divisores de " << num 
       << " son:" << endl;
  divisores(num);
  
  return 0;
}
