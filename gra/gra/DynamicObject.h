#pragma once
#include "GameObject.h"
#include "Wektor.h"

class DynamicObject :
	public GameObject
{
public:
	typedef char stat;

	int hp;
	int mana;
	float max_speed = 300;

	Wektor velocity;


	double some_func(double x);
	void update_velocity(Wektor target, double curr_time);
	void update_position(double dt);

	DynamicObject();
	DynamicObject(Wektor pos, float alpha, int w, int h, int r, bool col, ALLEGRO_BITMAP* bitmap, Wektor vel); 
	~DynamicObject();
};

