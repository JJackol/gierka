#pragma once
#include "Level2.h"



Level2::Level2()
{
	
}

Level2::Level2(ALLEGRO_DISPLAY* display) : Level{ display }, ob1{ {3275,8719},330,1000 }
{
	this->add(&ob1);
	mapp = &map;
}


Level2::~Level2()
{
}
