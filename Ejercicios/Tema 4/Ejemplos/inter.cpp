#include <iostream>
using namespace std;

void intercambia(int &x, int &y);
void intercambia(double &x, double &y);
void intercambia(char &x, char &y);

void intercambia(int &x, int &y) 
{
  int tmp;
  tmp = x;
  x = y;
  y = tmp;
}

void intercambia(double &x, double &y) 
{
  double tmp;
  tmp = x;
  x = y;
  y = tmp;
}

void intercambia(char &x, char &y) 
{
  char tmp;
  tmp = x;
  x = y;
  y = tmp;
}

int main() {
  int i1 = 3, i2 = 7;
  double d1 = 12.5, d2 = 35.9;
  char c1 = 'a', c2 = 'b';
  cout << i1 << " - " << i2 << endl;
  cout << d1 << " - " << d2 << endl;
  cout << c1 << " - " << c2 << endl;
  intercambia(i1, i2);
  intercambia(d1, d2);
  intercambia(c1, c2);
  cout << i1 << " - " << i2 << endl;
  cout << d1 << " - " << d2 << endl;
  cout << c1 << " - " << c2 << endl;
  return 0;
}
