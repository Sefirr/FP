#include <iostream>
using namespace std;

int menu();
double pulgACm(double pulg);
double lbAGr(double libras);
double grFAgrC(double grF);
double eurosAPts(double euros);

int menu()
{
  cout << "1 - Pulgadas a Cm." << endl;
  cout << "2 - Libras a Gr." << endl;
  cout << "3 - Fahrenheit a ºC" << endl;
  cout << "4 - Euros a Pts." << endl;
  cout << "0 - Salir" << endl;
  int op;
  cout << "Elige: "; cin >> op;
  return op;
}

double pulgACm(double pulg)
{
  assert(pulg > 0);
  double cmPorPulg = 2.54;
  return pulg * cmPorPulg;
}

double lbAGr(double libras)
{
  double grPorLb = 453.6;
  return libras * grPorLb;
}

double grFAgrC(double grF)
{
  return ((grF - 32) * 5 / 9);
}

double eurosAPts(double euros)
{
  double ptsPorEuro = 166.386;
  return euros * ptsPorEuro;
}

int main() {
  double valor;
  int op;
  do {
    op = menu();
    switch (op) {
      case 1:
        cout << "Pulgadas: "; cin >> valor;
        cout << "Equivale a " << pulgACm(valor) << " cm." << endl; break;
      case 2:
        cout << "Libras: "; cin >> valor;
        cout << "Equivale a " << lbAGr(valor) << " gr." << endl; break;
      case 3:
        cout << "Grados Fahrenheit: "; cin >> valor;
        cout << "Equivale a " << grFAgrC(valor) << " ºC" << endl; break;
      case 4:
        cout << "Euros: "; cin >> valor;
        cout << "Equivale a " << eurosAPts(valor) << " pts." << endl; break;
    }
  } while (op != 0);

  return 0;
}
