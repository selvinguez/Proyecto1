#include "CarroEnemigo.h"
#include "Funciones.h"
#include <cstdlib>

void CarroEnemigo::carroEnemigo() {
	PosicionX = 5;
	PosicionY = -3;
}

void CarroEnemigo::aparencia() {
	if (PosicionY == 20) {
		int randomNo = rand() % 3;
		if (randomNo == 0) {
			PosicionX = 2;

		}
		else if (randomNo == 1) {
			PosicionX = 5;

		}
		else if (randomNo == 2) {
			PosicionX = 8;
		}

		PosicionY = -3;


	}
}

	void CarroEnemigo::dibujar() {
		Funciones car;

		car.dibujarpunto(PosicionX, PosicionY);
		car.dibujarpunto(PosicionX - 1, PosicionY + 1);
		car.dibujarpunto(PosicionX + 1, PosicionY + 1);
		car.dibujarpunto(PosicionX, PosicionY + 1);
		car.dibujarpunto(PosicionX, PosicionY + 2);
		car.dibujarpunto(PosicionX - 1, PosicionY + 3);
		car.dibujarpunto(PosicionX + 1, PosicionY + 3);
		car.dibujarpunto(PosicionX, PosicionY + 3);
	
	
	}

	void CarroEnemigo::movimiento() {
		PosicionY++;
	}




