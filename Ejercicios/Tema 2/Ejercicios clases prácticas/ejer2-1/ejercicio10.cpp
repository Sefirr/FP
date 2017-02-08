/* ?10.   El área de un triángulo se puede calcular mediante la ley del seno: si se conocen
dos lados del triángulo, lado1 y lado2, y el ángulo ? existente entre ellos. Dicha
ley establece que
Área = ½  x  lado1  x  lado2  x  sen ?
Implementa un programa que calcule el área de un triángulo de esta manera. El
programa deberá solicitar al usuario los dos lados y el ángulo que éstos forman
(en grados). Ten en cuenta que la función sin() espera que el ángulo se
proporcione en radianes. Ángulo en radianes = Ángulo en grados x ? / 180. */






#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	double lado1, lado2, area, angulo, radianes;
	cout << "Primer lado del triángulo :";
	cin >> lado1;
	cout << "Segundo lado del triángulo :";
	cin >> lado2;
	cout << "¿Cuál es el ángulo que forman los dos lados?:";
	cin >> angulo;
	radianes = angulo * 3.141592 / 180;
	area = lado1 * lado2 * sin(radianes);
	cout << "El área de un triangulo del primer lado de " << lado1 << " cm y del segundo lado de " << lado2 << " cm y cuyos lados forman un ángulo de " << angulo << " grados es de " << area << " cm." << endl;
	
	return 0;
		}
