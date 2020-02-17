#include "Funciones.h"
#include <windows.h> 
#include <iostream>

using namespace std;

void Funciones::gotoXY(int x,int y)
{
	COORD cordenada;
	cordenada.X = x;
	cordenada.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cordenada);

}
 int Funciones::matriz[12][20];

void Funciones::dibujarpunto(int x,int y) {
	if (y < 20 && y >= 0) {
		matriz[x][y] = 1;
	}
}

void Funciones::resetiarTabla() {
	for (int y = 0;y < 20;y++) {
		for (int x = 1;x < 12;x++) {
			matriz[x][y] = 0;
		}
	}
}




