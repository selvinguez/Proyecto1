#pragma once
#ifndef CARRO_H
#define CARRO_H
#include "CarroEnemigo.h"

class Carro{
public:
	int PosicionX=2;
	int PosicionY=16;
	int vidas;

	void carro();
	void dibujar();
	void Derecha();
	void Izquierda();
	void checkiarColusion(CarroEnemigo*, bool*,Carro*,CarroEnemigo*);




};

#endif 
