#include "Sector.h"


void Sector::flush()
{
	for(int i=0;i<enemy_count;i++)
	{
		enemy_list[i] = nullptr;
	}
	enemy_count = 0;
	for (int i = 0; i<static_count; i++)
	{
		static_list[i] = nullptr;
	}
	static_count = 0;
	for (int i = 0; i<projectile_count; i++)
	{
		projectile_list[i] = nullptr;
	}
	projectile_count = 0;
}

void Sector::add(Enemy* enemy)
{
	enemy_list[enemy_count] = enemy;
	enemy_count++;
}


void Sector::add(StaticObject* st)
{
	static_list[static_count] = st;
	static_count++;
}

void Sector::add(Projectile* pr)
{
	projectile_list[projectile_count] = pr;
	projectile_count++;
}



Sector::Sector()
{
	enemy_list = new Enemy*[32];
	enemy_count = 0;

	static_list = new StaticObject*[32];
	static_count = 0;

	projectile_list = new Projectile*[32];
	projectile_count = 0;
}


Sector::~Sector()
{
	delete[] enemy_list;
	enemy_list = nullptr;

	delete[] static_list;
	static_list = nullptr;

	delete[] projectile_list;
	projectile_list = nullptr;
}
