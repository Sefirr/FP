#include <iostream>
using namespace std;

int main()
{
  double base, altura, area;
  cout << "Introduzca la base del tri�ngulo: ";
  cin >> base;
  cout << "Introduzca la altura del tri�ngulo: ";
  cin >> altura;
  area = base * altura / 2;
 cout << "El �rea de un tri�ngulo de base " << base << " y altura "
       << altura << " es: " << area << endl;
  return 0;
}
