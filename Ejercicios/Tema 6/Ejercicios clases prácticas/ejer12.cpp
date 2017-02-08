/* Ejercicio 12 - Como parte de un programa de gestión contable, se necesita una estructura de
datos capaz de almacenar los gastos en distintos conceptos producidos cada mes
por cada uno de los departamentos. Define tal estructura de datos teniendo en
cuenta que los departamentos y los tipos de gastos contemplados son los
siguientes:
 Departamentos: Marketing, Contabilidad, Recursos_Humanos, Distribución,
Ingeniería, Investigación.
 Conceptos: Salarios, Suministros, Mobiliario, Equipamiento, Otros.

Programa:
Define subprogramas que, partiendo de una matriz de gastos completa, realicen
las siguientes tareas:
a) Escribir en la pantalla la suma de gastos de cada uno de los departamentos.
b) Escribir en la pantalla la suma de gastos por cada concepto.
c) Calcular y devolver el total de gastos de un año.
d) Construir y devolver un array con los gastos generados cada mes.
e) Encontrar el valor más alto de la tabla de gastos y devolver el departamento
responsable, el tipo de gasto y el mes en que se produjo.

*/
#include <iostream>
#include <string>
using namespace std;

typedef enum { MARKETING, CONTABILIDAD, RECURSOS_HUMANOS, DISTRIBUCION, INGENIERIA, INVESTIGACION } tDepartamento;
typedef enum { SALARIOS, SUMINISTROS, MOBILIARIO, EQUIPAMIENTO, OTROS } tConceptos;

const int NUM_DEPARTAMENTOS = 6;
const int NUM_CONCEPTOS = 5;
const int MES = 12;
typedef double tGastos [MES][NUM_DEPARTAMENTOS][NUM_CONCEPTOS];

typedef double tGastosMensuales[MES];
void imprimeSumaGastosPorDepartamento(const tGastos gastos)
{
	for(int i = 0; i < NUM_DEPARTAMENTOS; i++)
	{
		double sumaGastos = 0;
		for( int j = 0; j < NUM_CONCEPTOS; j++)
		{
			sumaGastos += gastos[i][j];
		}
		cout << "Departamento " << aCadena(i) << ": " << sumaGastos << endl;
	}
}

double GastosAnuales(const tGastos gastos) {
	double TotalGastos = 0;
	for(int i = 0; i < MES; i++) {
		for(int j = 0; j < NUM_DEPARTAMENTOS; j++) {
			for(int k = 0; k < NUM_CONCEPTOS; k++) {
				TotalGastos += gastos[i][j][k];
			}
		}
	}
	return TotalGastos;
}

double GastosMes(const tGastos gastos, tGastosMensuales gastosM) {
	double TotalGastos = 0;
	for(int i = 0; i < MES; i++) {
		for(int j = 0; j < NUM_DEPARTAMENTOS; j++) {
			for(int k = 0; k < NUM_CONCEPTOS; k++) {
				gastosM[i] += gastos[i][j][k];
			}
		}
	}
	return TotalGastos;
}

string aCadena(int numDep) 
{
	string result = "";
	switch (numDep){
	case MARKETING:
		result = "Marketing";
		break;
	case 0: result = "
	default:
		result = "NO EXISTE";
		break;
	}
	return result;
}
int main() {

	tGastos gastos;

	return 0;
}