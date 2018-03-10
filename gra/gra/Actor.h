#pragma once
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
typedef char stat;

class Actor
{
public:
	Actor();
	~Actor();
private:
	int ID;
	int Name;
protected:
	int pos_x;
	int pos_y;
	int pos_alpha;
	int w;
	int h;
	int flagi;
};

class Player :
	private Actor
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

