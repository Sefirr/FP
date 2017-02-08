#include <iostream>
using namespace std;

int main()
{
  int num = 1;
  while(num * num <= 1000)
     num++;
  cout << "1er. entero con cuadrado mayor que 1.000: "
       << num << endl;

  return 0;
}
