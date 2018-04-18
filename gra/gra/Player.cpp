#include "Player.h"
#include "MyGameLib.h"


Player::Player()
{
	my_pos = { 1620,5800 };
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

void Player::load_resource()
{

}
