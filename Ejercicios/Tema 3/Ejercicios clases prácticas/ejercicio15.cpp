/* ¿Cuál será el contenido del archivo salida.txt después de ejecutar el siguiente
programa? (Indica el resultado sin ejecutar el código en un compilador.) */

#include <iomanip>
using namespace std;
#include <fstream>
int main()
{
	ofstream archivo;
	bool llueve = false;
	int i = 35;
	double d1 = 123;
	double d2 = 123.45;
	char c = 'x';
	float f = 3.14;

	archivo.open("salida.txt"); // Creación del archivo
	
	archivo << "Hoy llueve = " << llueve << boolalpha << llueve << endl;
	archivo << i << right << setw(8) << i << endl;
	archivo << d1 << scientific << right << setw(8) << d1 << endl;
	archivo << d2 << right << fixed << setw(8) << setprecision(3) << d2 << endl;
	archivo << c << setw(8) << left << c << endl;
	archivo << f << right << setw(5) << setprecision(3) << f << endl;
	archivo << scientific << d2 << fixed << endl;
	archivo << setprecision(8) << d2 << endl;
	
	archivo.close(); // Cierre del archivo
	
	return 0;
}

/* Contenido salida.txt:
35							35
123					 1.23*10^2
123.45				   123.45X
x	x
3.14 3.141
123.45
123.45XX
*/