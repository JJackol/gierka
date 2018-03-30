#pragma once
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

#include "Wektor.h"

class Actor
{
public:
	typedef char stat;
	Actor();
	~Actor();
private:
	Wektor my_pos;
	float my_angle_pos;
	int w;
	int h;
};



