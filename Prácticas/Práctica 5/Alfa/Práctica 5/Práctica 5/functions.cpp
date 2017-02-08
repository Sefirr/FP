#include "functions.h"
#include <iomanip>

bool cargarjugadores(tListaJugadores &lista) {
	int dato;
	tJugador jugador_E;
	ifstream entrada;
	char c;
	bool ok = true;

	lista.capacidad = MAX_USUARIOS;
	lista.cont = 0;

	entrada.open("jugadores.txt");
	if(!entrada.is_open())
		ok = false;
	else {
		entrada >> jugador_E.usuario;	
		jugador_E.comprados.cont = 0;
		while((strcmp(jugador_E.usuario,"X") != 0) && (lista.cont < MAX_USUARIOS)) {
			entrada >> jugador_E.password;
			entrada.get(c);
			entrada.getline(jugador_E.universidad, MAX_CHAR);
			entrada >> jugador_E.dinero;
			entrada >> jugador_E.prestigio;
			entrada >> dato;
			while(dato != -1) {
				jugador_E.comprados.elem[jugador_E.comprados.cont] = dato;
				jugador_E.comprados.cont++;
				
				entrada >> dato;
			}

			lista.jugador[lista.cont] = jugador_E;
			jugador_E.comprados.cont = 0;
			lista.cont++;
			
			if(lista.cont == lista.capacidad)
				ampliar_jugadores(lista);

			entrada >> jugador_E.usuario;

		}
	}
	entrada.close();

	return ok;
}

bool cargaredificios(tListaEdificios &lista) {
	tEdificio edificio;
	ifstream entrada;
	int estado;
	char c;
	bool ok = true;

	lista.capacidad = MAX_EDIFICIOS;
	lista.cont = 0;

	entrada.open("edificios.txt");
	if(!entrada.is_open())
		ok = false; 
	else {
		entrada >> edificio.codigo;
		while((edificio.codigo != -1) && (lista.cont < MAX_EDIFICIOS))
		{
			entrada.get(c);
			entrada.getline(edificio.nombre, MAX_CHAR);
			entrada >> edificio.precio;
			entrada >> edificio.dinero;
			entrada >> edificio.prestigio;
			entrada >> estado;

			switch(estado) {
			case 0: 
				edificio.estado = DISPONIBLE;
				break;
			case 1: 
				edificio.estado = COMPRADO;
				break; 
			case 2: 
				edificio.estado = BORRADO;
				break;
			}

			lista.edificios[lista.cont] = edificio;
			lista.cont++;

			if(lista.cont == lista.capacidad)
				ampliar_edificios(lista);

			entrada >> edificio.codigo;

		}

	}
	entrada.close();

	return ok;
}

int menu(tListaEdificios &edificios, tListaJugadores &jugadores, int pos) {
	int opcion;
	int pos_edificio;

	cout << endl << "Menu de juego" << endl;
	cout << "================" << endl;
	cout << "Bienvenido " << jugadores.jugador[pos].usuario << ", elige una opcion: " << endl << endl;
	cout << "1 - Ver mis edificios" << endl;
	cout << "2 - Ver los edificios disponibles" << endl;
	cout << "3 - Comprar un edificio" << endl;
	cout << "4 - Ver la clasificación (ordenada por dinero)" << endl;
	cout << "5 - Ver la clasificación (ordenada por prestigio)" << endl;
	cout << "0 - Cerrar la sesión" << endl;
	cout << "Opción: ";
	cin >> opcion;

	switch(opcion) {
	case 0: break;
	case 1: 
		for(int i = 0; i < jugadores.jugador[pos].comprados.cont; i++) {
			if(buscarEdificio(edificios, jugadores.jugador[pos].comprados.elem[i], pos_edificio))
				mostrarEdificio(edificios.edificios[pos_edificio]);
		}
		break;
	case 2: 
		for(int i = 0; i < edificios.cont; i++) {
			if(edificios.edificios[i].estado == DISPONIBLE)
				mostrarEdificio(edificios.edificios[i]);
		}
		break;
	case 3:
		comprarEdificio(jugadores.jugador[pos], edificios);
		break;
	case 4: 
		clasificaciondinero(jugadores);
		break;
	case 5: 
		clasificacionprestigio(jugadores);
		break;
	default: cout << endl << "Opción no válida, escoge otra." << endl;
	}

	return opcion;
}

int menu_admin(tListaJugadores &jugadores, tListaEdificios &edificios) {
	int opcion;
	int pos;
	int buscado;
	bool valido;
	tCadena nombre;

	cout << endl << "Menú de administración" << endl;
	cout << "======================" << endl << endl;
	cout << "1 - Ver el listado de edificios" << endl;
	cout << "2 - Nuevo edificio" << endl;
	cout << "3 - Borrar un edificio" << endl;
	cout << "4 - Ver el listado de jugadores" << endl;
	cout << "5 - Nuevo jugador" << endl;
	cout << "6 - Borrar un jugador" << endl;
	cout << "7 - Ejecutar un turno" << endl;
	cout << "8 - Ver la clasificación" << endl;
	cout << "0 - Cerrar la sesión" << endl;
	cout << "Opción: ";
	cin >> opcion;

	switch(opcion) {
	case 0: break;
	case 1: 
		for(int i = 0; i < edificios.cont; i++) {
			mostrarEdificio(edificios.edificios[i]);
		}
		break;
	case 2: 
		if(insertarEdificio(edificios))
			cout << "Edificio insertado con éxito.";
		else
			cout << "ERROR al insertar: La lista está llena o el código del edificio está duplicado";
		break;
	case 3: 
		cout << "Código del edificio: ";
		cin >> buscado;

		if(bajaEdificio(edificios, buscado))
			cout << "Edificio borrado con éxito.";
		else
			cout << "El edificio no existe o no está disponible.";
		break;
	case 4: 
		for(int i = 0; i < jugadores.cont; i++) {
			mostrarJugador(jugadores.jugador[i], edificios);
		}
		break;
	case 5: 
		if(insertarJugador(jugadores, valido) && valido)
			cout << "Jugador insertado con éxito.";
		else if(!valido)
			cout << "ERROR - Nombre de jugador inválido.";
		else
			cout << "ERROR al insertar: La lista está llena o el usuario está duplicado."; 
		break;
	case 6: 
		cout << "Nombre del jugador: ";
		cin >> nombre;

		if(bajaJugador(jugadores, nombre,edificios,pos))
			cout << "Eliminando edificios del jugador..." << endl << "Jugador eliminado.";
		else
			cout << "El jugador no existe.";
		break;
	case 7: 
		ejecutar_turno(jugadores, edificios);
		break;
	case 8: 
		clasificaciondinero(jugadores);
		break;
	default: cout << endl << "Opción no válida, escoge otra." << endl;
	}

	return opcion;
}

void clasificaciondinero(tListaJugadores &lista) {

	ordenardinero(lista);
	cout << "Posición  " << " Dinero  " << " Nombre  " << endl;
	cout << "========  " << " ======  " << " ======  " << endl;
	for(int i = 0; i < lista.cont; i++) {
		cout << setw(6) << i + 1 << " " << setw(10) << right << lista.jugador[i].dinero << "   " << lista.jugador[i].universidad << endl;
	}
}

void clasificacionprestigio(tListaJugadores &lista) {

	ordenarprestigio(lista);
	cout << "Posición  " << " Prest.  " << " Nombre  " << endl;
	cout << "========  " << " ======  " << " ======  " << endl;
	for(int i = 0; i < lista.cont; i++) {
		cout << setw(6) << i + 1 << " " << setw(10) << right << lista.jugador[i].prestigio << "   " << lista.jugador[i].universidad << endl;
	}

}

void ordenardinero(tListaJugadores &lista) {

	bool inter = true;
	int i = 0;
	while((i < lista.cont) && inter) {
		inter = false;
		for(int j = lista.cont - 1; j > i; j--) 
			if(lista.jugador[j].dinero > lista.jugador[j - 1].dinero) {
				tJugador tmp;
				tmp = lista.jugador[j];
				lista.jugador[j] = lista.jugador[j - 1];
				lista.jugador[j - 1] = tmp;
				inter = true;
			}
			if(inter) i++;
	}
}

void ordenarprestigio(tListaJugadores &lista) {

	bool inter = true;
	int i = 0;
	while((i < lista.cont) && inter) {
		inter = false;
		for(int j = lista.cont - 1; j > i; j--) 
			if(lista.jugador[j].prestigio > lista.jugador[j - 1].prestigio) {
				tJugador tmp;
				tmp = lista.jugador[j];
				lista.jugador[j] = lista.jugador[j - 1];
				lista.jugador[j - 1] = tmp;
				inter = true;
			}
			if(inter) i++;
	}

}

void ejecutar_turno(tListaJugadores &jugadores, tListaEdificios edificios) {
	int pos;
	for(int i = 0; i < jugadores.cont; i++) {
		for(int j = 0; j < jugadores.jugador[i].comprados.cont; j++) {
			buscarEdificio(edificios, jugadores.jugador[i].comprados.elem[j], pos);
			jugadores.jugador[i].dinero += edificios.edificios[pos].dinero;
			jugadores.jugador[i].prestigio += edificios.edificios[pos].prestigio;
		}
	}

}

bool login(tListaJugadores lista, int &intentos, bool &session_admin, int &i) {
	intentos = 0; 
	tJugador jugador_E;
	bool session_OK = false;
	session_admin = false;

	bool encontrado = false;

	do {
		comprobarUsuario(jugador_E, lista,i,encontrado);
		comprobarPass(jugador_E,lista, i, intentos, encontrado, session_OK, session_admin);

		if(strcmp(jugador_E.usuario, "salir") == 0 || strcmp(jugador_E.usuario, "s") == 0)
			encontrado = true;
	} while(!encontrado);

	return session_OK;
}

void comprobarUsuario(tJugador &jugador_E, tListaJugadores lista, int &i, bool &encontrado) {
	encontrado = false;
	//Logueo de usuarios
	cout << "Usuario: ";
	cin >> jugador_E.usuario;	
	
	if((strcmp(jugador_E.usuario,"admin") == 0))
		encontrado = true;

	i = 0;
	while (!encontrado && (strcmp(jugador_E.usuario, "salir") != 0 || (strcmp(jugador_E.usuario, "s") != 0)) && (i < lista.cont)) {
		if(strcmp(jugador_E.usuario,lista.jugador[i].usuario) == 0 || (strcmp(jugador_E.usuario,"admin") == 0))
			encontrado = true;
		else if (strcmp(jugador_E.usuario, lista.jugador[i].usuario) != 0) 
			i++;
	}
}

void comprobarPass(tJugador jugador_E, tListaJugadores lista, int i, int &intentos, bool encontrado, bool &session_OK, bool &session_admin) {

	if (encontrado) {
			cout << "Contraseña: ";
			cin >> jugador_E.password;

			if(strcmp(jugador_E.usuario,"admin") == 0 && strcmp(jugador_E.password,"12345") == 0)
				intentos = 3;

			while ((intentos < 2) && strcmp(jugador_E.password, lista.jugador[i].password) != 0) {
				cout << "Contraseña: " ;
				cin >> jugador_E.password;
				intentos++;
			}

			if((strcmp(jugador_E.usuario, "admin") == 0) && (strcmp(jugador_E.password,"12345") == 0))
				session_admin = true;
			else if(strcmp(jugador_E.password, lista.jugador[i].password) == 0)
				session_OK = true;
		}
}

void listaedificios(tListaEdificios lista) {

	ofstream salida;

	salida.open("edificios.txt");

	for(int i = 0; i < lista.cont; i++) {
		salida << lista.edificios[i].codigo << endl;
		salida << lista.edificios[i].nombre << endl;
		salida << lista.edificios[i].precio << endl;
		salida << lista.edificios[i].dinero << endl;
		salida << lista.edificios[i].prestigio << endl;
		salida << lista.edificios[i].estado << endl;
	}
	salida << -1;
	salida.close();
}

void listajugadores(tListaJugadores lista) {

	ofstream salida;

	salida.open("jugadores.txt");

	for(int i = 0; i < lista.cont; i++) {
		salida << lista.jugador[i].usuario << endl;
		salida << lista.jugador[i].password << endl;
		salida << lista.jugador[i].universidad << endl;
		salida << lista.jugador[i].dinero << endl;
		salida << lista.jugador[i].prestigio << endl;
		for(int j = 0; j < lista.jugador[i].comprados.cont; j++) {
			salida << lista.jugador[i].comprados.elem[j] << endl;
		}
		salida << -1 << endl;
	}
	salida << "X";
	salida.close();
}

void ampliar_jugadores(tListaJugadores &jugadores) {

	tLista aux_j = new tJugador[jugadores.capacidad];

	for(int i = 0; i < jugadores.cont; i++) {
		aux_j[i] = jugadores.jugador[i];
	}

	tLista var = aux_j;
	aux_j = jugadores.jugador; 
	jugadores.jugador = var;

	
	delete [] aux_j;

	jugadores.capacidad = (jugadores.capacidad * 3) / 2 + 1;

}

void ampliar_edificios(tListaEdificios &edificios) {

	tEdificios aux_e = new tEdificio[edificios.capacidad];

	for(int i = 0; i < edificios.cont; i++) {
		aux_e[i] = edificios.edificios[i];
	}

	tEdificios var = aux_e;
	aux_e = edificios.edificios; 
	edificios.edificios = var;

	delete [] aux_e;

	edificios.capacidad = (edificios.capacidad * 3) / 2 + 1;

}