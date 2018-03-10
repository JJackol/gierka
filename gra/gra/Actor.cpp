#include "Actor.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>


Actor::Actor()
{
	ID = 0;
	Name = 0;
	pos_x = 0;
	pos_y = 0 ;
	pos_alpha = 0;
	w = 0;
	h = 0;
	flagi = 0;
}


Actor::~Actor()
{
}

/****	class Player	*************************
*************************************/
Player::Player()
{
	hp = 0;
	ap = 0;
	mana = 0;
	strenght = 0;
	dex = 0;
	abilityp = 0;
	armor = 0;
	mres = 0;
	fireres = 0;
	coldres = 0;
}


Player::~Player()
{
}
