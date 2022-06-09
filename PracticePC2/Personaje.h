#pragma once
#include <iostream>

using namespace System::Drawing;
using namespace System;
class Personaje
{

protected:

	int x, y;
	int dx, dy;
	int idx, idy;
	int width, height;
	bool visible;
	int direction;

public:

	Personaje(int width, int height,int direction){
		
		x = rand() % 800;
		y = rand() % 500;
		dx = dy = 8;
		idx = idy = 0;
		visible = true;
		this->width = width;
		this->height = height;
		this->direction = direction;
	}

	~Personaje(){}

	void dibujar(Graphics^ g, Bitmap^ bmp) {
		Rectangle section = Rectangle(idx * width, idy * height, width, height);
		Rectangle zoom = Rectangle(x, y, width * 1.0, height * 1.0);
		g->DrawImage(bmp, zoom, section, GraphicsUnit::Pixel);
	}

	virtual void mover(){}

	bool getVisible() { return visible; }
	void setVisible(bool value) { visible = value; }

	int getX() { return x; }
	int getY() { return y; }
	int getDirection() { return direction; }

	Rectangle getRetangle() {
		return Rectangle(x, y, width, height);
	}

};