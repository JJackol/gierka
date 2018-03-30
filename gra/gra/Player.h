#pragma once
#include "Actor.h"
class Player	:	private Actor
{
public:
	Player();
	~Player();
protected:
	int hp;
	stat ap;
	int mana;
private:
	stat strenght;
	stat dex;
	stat abilityp;
	stat armor;
	stat mres;
	stat fireres;
	stat coldres;
};