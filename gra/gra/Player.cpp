#include "Player.h"
#include "MyGameLib.h"


Player::Player()
{
	width = 100;
	height = 100;
}


Player::~Player()
{
}

void Player::update_angle(Wektor mouse)
{
	mouse -= {SCREEN_W / 2, SCREEN_H / 2};
	angle = mouse.get_angle_d();
}

void Player::load_resource()
{

	my_bitmap = al_create_bitmap(100, 100);
	my_bitmap = al_load_bitmap("postac.png");

}
