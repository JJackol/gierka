#pragma once
#include "DynamicObject.h"
#include "Projectile.h"
#include <allegro5/allegro.h>

class Level;

class Player	:	public DynamicObject
{
public:
	Player();
	~Player();
	void update_angle(Wektor mouse);
	void shoot( Projectile** , int& );
	void load_resource();
};
