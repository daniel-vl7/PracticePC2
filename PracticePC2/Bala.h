#pragma once
#include <iostream>

using namespace System::Drawing;

class Bala {
private:
	int x, y;
	int dx, dy;
	int width, height;
	int direction;
	bool visible;

public:
	Bala(int x,int y, int wi, int he, int dir){
		width = wi;
		height = he;
		direction = dir;
		dx = dy = 30;
		visible = true;
		this->x = x;
		this->y = y;
	}
	~Bala(){}

	void dibujar(Graphics^ g, Bitmap^ bmp){
		g->DrawImage(bmp, x, y, width * 0.03, height * 0.03);
	}
	//w = 2
	// s = 3
	// a =  1
	// d = 4
	void mover(Graphics^ g){
		if (direction == 3 && y + height * 0.03 <= g->VisibleClipBounds.Height){
			y += dy;
		}
		if (direction == 2 && y >= 0) {
			y -= dy;
		}
		if (direction == 4 && x + width * 0.03 <= g->VisibleClipBounds.Width) {
			x += dx;
		}
		if (direction == 1 && x >= 0) {
			x -= dx;
		}
	}

	int getX() { return x; }
	int getXWidth() { return x + width * 0.03; }
	int getY() { return y; }
	int getYHeight() { return y + height * 0.03; }

	bool getVisible() { return visible; }
	void setVisible(bool value) { visible = value; }

	Rectangle getRectangle() {
		return  Rectangle(x, y, width * 0.03, height * 0.03);
	}
};