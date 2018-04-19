#pragma once
#include "GameObject.h"
#include "Enemy.h"
#include "StaticObject.h"
#include "Projectile.h"

class Sector
{
public:
	Enemy** enemy_list;
	int enemy_count;
	StaticObject** static_list;
	int static_count;
	Projectile** projectile_list;
	int projectile_count;

	void flush();
	void add(Enemy *);
	void add(StaticObject *);
	void add(Projectile *);
	Sector();
	~Sector();
};

