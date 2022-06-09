#pragma once
#include "Personaje.h"

class Heroe : public Personaje {

public:

	Heroe(int width, int height, int direction) : Personaje(width, height, direction) {}
	~Heroe(){}

	void mover(Graphics^ g, char i) {
		switch (i)
		{
			//w = 2
	// s = 3
	// a =  1
	// d = 4
		case 'A':
			if (x > 0) {
				x -= dx;
				idy = 1;
				direction = 1;
			}
			break;

		case 'D':
			if (x + width * 1.0 < g->VisibleClipBounds.Width) {
				x += dx;
				idy = 2;
				direction = 4;
			}
			break;

		case 'W':
			if (y > 0) {
				y -= dy;
				idy = 3;
				direction = 2;
			}
			break;

		case 'S':
			if (y + height * 1.0 < g->VisibleClipBounds.Height) {
				y += dy;
				idy = 0;
				direction = 3;
			}
			break;
		}

		idx++;
		if (idx > 3)idx = 0;
	}
};