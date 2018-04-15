#pragma once
#include "Wektor.h"
#include <allegro5/bitmap.h>

class Projectile
{
public:
	Wektor my_pos;
	Wektor vel;
	static ALLEGRO_BITMAP* bmp;
	int dmg;
	float radius;
	Projectile();
	~Projectile();
};

