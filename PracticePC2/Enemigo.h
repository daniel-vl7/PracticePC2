#pragma once
#include "Personaje.h"

class Enemigo : public Personaje {

public:
	
	Enemigo(int width, int height, int direction) :Personaje(width, height, direction) {}
	~Enemigo(){}

	void mover(Graphics^ g){

		if (direction == 1)
		{
			if (x + width * 1.0 > g->VisibleClipBounds.Width || x < 0)
			{
				dx *= -1;
			}
			if (dx > 0) idy = 2;
			else idy = 1;
			x += dx;
		}
		else {
			if (y + height * 1.0 > g->VisibleClipBounds.Height || y < 0)
				dy *= -1;
			if (dy > 0) idy = 0;
			else idy = 3;
			y += dy;
		}

		idx++;
		if (idx > 3) idx = 0;
	}
};