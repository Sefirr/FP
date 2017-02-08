#include <iostream>
using namespace std;

int main()
{
	int x = 12, y = 3;
	double sigma =2.1836, lambda = 1.11695, alfa = 328.67, f;

	f = 3 * ((x + sigma * y) / (x*x - y*y)) - (lambda * (alfa - 13.7)) ;
	
	cout << " Valor de x = " << x << endl;
	cout << " Valor de y = " << y << endl;
	cout << " Valor de sigma = " << sigma << endl;
	cout << " Valor de lambda = " << lambda << endl;
	cout << " Valor de alfa = " << alfa << endl;
	cout << "f = 3 x " << x << " + " << sigma << " x " << y << " / " << x*x << " - " << y*y << " - " << lambda << " x " << alfa << " - 137 = " << f ; 
	
	
	return 0;
		}
