#include "Projectile.h"

float Projectile::max_speed = 1000;
float Projectile::radius = 16;
int Projectile::dmg = 20;

Projectile::Projectile()
{
}

void Projectile::load_resource()
{
	bmp = al_load_bitmap("punkt.png");
}

Projectile::Projectile(Wektor start, float angle)
{
	my_pos = start;	
	vel = Wektor{ 1,0 }*max_speed;
	vel.rotate(angle);
	
}


Projectile::~Projectile()
{
}
