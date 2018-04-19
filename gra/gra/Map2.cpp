#include "Map2.h"
#include <allegro5/bitmap_io.h>
#include "MyGameLib.h"


void Map2::keep_on_map(DynamicObject& object)
{

	if (object.my_pos.x < top_left.x + object.radius)
		object.my_pos.x = top_left.x + object.radius;
	if (object.my_pos.y < top_left.y + object.radius)
		object.my_pos.y = top_left.y + object.radius;
	if (object.my_pos.x > botom_right.x - object.radius)
		object.my_pos.x = botom_right.x - object.radius;
	if (object.my_pos.y > botom_right.y - object.radius)
		object.my_pos.y = botom_right.y - object.radius;

}

bool Map2::is_on_map(DynamicObject& object)
{
	return true;
}

void Map2::draw(Wektor top)
{
	int k = 4;
	top /= k;
	al_draw_scaled_bitmap(my_bmp, top.x, top.y, static_cast<float>(SCREEN_W)/k, static_cast<float>(SCREEN_H)/k,
							0, 0, SCREEN_W, SCREEN_H, 0);
}


Map2::Map2() :top_left(1588,1473),botom_right(8305,5924)
{
	load:
	try
	{
		 InitError err;
		my_bmp = al_load_bitmap("bmp/map3.png");
		if (!my_bmp)throw err;

	}
	catch(InitError err)
	{
		goto load;
	}
}



Map2::~Map2()
{
	al_destroy_bitmap(my_bmp);
}
