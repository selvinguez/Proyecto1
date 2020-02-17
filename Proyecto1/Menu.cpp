#include "Menu.h"
#include <iostream>
#include "Juego.h"
#include <iostream>
#include <windows.h>
#include "Funciones.h"
using namespace std;

void menu::menu1() {
	menu men;
	int opcion = 0;
	Juego jugar;
	Funciones fun;
	fun.gotoXY(0, 1);
	cout << "Bienvenidos al Juego de Carrito\nHonduras Ludificado";
	fun.gotoXY(0,5);
	cout << "1. JUGAR\n2. ACERCA\n3. Salir\n\n\n";
	
	cout << "Ingrese Opcion: ";
    cin >> opcion;

	if (opcion == 1) {
		system("cls");
		jugar.Empezar();

	}
	else if (opcion == 2) {
		system("cls");
		Sleep(1000);
		fun.gotoXY(4, 4);
		cout << "Hecho Por:  Selvin Rodriguez";
		fun.gotoXY(4, 5);
		cout << "Juego de carrito";
		fun.gotoXY(4, 6);
		cout << "Honduras Ludificado";
		Sleep(5000);
		system("cls");
		men.menu1();
	}
	else if (opcion == 3) {
		system("cls");
		fun.gotoXY(0, 5);
		cout << "Dios te Bendiga\nGracias por jugar\nAdios!!!";
		Sleep(5000);
		exit(0);
	
	}
	else {
		cout << "Opcion equivocada";
	}


}