/* Declara un tipo enumerado tCalificacion con los valores noPresentado,
suspenso, aprobado, notable, sobresaliente y matriculaDeHonor. Luego,
declara dos variables nota1 y nota2, y lee en ellas dos calificaciones num�ricas
de 0 a 10 (con un decimal). Asigna a dos variables calif1 y calif2, de tipo
tCalificacion, el valor que les corresponda, de acuerdo con los valores de las
correspondientes variables num�ricas (0: noPresentado). Finalmente, muestra
cada nota num�rica seguida de la calificaci�n textual que le corresponde. (S�lo
mostrar� las calificaciones si ambas notas est�n entre 0 y 10.) */

#include <iostream>
using namespace std;

int main() 
{
	typedef enum {noPresentado, suspenso, aprobado, bien, notable, sobresaliente, matriculaDeHonor} tCalificacion;
	tCalificacion calif1, calif2;
	int nota1, nota2;
	
	cout << "Nota 1: ";
	cin >> nota1;
	cout << "Nota 2: ";
	cin >> nota2;
	
	switch(nota1){
		case 0: calif1 = noPresentado; break;
		case 1:
		case 2:
		case 3: 
		case 4: 
		calif1 = suspenso; break;
		case 5: calif1 = aprobado; break;
		case 6:	
		case 7:	calif1 = notable; break;
		case 8:	
		case 9: calif1 = sobresaliente; break;
		case 10: calif1 = matriculaDeHonor; break;
		default: cout << "Valor no v�lido";
	}
	
	switch(nota2){
		case 0: calif2 = noPresentado; break;
		case 1:
		case 2:
		case 3: 
		case 4: calif2 = suspenso; break;
		case 5: calif2 = aprobado; break;
		case 6:	
		case 7:	calif2 = notable; break;
		case 8:	
		case 9: calif2 = sobresaliente; break;
		case 10: calif2 = matriculaDeHonor; break;
		default: cout << "Valor no v�lido";
	}
	
	cout << "Nota 1: ";
	cout << nota1 << " (";
	if(calif1 == noPresentado)
		cout << "No presentado";

		else if(calif1 == suspenso) 		
			cout << "suspenso";
		else if(calif1 == aprobado) 		
			cout << "Aprobado";
		else if(calif1 == notable)		
			cout << "Notable";
		else if(calif1 == sobresaliente)	
			cout << "sobresaliente";
		else if(calif1 == matriculaDeHonor)
			cout << "Matr�cula de Honor";
		
	cout << ")" << endl;
			
	cout << "Nota 2: ";
	cout << nota2 << " (";
	if(calif2 == noPresentado)	
		cout << "No presentado";
		else if(calif2 == suspenso) 		
			cout << "suspenso";
		else if(calif2 == aprobado) 		
			cout << "Aprobado";
		else if(calif2 == notable)		
			cout << "Notable";
		else if(calif2 == sobresaliente)	
			cout << "sobresaliente";
		else if(calif2 == matriculaDeHonor)
			cout << "Matr�cula de Honor";
	
	cout << ")" << endl;


	return 0;
}