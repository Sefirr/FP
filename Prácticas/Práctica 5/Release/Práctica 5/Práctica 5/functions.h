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
/* La funci�n booleana login hace que el usuario acceda al juego, si el usuario que ha introducido es correcto. Si no es correcto, devuelve el booleano
en false. Consta de cuatro par�metros:
- El par�metro lista no se modifica ya que solo busca el nombre del usuario que ha introducido el internauta, no modifica la lista.
- El par�metro intentos si se modifica ya que conforme el usuario se equivoca de contrase�a los intentos incrementan, hasta un m�ximo de tres.
- El par�metro session_admin si se modifica ya que indica si la session de administrado se ha ejecutado y carga el menu de administraci�n.
- El par�metro i si se modifica ya que si encuentra al jugador, devuelve su posici�n exacta. Esto solo sirve para que una vez logueados, en el 
menu de usuario le de la bienvenida al jugador por su nombre.*/
bool login(tListaJugadores lista, int &intentos, bool &session_admin, int &i);
/* El procedimiento comprobarUsuario busca el usuario que ha introducido el usuario en la lista y comprueba si existe.
Constra de cuatro par�metros:
- El parametro jugador_E se modifica ya que cuando tu te logueas introduces un nick y un password que puedes ir modificando hasta que metes el correcto.
- El par�metro lista no se modifica ya que es un par�metro de entrada.
- El par�metro i se modifica ya que es un par�metro de salida.
- El par�metro encontrado si se modifica ya que es un par�metro de salida.*/
void comprobarUsuario(tJugador &jugador_E, tListaJugadores lista, int &pos, bool &encontrado);
/* El procedimiento comprobarPass comprueba si la contrase�a es correcta.Si es correcta modifica los par�metros de salida session_OK o session_admin
indicando si se tiene que ejecutar el menu de usuario o de administraci�n. El resto de par�metros excepto intentos, son de entrada debido a que toman
los valores de comprobarUsuario.*/
void comprobarPass(tJugador jugador_E, tListaJugadores lista, int i, int &intentos, bool encontrado, bool &session_OK, bool &session_admin);
/* La funci�n entera menu muestra el men� y ejecuta la opci�n del usuario.
Consta de tres par�metros:
- El par�metro edificios se modifica ya que por ejemplo, si compras un edificio est�s modificando la lista de edificios.
- El par�metro jugadores se modifica ya que por ejemplo, al comprar un edificio est�s modificando el dinero que tiene el usuario.
- El par�metro pos no se modifica ya que es un par�metro de entrada.*/
int menu(tListaEdificios &edificios, tListaJugadores &jugadores, int pos);
/* La funci�n entera menu_admin muestra el men� de administraci�n y ejecuta la opci�n correspondiente.
Consta de dos par�metros:
- El par�metro edificios se modifica ya que por ejemplo, si a�ades un edificio est�s modificando la lista de edificios.
- El par�metro jugadores se modifica ya que por ejemplo, al a�adir un edificio est�s modificando la lista de edificios.

Ambas funciones menu y menu_admin son enteras ya que devuelven la opci�n al programa principal para que al pulsar 0 se salga del menu.*/
int menu_admin(tListaJugadores &jugadores, tListaEdificios &edificios);
/* El procedimiento ejecutar turno es el encargado de ejecutar un turno, modificando el dinero y el prestigio del usuario en base a los edificios que tenga.
Consta de dos par�metros:
- El par�metro jugadores, se modifica ya que se modifica el dinero y el prestigio del usuario, al ejecutar turnos.
- El par�metro edificios no se modifica, ya que no modificamos nada de la lista de edificios, solo de la lista de jugadores.*/
void ejecutar_turno(tListaJugadores &jugadores, tListaEdificios edificios);
/* Todas estas funciones son las encargadas de ordenar y mostrar la clasificaci�n del usuario.
Solo tienen un par�metro lista que modifican ya que al ordenar la lista, modifica la posici�n de los elementos  del array de jugadores. Por tanto,
el par�metro se modifica.*/
void ordenardinero(tListaJugadores &lista);
void ordenarprestigio(tListaJugadores &lista);
void clasificaciondinero(tListaJugadores &lista);
void clasificacionprestigio(tListaJugadores &lista);
/* Los procedimientos listaedificios y listajugadores copian las listas modificadas al archivo. Para que una vez,  nos vayamos del programa no se
pierda informaci�n de los jugadores y/o edificios.
Tienen un par�metro lista que no se modifica ya que recorren las dos listas y las copian en los archivos edificios.txt y jugadores.txt , pero no las modifican.*/
void listaedificios(tListaEdificios lista);
void listajugadores(tListaJugadores lista);
void ampliar_jugadores(tListaJugadores &jugadores);
void ampliar_edificios(tListaEdificios &edificios);

#endif