#include <iostream>
#include <string>
using namespace std;

int main() {
  string nombre, apellidos;
  cout << "Nombre: ";
  getline(cin, nombre);
  cout << "Apellidos: ";
  getline(cin, apellidos);
  cout << "Nombre completo: " << nombre << " "
       << apellidos << endl;

  return 0;
}
