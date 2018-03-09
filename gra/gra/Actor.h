#pragma once
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
	int ap;
	int mana;
private:
	int strenght;
	int dex;
	int abilityp;
	int armor;
	int mres;
	int fireres;
	int coldres;
};

