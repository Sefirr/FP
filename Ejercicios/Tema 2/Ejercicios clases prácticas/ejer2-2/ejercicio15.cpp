#include <iostream>
using namespace std;

int main()
{
	double examen1, examen2, examen3, examen4, mediaprac, practica1, practica2, practica3, practica4, practica5, actividad_ad, notafinal;
	cout << "Resultado del examen de diciembre = ";
	cin >> examen1;
	cout << "Resultado del examen de febrero = ";
	cin >> examen2;
	cout << "Resultado del examen de abril = ";
	cin >> examen3;
	cout << "Resultado del examen final = ";
	cin >> examen4;
	cout << "Resultado práctica 1 = ";
	cin >> practica1;
	cout << "Resultado práctica 2 = ";
	cin >> practica2;
	cout << "Resultado práctica 3 = ";
	cin >> practica3;
	cout << "Resultado práctica 4 = ";
	cin >> practica4;
	cout << "Resultado práctica 5 = ";
	cin >> practica5;
	mediaprac = (practica1+practica2+practica3+practica4+practica5)/5;
	cout << "Resultado actividad adicional = ";
	cin >> actividad_ad;
	cout << endl;
	
	if(mediaprac >= 5 && examen4 > 4)
	{
	notafinal =  examen1*0.05 + examen2*0.1 + examen3*0.1 + examen4*0.45 + mediaprac*0.2 + actividad_ad*0.1;
	cout << "La calificación de la nota final = " << notafinal;
	}
	else{
	cout << "No has aprobado la asignatura porque no has aprobado todas las prácticas o no has sacado mas de un 4 en el examen final, o bien las dos." << endl;
	}
		return 0;
}