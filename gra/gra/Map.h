#pragma once
#include "Wektor.h"
#include "DynamicObject.h"

class Map
{
public:
	virtual void keep_on_map(DynamicObject& object);
	virtual void draw(Wektor top_left);
	Map();
	~Map();
};

