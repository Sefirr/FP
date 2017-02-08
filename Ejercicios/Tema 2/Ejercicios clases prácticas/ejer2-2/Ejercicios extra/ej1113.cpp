#include <iostream>
#include <string>
using namespace std;
#include <iomanip>
#include <cctype>

int main(){

const int IVA = 21, DESC = 20;

typedef enum {castellano, catalan, euskera, gallego, ingles, frances} tIdioma;
typedef enum {accion,aventuras, ciencia_ficcion, comedia, drama, policiaca, terror} tGenero;
typedef enum {novedad, general, oferta, saldo} tTarifa;
tTarifa tarifa;
tIdioma idioma, idiomasubtitulos;
tGenero genero;

double total, porIVA, final, porDesc, precio, TotalFacturado = 0, IvaGlobal = 0;

char subtitulos, descuento;

int duracion, dias, tantoDesc, eleccion;

string titulo, director, cliente, nif, telefono;

bool ok, datospeli = false, datosalquiler = false;


int opcion = -1;

while(opcion != 0){
cout << endl << "1. Datos de la película" << endl;
cout << "2. Datos del alquiler" << endl;
cout << "3.Generar recibo" << endl;
cout << "4. Contabilidad" << endl;
cout << "5. Reiniciar" << endl;
cout << "0. Salir" << endl;
cout << "Opción: ";
cin >> opcion;

if(opcion == 1){

cout << endl << "Título de la película: ";
cin.sync();
getline(cin, titulo);
cout << "Director de la película: "; 
cin.sync();
getline(cin, director);

ok = false;
while (ok == false) {
cout << "Elige el género de la película: " << endl;
cout << "1 - Acción" << endl;
cout << "2 - Aventuras" << endl;
cout << "3 - Ciencia Ficción" << endl;
cout << "4 - Comedia" << endl;
cout << "5 - Drama" << endl;
cout << "6 - Policiaca" << endl;
cout << "7 - Terror" << endl;
cout << "Número de genero: ";
cin >> eleccion;

ok = true;
if (eleccion < 1)
	ok = false;
if (eleccion > 7)
	ok = false;
}
genero = tGenero(eleccion - 1);

	

ok = false;
while (ok == false) {
cout << endl << "Elige un idioma: " << endl;
cout << "1 - Castellano" << endl;
cout << "2 - Catalán" << endl;
cout << "3 - Euskera" << endl;
cout << "4 - Gallego" << endl;
cout << "5 - Inglés" << endl;
cout << "6 - Francés" << endl;
cout << "Número de idioma: ";
cin >> eleccion;

ok = true;
if (opcion < 1)
	ok = false;
if (opcion > 6)
	ok = false;
}
idioma = tIdioma(eleccion - 1);

cout << endl << "¿Está subtitulada la película? ";
cin >> subtitulos;

if(subtitulos == 's'){
ok = false;
while (ok == false) {
cout << "Elige el idioma de los subtitulos: " << endl;
cout << "1 - Castellano" << endl;
cout << "2 - Catalán" << endl;
cout << "3 - Euskera" << endl;
cout << "4 - Gallego" << endl;
cout << "5 - Inglés" << endl;
cout << "6 - Francés" << endl;
cout << "Número de idioma: ";
cin >> eleccion;

ok = true;
if (eleccion < 1)
	ok = false;
if (eleccion > 6)
	ok = false;
}
idiomasubtitulos = tIdioma(eleccion - 1);

	}

ok = false;
while(ok == false){
cout << "Elige una tarifa: " << endl;
cout << "1 - Novedad" << endl;
cout << "2 - General" << endl;
cout << "3 - Oferta" << endl;
cout << "4 - Saldo" << endl;
cout << "Número de tarifa: ";
cin >> eleccion;

ok = true;

if (opcion < 1)
	ok = false;
if (opcion > 4)
	ok = false;
}

tarifa = tTarifa(eleccion - 1);

cout << "Minutos de duración de la película: ";
cin >> duracion;

datospeli = true;
}

if(opcion == 2){
cout << endl << "Nombre del cliente: ";
cin.sync();
getline(cin, cliente);
cout << "NIF del cliente: ";
cin.sync();
getline(cin, nif);
cout << "Teléfono del cliente: ";
cin.sync();
getline(cin, telefono);
cout << "Días: ";
cin >> dias;
cout << "Descuento (s/n)? ";
cin >> descuento;
descuento = toupper(descuento);

datosalquiler = true;
}

if(opcion == 3){
if (datospeli == false){
		cout << endl << "¡No hay datos de la película!" << endl;
		}
		else if (datosalquiler == false){
		cout << endl << "¡No hay datos de alquiler!" << endl;
		}
		else  {
cout << endl << "Factura:" << endl;
cout << setw(50) << right <<  cliente << endl;
cout << setw(50) << right << nif << endl;
cout << setw(50) << right << telefono << endl;


	



cout << endl << endl << "Película:" << endl;
cout << titulo << " (Dir.: " << director << ")" << endl;
if(genero == accion)
	cout << "Acción";
if(genero == aventuras)
	cout << "Aventuras";
if(genero == ciencia_ficcion)
	cout << "Ciencia Ficción";
if(genero == comedia)
	cout << "Comedia";
if(genero == drama)
	cout << "Drama";
if(genero == policiaca)
	cout << "Policiaca";
if(genero == terror)
	cout << "Terror";
cout << " (" << duracion << " min.)" << endl;
cout << "Idioma: "; 
if(idioma == castellano)
cout << "Castellano";
if(idioma == catalan)
cout << "Catalán";
if(idioma == euskera)  
cout << "Euskera";
if(idioma == gallego) 
	cout << "Gallego";
if(idioma == ingles) 
	cout << "Inglés";
if(idioma == frances )
	cout << "Francés";
	

cout << " (subtitulada en ";

if(idiomasubtitulos == castellano )
cout << "Castellano)" << endl << endl;
if(idiomasubtitulos == euskera)
cout << "Euskera)" << endl << endl;
if(idiomasubtitulos == gallego)
cout << "Gallego)" << endl << endl;
if(idiomasubtitulos == catalan)
cout << "Catalán)" << endl << endl;
if(idiomasubtitulos == ingles)
cout << "Inglés)" << endl << endl;
if(idiomasubtitulos == frances)	
cout << "Francés)" << endl << endl;

cout << "Facturación:" << endl;
if(tarifa == novedad)
precio = 3.5;
if(tarifa == general)
precio = 2.5;
if(tarifa == oferta)
precio = 1.5;
if(tarifa == saldo)
precio = 0.5;

cout  << setw(40) << left << "Precio por día" << setw(10) << right << precio << " €" << endl;
cout  << setw(40) << left << "Días" << setw(8) << right << dias << endl;

total = precio * dias;

cout << setw(40) << left << "Total" << setw(10) << right << fixed << setprecision(2) << total << " €" << endl;
        
tantoDesc = 0;

if(descuento == 'S'){
	tantoDesc = DESC;
    porDesc = total * tantoDesc / 100;
}	
cout << setw(40) << left << "Descuento" << setw(7) << right << tantoDesc << " %" << endl;
cout << setw(50) << right << fixed << setprecision(2) << -porDesc << " €" << endl;
total = total - porDesc;
cout << setw(40) << left << "Total tras descuento" << setw(10) << right << setprecision(2) << total << " €" << endl;
cout << setw(40) << left << "I.V.A" << setw(7) << right << IVA << " %" << endl;
porIVA = total * IVA / 100;
cout << setw(50) << right << porIVA << " €" << endl;

final = total + porIVA;
cout << setw(40) << left << "Precio final" << setw(10) << right << final << " €" << endl;

TotalFacturado = TotalFacturado + total;
IvaGlobal = IvaGlobal + porIVA;
}

}

if(opcion == 4) {
		cout << endl << setw(40) << left << "Total facturado: ";
		cout << setw(10) << right << fixed << setprecision(2) << TotalFacturado << " €" << endl;
		cout << setw(40) << left << "Total de I.V.A.: ";
		cout << setw(10) << right << fixed << setprecision(2) << IvaGlobal << " €" << endl;
		}

if(opcion == 5){
	datospeli = datosalquiler = false;
	IvaGlobal = TotalFacturado = 0;
	}
}
return 0;
	
}