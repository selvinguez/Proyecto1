#include "CarroEnemigo.h"
#include "Funciones.h"
#include "Juego.h"
#include "Carro.h"
#include <thread>
#include <windows.h>  
#include <iostream>
#include <stdio.h>
#include <time.h>
#include "Menu.h"

using namespace std;

Juego ju;
void misMovimientos(Carro* c) {
	while (1) {
		if (GetAsyncKeyState(VK_LEFT) & (0x8000 != 0)) {
			c->Izquierda();

		}
		else if (GetAsyncKeyState(VK_RIGHT) & (0x8000 != 0)) {
			c->Derecha();

		}
	}
}

void Juego::Empezar() {
	menu m;
	Funciones fun;
	Carro Carrito;
	CarroEnemigo enemigo = CarroEnemigo();
	CarroEnemigo enemigo2 = CarroEnemigo();
	int nivel = 1;
	int puntuacion = 0;
	int velocidad = 150;
	int estadistica = 70;
	Carrito.vidas = 3;
	clock_t t, ts;
	int segundos = 0;

	ts = clock() + CLOCKS_PER_SEC;
	for (;;)
	{
		if ((t = clock()) >= ts)
		{


			//Instrucciones 
			fun.gotoXY(2, 5);
			cout  << "Flecha Derecha     --->";
			fun.gotoXY(2, 6);
			cout << "Flecha Izquierda   <---";
			Sleep(3000);
			system("cls");
			thread mySecondThread(misMovimientos, &Carrito);
	
			bool running = true;
			while (running) {
				fun.resetiarTabla();
				enemigo.aparencia();
				enemigo.dibujar();
				enemigo.movimiento();
				enemigo2.aparencia();
				enemigo2.dibujar();
				enemigo2.movimiento();

				Carrito.dibujar();
				Carrito.checkiarColusion(&enemigo, &running, &Carrito,&enemigo2);
				
				if (GetAsyncKeyState(VK_UP) & (0x8000 != 0)) {
					if (velocidad > 100) {
						velocidad -= 5;
						estadistica -= 5;
					}
				}
				

				//Tiempo 
				fun.gotoXY(20, 10);
				cout << "Tiempo: " << ++segundos;
				ts = t + CLOCKS_PER_SEC;
				//Nivel y Puntuacion
				if (segundos % estadistica == 0) {
					//ju.velocidad = ju.velocidad - 5;
					nivel += 1;
					puntuacion += 20;
					velocidad -= 10;
				}
				fun.gotoXY(20, 12);
				cout << "Nivel: " << nivel;
				fun.gotoXY(20, 14);
				cout << "Puntuacion: " << puntuacion;
				//Vidas
				fun.gotoXY(20, 8);
				cout << "Vidas: " << Carrito.vidas;
				//El Win
				if (nivel == 11) {
					Sleep(1000);
					system("cls");
					fun.gotoXY(5, 4);
					cout << "Ganaste!!";
					fun.gotoXY(5, 5);
					cout << "By:Selvin";
					fun.gotoXY(5, 6);
					cout << "Honduras ludificado ";
					fun.gotoXY(0, 0);
					Sleep(1000);
					system("cls");
					m.menu1();

				}


				for (int j = 0;j < 20;j++) {
					for (int i = 0;i < 13;i++) {
						if (i == 0 | i == 10) {
							fun.gotoXY(i, j);
							cout << "S";

						}
						else if (fun.matriz[i][j] == 1) {
							fun.gotoXY(i, j);
							cout << "R";

						}
						else {
							fun.gotoXY(i, j);
							cout << " ";

						}

					}

				}

				Sleep(velocidad);
			
			}
			Sleep(1000);
			system("cls");
			fun.gotoXY(5, 4);
			cout << "GAME OVER!!!";
			fun.gotoXY(5, 5);
			cout << "By:Selvin";
			fun.gotoXY(5, 6);
			cout << "Honduras ludificado ";
			fun.gotoXY(0, 0);
			Sleep(1000);
			velocidad = 150;
			system("cls");
			m.menu1();



		
	
		}
	}


}
