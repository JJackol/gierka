#pragma once
#include "Map.h"
class Map2 :
	public Map
{
public:
	Wektor top_left;
	Wektor botom_right;
	ALLEGRO_BITMAP* my_bmp;

	void keep_on_map(DynamicObject& object);
	bool is_on_map(DynamicObject & object);
	void draw(Wektor top_left);
	Map2();
	~Map2();
};

