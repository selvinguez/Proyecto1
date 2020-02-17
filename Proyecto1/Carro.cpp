#include "Carro.h"
#include "Funciones.h"


void Carro::carro() {
	PosicionX =2;
	PosicionY=16;
}

void Carro::dibujar() {
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

void Carro::Derecha() {
	if (PosicionX == 5) {
		PosicionX = 8;
	}
	else if (PosicionX==2){
		PosicionX = 5;
	}
}

void Carro::Izquierda() {
	if (PosicionX == 8) {
		PosicionX = 5;
	}
	else if(PosicionX == 5){
		PosicionX = 2;
	}
}




void Carro::checkiarColusion(CarroEnemigo*enemigo, bool* correr ,Carro* ca,CarroEnemigo*enemigo2) {
	    
	if ((enemigo->PosicionY == ca->PosicionY  && enemigo->PosicionX == ca->PosicionX)| (enemigo2->PosicionY == ca->PosicionY && enemigo2->PosicionX == ca->PosicionX)) {
		vidas -= 1;
		if (vidas == 0) {
			*correr = false;
		}
	}
}