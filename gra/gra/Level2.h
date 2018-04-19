#pragma once
#include "Level.h"

class Level2 :
	public Level
{
public:
	Map2 map;

	StaticObject ob1;
	Level2();
	Level2(ALLEGRO_DISPLAY*);
	~Level2();
};

