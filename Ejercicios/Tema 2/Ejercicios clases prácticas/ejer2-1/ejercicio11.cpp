#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	double x, y, f;
	const double factor =1.531;
	const double PI = 3.141592;
	cout << "Valor de x: ";
	cin >> x;
	cout << "Valor de y: ";
	cin >> y;
	f = sqrt(pow(factor,(x+y)) + abs(exp(x) - exp(x))) * (sin(x) - tan(y)) / (log10(y) * pow(PI, x));
	cout << "f(x,y) = " << f; 
	return 0;
		}
