#pragma once
#include "Wektor.h"
#include <allegro5/allegro.h>

class Projectile
{
public:
	Wektor my_pos;
	Wektor vel;
	int index;
	static float max_speed;
	
	ALLEGRO_BITMAP* bmp;
	static int dmg;
	static float radius;
	void load_resource();
	Projectile();
	Projectile(Wektor start, float angle);
	~Projectile();
};

