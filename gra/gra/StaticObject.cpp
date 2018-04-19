#pragma once
#include "StaticObject.h"


StaticObject::StaticObject():GameObject()
{
}

StaticObject::StaticObject(Wektor pos, float w, float h) 
{
	top_left = pos;
	width = w;
	height = h;
	botom_right = top_left + Wektor{ w, h };
}

StaticObject::~StaticObject()
{
	al_destroy_bitmap(my_bitmap);
}
