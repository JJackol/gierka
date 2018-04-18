#include "StaticObject.h"
#include <allegro5/bitmap_io.h>


StaticObject::StaticObject():GameObject()
{
}

StaticObject::StaticObject(Wektor pos, const char* filename, float w, float h) 
{
	my_pos = pos;
	width = w;
	height = h;
	my_bitmap = al_load_bitmap(filename);
}

StaticObject::~StaticObject()
{
	al_destroy_bitmap(my_bitmap);
}
