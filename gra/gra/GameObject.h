#pragma once
#include "Wektor.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/bitmap_io.h>
class GameObject
{
public:
	Wektor my_pos;
	float angle;
	int width;
	int height;
	float radius;
	bool collision;
	 ALLEGRO_BITMAP* my_bitmap;

	void load_bitmap(const char* file);
	virtual void draw(Wektor camera);

	GameObject();
	GameObject(Wektor pos,  int w, int h, float r,float alpha, bool col);
	virtual ~GameObject();
};

