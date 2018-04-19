#include "DynamicObject.h"
#include <allegro5/bitmap_draw.h>


void DynamicObject::update_state(double dt, Wektor target)
{
	target.normalize();
	this->update_velocity(target, 0);
	this->update_position(dt);
	if(hp<=0)
	{
		alive = false;
		collision = false;
	}
}

double DynamicObject::some_func(double x)
{
	return x * x;
}

void DynamicObject::update_velocity(Wektor target, double curr_time)
{
	target *= max_speed;
	velocity += (target - velocity)*0.15;
}


void DynamicObject::update_position(double dt)
{
	my_pos += (velocity * dt);
}

void DynamicObject::draw(Wektor camera)
{
	al_draw_rotated_bitmap(my_bitmap, width / 2, height / 2, my_pos.x-camera.x, my_pos.y-camera.y, angle, 0);
}


DynamicObject::DynamicObject()
{
}

DynamicObject::DynamicObject(Wektor pos,  int w, int h, int r,float alpha, bool col, Wektor vel)

	:GameObject(pos,  w, h, r, alpha, col), velocity{vel}
{
}


DynamicObject::~DynamicObject()
{
}
