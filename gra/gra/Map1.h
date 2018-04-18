#pragma once
#include "Map.h"
class Map1 :
	public Map
{
public:
	Wektor centre;
	const float radius;
	ALLEGRO_BITMAP* my_bmp;

	void keep_on_map(DynamicObject& object);
	bool is_on_map(DynamicObject & object, Wektor offside);
	Map1();
	~Map1();
};

