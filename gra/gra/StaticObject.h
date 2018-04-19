#pragma once
#include "GameObject.h"
#include <allegro5/allegro.h>

class StaticObject :
	public GameObject
{
public:
	Wektor top_left;
	Wektor botom_right;
	StaticObject();
	StaticObject(Wektor pos,float w, float h);
	~StaticObject();
};

