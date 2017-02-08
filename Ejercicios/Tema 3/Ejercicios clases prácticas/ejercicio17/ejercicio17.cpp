/* Escribe un programa que lea los n�meros de un archivo datos.txt (cada l�nea
contiene un n�mero real positivo) y muestre en la pantalla el mayor de todos
ellos. El archivo termina con un 0 como centinela. */

#include <iostream>
using namespace std;
#include <fstream>

int main()
{
	int num, mayor;
	ifstream datos;
	
	datos.open("datos.txt");
	
	if(!datos.is_open())
		cout << "No se ha abierto el archivo de datos";
	
	else
	{
		datos >> num;
		mayor = num;
		
		while(num != 0)
		{
		datos >> num;
			if(num > mayor)
			{
				mayor = num;
				}
			}
		cout << "El n�mero mayor es " << mayor << endl;
		}
	
	
	
	datos.close();
	

	return 0;
	
}