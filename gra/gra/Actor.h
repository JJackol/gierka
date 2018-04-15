#pragma once
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

#include "Wektor.h"
#include "DynamicObject.h"

class Actor : public DynamicObject
{
public:
	typedef char stat;
	Actor();
	~Actor();

	int hp;
	int mana;
	float max_speed=10;
	stat ap;
	stat strenght;
	stat dex;
	stat armor;
};



