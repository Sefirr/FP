#include <iostream>
using namespace std;
#include <fstream>


int main()
{
	char c1, c2;
	int secuencia = 0;

	ifstream lectura;

	lectura.open("input26.txt");
	do {
		lectura >> c1;
		if(c1 == 'x')
		{
			lectura >> c2;
				if(c2 == 'y')
					++secuencia;
		}
		else 
			lectura >> c1;
	} while(c1 != '*');

	lectura.close();
	
	cout << "Secuencia xy leída " << secuencia << " veces." << endl;


	return 0;

}