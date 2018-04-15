#include "DynamicObject.h"


double DynamicObject::some_func(double x)
{
	return x * x;
}

void DynamicObject::update_velocity(Wektor target, double curr_time)
{
	target *= max_speed;
	velocity += (target - velocity)*0.1;
}


void DynamicObject::update_position(double dt)
{
	my_pos += (velocity * dt);
}


DynamicObject::DynamicObject()
{
}

DynamicObject::DynamicObject(Wektor pos, float alpha, int w, int h, int r, bool col,
	ALLEGRO_BITMAP* bitmap, Wektor vel)

	:GameObject(pos, alpha, w, h, r, col), velocity{vel}
{
}


DynamicObject::~DynamicObject()
{
}
