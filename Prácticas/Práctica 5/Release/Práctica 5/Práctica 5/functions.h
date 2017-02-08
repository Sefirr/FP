#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "listaedificios.h"
#include "listajugadores.h"
#include "constants.h"
#include <iostream>
using namespace std;

/* Las funciones booleanas cargarjugadores ycargaredificios cargan las listas de jugadores y de edificios. Y devuelven un booleano a true, si se han
cargado correctamente. En caso contrario, false.
Constan de un parametro llamado lista que se modifica ya que al cargar los datos de las listas desde un fichero, estas modificando la lista de edificios y jugadores.*/
bool cargarjugadores(tListaJugadores &lista);
bool cargaredificios(tListaEdificios &lista);
/* La función booleana login hace que el usuario acceda al juego, si el usuario que ha introducido es correcto. Si no es correcto, devuelve el booleano
en false. Consta de cuatro parámetros:
- El parámetro lista no se modifica ya que solo busca el nombre del usuario que ha introducido el internauta, no modifica la lista.
- El parámetro intentos si se modifica ya que conforme el usuario se equivoca de contraseña los intentos incrementan, hasta un máximo de tres.
- El parámetro session_admin si se modifica ya que indica si la session de administrado se ha ejecutado y carga el menu de administración.
- El parámetro i si se modifica ya que si encuentra al jugador, devuelve su posición exacta. Esto solo sirve para que una vez logueados, en el 
menu de usuario le de la bienvenida al jugador por su nombre.*/
bool login(tListaJugadores lista, int &intentos, bool &session_admin, int &i);
/* El procedimiento comprobarUsuario busca el usuario que ha introducido el usuario en la lista y comprueba si existe.
Constra de cuatro parámetros:
- El parametro jugador_E se modifica ya que cuando tu te logueas introduces un nick y un password que puedes ir modificando hasta que metes el correcto.
- El parámetro lista no se modifica ya que es un parámetro de entrada.
- El parámetro i se modifica ya que es un parámetro de salida.
- El parámetro encontrado si se modifica ya que es un parámetro de salida.*/
void comprobarUsuario(tJugador &jugador_E, tListaJugadores lista, int &pos, bool &encontrado);
/* El procedimiento comprobarPass comprueba si la contraseña es correcta.Si es correcta modifica los parámetros de salida session_OK o session_admin
indicando si se tiene que ejecutar el menu de usuario o de administración. El resto de parámetros excepto intentos, son de entrada debido a que toman
los valores de comprobarUsuario.*/
void comprobarPass(tJugador jugador_E, tListaJugadores lista, int i, int &intentos, bool encontrado, bool &session_OK, bool &session_admin);
/* La función entera menu muestra el menú y ejecuta la opción del usuario.
Consta de tres parámetros:
- El parámetro edificios se modifica ya que por ejemplo, si compras un edificio estás modificando la lista de edificios.
- El parámetro jugadores se modifica ya que por ejemplo, al comprar un edificio estás modificando el dinero que tiene el usuario.
- El parámetro pos no se modifica ya que es un parámetro de entrada.*/
int menu(tListaEdificios &edificios, tListaJugadores &jugadores, int pos);
/* La función entera menu_admin muestra el menú de administración y ejecuta la opción correspondiente.
Consta de dos parámetros:
- El parámetro edificios se modifica ya que por ejemplo, si añades un edificio estás modificando la lista de edificios.
- El parámetro jugadores se modifica ya que por ejemplo, al añadir un edificio estás modificando la lista de edificios.

Ambas funciones menu y menu_admin son enteras ya que devuelven la opción al programa principal para que al pulsar 0 se salga del menu.*/
int menu_admin(tListaJugadores &jugadores, tListaEdificios &edificios);
/* El procedimiento ejecutar turno es el encargado de ejecutar un turno, modificando el dinero y el prestigio del usuario en base a los edificios que tenga.
Consta de dos parámetros:
- El parámetro jugadores, se modifica ya que se modifica el dinero y el prestigio del usuario, al ejecutar turnos.
- El parámetro edificios no se modifica, ya que no modificamos nada de la lista de edificios, solo de la lista de jugadores.*/
void ejecutar_turno(tListaJugadores &jugadores, tListaEdificios edificios);
/* Todas estas funciones son las encargadas de ordenar y mostrar la clasificación del usuario.
Solo tienen un parámetro lista que modifican ya que al ordenar la lista, modifica la posición de los elementos  del array de jugadores. Por tanto,
el parámetro se modifica.*/
void ordenardinero(tListaJugadores &lista);
void ordenarprestigio(tListaJugadores &lista);
void clasificaciondinero(tListaJugadores &lista);
void clasificacionprestigio(tListaJugadores &lista);
/* Los procedimientos listaedificios y listajugadores copian las listas modificadas al archivo. Para que una vez,  nos vayamos del programa no se
pierda información de los jugadores y/o edificios.
Tienen un parámetro lista que no se modifica ya que recorren las dos listas y las copian en los archivos edificios.txt y jugadores.txt , pero no las modifican.*/
void listaedificios(tListaEdificios lista);
void listajugadores(tListaJugadores lista);
void ampliar_jugadores(tListaJugadores &jugadores);
void ampliar_edificios(tListaEdificios &edificios);

#endif