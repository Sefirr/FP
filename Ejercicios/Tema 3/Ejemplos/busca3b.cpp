#include <iostream>
using namespace std;
#include <fstream>

int main()
{
  int i, num, cont = 1;
  ifstream archivo;
  archivo.open("ordenada.txt");
  cout << "Valor a localizar: ";
  cin >> num;
  archivo >> i;
  while ((i != 0) && (i < num))
  {
     cont++;
     archivo >> i;
  }
  if (i == num)
     cout << "Encontrado (pos.: " << cont << ")";
  else
     cout << "No encontrado";
  cout << endl;
  archivo.close();

  return 0;
}
