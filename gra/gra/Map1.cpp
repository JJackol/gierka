#include "Map1.h"
#include <allegro5/bitmap_io.h>


void Map1::keep_on_map(DynamicObject& object)
{
	Wektor offside=(object.my_pos - centre);
	if(!this->is_on_map(object, offside))
	{	
		object.my_pos+= normalize(offside*100)*(radius-5)-offside ;
	}

}

bool Map1::is_on_map(DynamicObject& object, Wektor offside)
{
	return offside * offside <= (radius - object.radius) * (radius - object.radius);
}

Map1::Map1() : centre{ 1496,1506 }, radius{1164}
{
	my_bmp = al_load_bitmap("bmp/map1.png");
}


Map1::~Map1()
{
	al_destroy_bitmap(my_bmp);
	
	
}
