/* El cuadrado de un n�mero entero es igual a la suma de tantos n�meros impares
consecutivos (desde la unidad) como unidades tiene el n�mero. Es decir, 9 es
igual a 1+3+5 (3 impares) y 25 es igual a 1+3+5+7+9 (5 impares).
Implementa un programa que, de forma iterativa, haga lo siguiente (en cada
iteraci�n): solicite un n�mero entero y muestre en la pantalla su cuadrado
calculado utilizando el algoritmo indicado. El programa deber� finalizar cuando
se introduzca el valor 0. */
#include <iostream>
using namespace std;

int main() {
	int num, suma = 0;
	
	bool cuadrado = false;
	


	cout << "Introduce un n�mero entero(0 para terminar): ";
	cin >> num;
	
	for(int i = 1; i < num; i += 2) 
	{
		cout << i << " + ";
	}
	return 0;
}