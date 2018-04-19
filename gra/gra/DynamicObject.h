#pragma once
#include "GameObject.h"
#include "Wektor.h"
#include <allegro5/allegro.h>

class DynamicObject :
	public GameObject
{
public:
	typedef char stat;

	int hp;
	int mana;
	float max_speed = 300;
	bool alive;

	Wektor velocity;

	virtual void update_state(double dt, Wektor target);

	double some_func(double x);
	void update_velocity(Wektor target, double curr_time);
	void update_position(double dt);
	void draw(Wektor camera);

	DynamicObject();
	DynamicObject(Wektor pos,  int w, int h, int r,float alpha, bool col, Wektor vel); 
	~DynamicObject();
};

