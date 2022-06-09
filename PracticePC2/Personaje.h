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
		
		x =100;
		y =100;
		dx = dy = 5;
		idx = idy = 0;
		visible = true;
		this->width = width;
		this->height = height;
	}

	~Personaje(){}

	void dibujar(Graphics^ g, Bitmap^ bmp) {
		Rectangle section = Rectangle(idx * width, idy * height, width, height);
		Rectangle zoom = Rectangle(x, y, width * 0.8, height * 0.8);
		g->DrawImage(bmp, zoom, section, GraphicsUnit::Pixel);
	}

	virtual void mover(){}

	bool getVisible() { return visible; }
	void setVisible(bool value) { visible = value; }

	Rectangle getRetangle() {
		return Rectangle(x, y, width, height);
	}

};