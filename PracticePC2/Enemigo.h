#pragma once
#include "Personaje.h"

class Enemigo : public Personaje {

public:
	
	Enemigo(int width, int height) :Personaje(width, height) {}
	~Enemigo(){}

	void mover(Graphics^ g){

		if (x + width * 1.0 > g->VisibleClipBounds.Width || x < 0)
		{
			dx *= -1;
			if (dx < 0) idy = 1;
			else idy = 2;
			x += dx;
		}
		
		else {
			if (y + height * 1.0 > g->VisibleClipBounds.Height || y < 0)
			{
				dy *= -1;
				if (dy < 0) idy = 3;
				else idy = 0;
				y += dy;
			}
		}

		idx++;
		if (idx > 3) idx = 0;
	}
};