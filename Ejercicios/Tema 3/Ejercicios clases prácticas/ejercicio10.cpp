/* Escribe un programa que lea del teclado diez números enteros y muestre en la
pantalla el mayor de todos ellos. */

#include <iostream>
using namespace std;
#include <stdio.h>

int main()
{
	int num, mayor = 0; 
	
	cout << "Introduce un número: ";
	cin >> num;   //pide ingresar un valor para num
	mayor = num;
	
	for (int cont = 1; cont <= 9; cont++)  
	{
		cout << "Introduce un número: ";
		cin >> num;	//pide ingresar un valor para num
		if (num > mayor)		//si num es mas que mayor hacer que
		mayor = num;	//	mayor va a tomar el valor de num
	}
	cout << "El número mayor es " << mayor << endl;
	return 0;

}