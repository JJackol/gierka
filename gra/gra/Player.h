#pragma once
#include "DynamicObject.h"
#include <allegro5/allegro.h>
#include "allegro5/allegro_image.h"
class Player	:	public DynamicObject
{
public:
	Player();
	~Player();
	void update_angle(Wektor mouse);
	void load_resource();
};