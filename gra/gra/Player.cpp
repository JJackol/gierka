#pragma once
#include "Player.h"
#include "MyGameLib.h"
#include <allegro5/allegro.h>

Player::Player()
{
	my_pos = { 1800,5800 };
	radius = 60;
	width = 256;
	height = 256;
	my_bitmap = al_load_bitmap("bmp/player.png");
	max_speed = 500;
}


Player::~Player()
{
	al_destroy_bitmap(my_bitmap);
}

void Player::update_angle(Wektor mouse)
{
	
}

void Player::shoot(Projectile** projectile_list, int& projectile_count)
{
	bool saved = false;
	Wektor start = { 120,45 };
	start.rotate(angle);
	Projectile* new_pr = new Projectile{ start,angle };
	for(int i=0; i <projectile_count;i++)
	{
		if((projectile_list[i])==nullptr)
		{
			projectile_list[i] = new_pr;
			saved = true;
			break;
		}
	}
	if(!saved)
	{
		projectile_list[projectile_count] = new_pr;
		projectile_count++;
	}
}

void Player::load_resource()
{
	
}
