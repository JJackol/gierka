#pragma once
#include "GameObject.h"
#include <allegro5/bitmap.h>
#include <allegro5/bitmap_io.h>


GameObject::GameObject() :angle{ 0 }, width{ 0 }, height{ 0 }, radius{ 0 }

{
}

void GameObject::load_bitmap(const char* file)
{
	my_bitmap = al_load_bitmap(file);
}

GameObject::GameObject(Wektor pos,  int w=0, int h=0, float r=0,float alpha=0,
						bool col =false)
	:my_pos{ pos },		angle {	alpha }, 
	width{ w },			height{ h }, 
	radius{ r },		collision{ col }
{


}

void GameObject::draw(Wektor camera)
{
	al_draw_rotated_bitmap(my_bitmap, width / 2, height / 2, my_pos.x, my_pos.y, angle, 0);
}


GameObject::~GameObject()
{
}
