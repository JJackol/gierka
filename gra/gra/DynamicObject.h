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
	void draw(Wektor camera);

	DynamicObject();
	DynamicObject(Wektor pos,  int w, int h, int r,float alpha, bool col, Wektor vel); 
	~DynamicObject();
};

