#pragma once
#include "Wektor.h"
#include <allegro5/bitmap.h>

class GameObject
{
public:
	Wektor my_pos;
	float angle;
	int width;
	int height;
	int radius;
	bool colision;
	ALLEGRO_BITMAP* my_bitmap;

	GameObject();
	GameObject(Wektor pos, float alpha, int w, int h, int r, bool col);
	~GameObject();
};

