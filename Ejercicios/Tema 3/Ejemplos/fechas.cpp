#include <iostream>
using namespace std;

int main()
{
   typedef enum { enero, febrero, marzo, abril, mayo, junio, julio, agosto, septiembre, octubre, noviembre, diciembre } tMes;

   typedef enum { lunes, martes, miercoles, jueves, viernes, sabado, domingo } tDiaSemana;

   tDiaSemana hoy;
   int dia;
   tMes mes;
   int anio;
   
   dia = 20;
   hoy = jueves;
   mes = octubre;
   anio = 2011;
   
   // Mostramos la fecha
   cout << "Hoy es: ";
   switch (hoy) {
      case  lunes     : cout << "lunes";     break; 
      case  martes    : cout << "martes";    break; 
      case  miercoles : cout << "miercoles"; break; 
      case  jueves    : cout << "jueves";    break; 
      case  viernes   : cout << "viernes";   break; 
      case  sabado    : cout << "sabado";    break; 
      case  domingo   : cout << "domingo";   break; 
   }
   cout << " " << dia << " de ";
   switch (mes) {
      case  enero      : cout << "enero";      break; 
      case  febrero    : cout << "febrero";    break; 
      case  marzo      : cout << "marzo";      break; 
      case  abril      : cout << "abril";      break; 
      case  mayo       : cout << "mayo";       break; 
      case  junio      : cout << "junio";      break; 
      case  julio      : cout << "julio";      break; 
      case  agosto     : cout << "agosto";     break; 
      case  septiembre : cout << "septiembre"; break; 
      case  octubre    : cout << "octubre";    break; 
      case  noviembre  : cout << "noviembre";  break;
      case  diciembre  : cout << "diciembre";  break;
   }
   cout << " de " << anio << endl;
   
   cout << "Pasada la medianoche..." << endl;
   
   ++dia;
   int i = int(hoy);
   i++;
   hoy = tDiaSemana(i);

   // Mostramos la fecha
   cout << "Hoy es: ";
   switch (hoy) {
      case  lunes     : cout << "lunes";     break; 
      case  martes    : cout << "martes";    break; 
      case  miercoles : cout << "miercoles"; break; 
      case  jueves    : cout << "jueves";    break; 
      case  viernes   : cout << "viernes";   break; 
      case  sabado    : cout << "sabado";    break; 
      case  domingo   : cout << "domingo";   break; 
   }
   cout << " " << dia << " de ";
   switch (mes) {
      case  enero      : cout << "enero";      break; 
      case  febrero    : cout << "febrero";    break; 
      case  marzo      : cout << "marzo";      break; 
      case  abril      : cout << "abril";      break; 
      case  mayo       : cout << "mayo";       break; 
      case  junio      : cout << "junio";      break; 
      case  julio      : cout << "julio";      break; 
      case  agosto     : cout << "agosto";     break; 
      case  septiembre : cout << "septiembre"; break; 
      case  octubre    : cout << "octubre";    break; 
      case  noviembre  : cout << "noviembre";  break;
      case  diciembre  : cout << "diciembre";  break;
   }
   cout << " de " << anio << endl;
      
   return 0;
}
