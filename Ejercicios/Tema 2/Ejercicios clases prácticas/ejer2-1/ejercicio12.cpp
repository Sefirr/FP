#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	double capital, cuota, ratio, plazo, interes_anual, ans;
	cout << "Capital: ";
	cin >> capital;
	cout << "Interes anual: ";
	cin >> interes_anual;
	cout << "Plazo en años: ";
	ratio = interes_anual / 12;
	cin >> ans;
	plazo = ans * 12;
	cuota = (capital * ratio) / (100 * (1 - pow(1 + (ratio / 100),-plazo)));
	cout << "Tu cuota mensual es " << cuota; 
	
	return 0;
		}
