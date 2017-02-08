#include <iostream>
#include <string>
using namespace std;

int main()
{	
	string a, b, c;
	
	cout << "Valor de a:";
	cin >> a;
	cout << "Valor de b:";
	cin >> b;
	cout << "Valor de c:";
	cin >> c;
	
	if(b > c){
	string aux = b;
	b = c;
	c = aux;
	}
	if(b > a) {
	string aux = b;
	b = a;
	a = aux;
	}
	if (a > b) {
	string aux = a;
	a = b;
	b = aux;
	}
	if(a > c) {
	string aux = a;
	a = c;
	c = aux;
	}
	if(c > a){
	string aux = c;
	c = a;
	a = aux;
	}
	if(c > b) {
	string aux = c;
	c = b;
	b = aux;
	}
	
	cout << "Cadenas de texto de menor a mayor caracteres: " << c << ", " << b << ", " << a << ", " << endl;
	
	
	return 0;
		}
