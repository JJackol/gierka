#include "GameObject.h"
#include <allegro5/bitmap.h>
#include <allegro5/bitmap_io.h>


GameObject::GameObject() :angle{ 0 }, width{ 0 }, height{ 0 }, radius{ 0 }

{
}

GameObject::GameObject(Wektor pos,  int w=0, int h=0, int r=0,float alpha=0,
						bool col =false)
	:my_pos{ pos },		angle {	alpha }, 
	width{ w },			height{ h }, 
	radius{ r },		colision{ col }
{


}

void GameObject::draw(Wektor camera)
{
}


GameObject::~GameObject()
{
}
