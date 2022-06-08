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

public:

	Personaje(int width, int height){
		Random^ r;
		x = r->Next(60,150);
		y = r->Next(60, 150);
		dx = dy = 5;
		idx = idy = 0;
		visible = true;
		this->width = width;
		this->height = height;
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

	Rectangle getRetangle() {
		return Rectangle(x, y, width, height);
	}

};