#include <iostream>
#include <cmath>
using namespace std;

int main()
{	
	int a, b, c;
	
	cout << "Valor de a:";
	cin >> a;
	cout << "Valor de b:";
	cin >> b;
	cout << "Valor de c:";
	cin >> c;
	
	if(b > c){
	int aux = b;
	b = c;
	c = aux;
	}
	if(b > a) {
	int aux = b;
	b = a;
	a = aux;
	}
	if (a > b) {
	int aux = a;
	a = b;
	b = aux;
	}
	if(a > c) {
	int aux = a;
	a = c;
	c = aux;
	}
	if(c > a){
	int aux = c;
	c = a;
	a = aux;
	}
	if(c > b) {
	int aux = c;
	c = b;
	b = aux;
	}
	
	cout << "Números ordenados de menor a mayor: " << c << ", " << b << ", " << a << endl;
	
	
	return 0;
		}
