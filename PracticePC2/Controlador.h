#pragma once

#include "Enemigo.h"
#include "Heroe.h"
#include "Bala.h"
#include <vector>

using namespace std;

class Controlador {
private:
	vector<Enemigo*>enemigos;
	vector<Bala*>balas;
public:
	Controlador(){}
	~Controlador(){}

	void agregarEnemigo(Enemigo* e) {
		enemigos.push_back(e);
	}

	void agregarBala(Bala* b) {
		balas.push_back(b);
	}

	void dibujarTodo(Graphics^ g, Bitmap^ bmpEnemy, Bitmap^ bmpBala) {
		for (int i = 0; i < enemigos.size(); i++)
		{
			enemigos[i]->dibujar(g, bmpEnemy);
		}
		for (int i = 0; i < balas.size(); i++)
		{
			balas[i]->dibujar(g, bmpBala);
		}

	}

	void moverTodo(Graphics^ g) {
		for (int i = 0; i < enemigos.size(); i++)
		{
			enemigos[i]->mover(g);
		}
		for (int i = 0; i < balas.size(); i++)
		{
			balas[i]->mover(g);
		}
	}

	void colision() {

	}
};