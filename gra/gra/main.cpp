//#include <iostream>
#include <cstdio>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "Wektor.h"
#include "MyGameLib.h"

using namespace std;

int main(int argc, char **argv) {

	base_init();

	ALLEGRO_DISPLAY *ekran = nullptr;
	ALLEGRO_BITMAP *mapa = nullptr;
	ekran = al_create_display(SCREEN_W , SCREEN_H);
	mapa = al_create_bitmap(2000, 2000);
	al_set_target_bitmap(mapa);
	mapa = al_load_bitmap("mapatest.png");
	al_set_target_backbuffer(ekran);
	al_draw_bitmap_region(mapa ,	0, 0, SCREEN_W, SCREEN_H, 0, 0,0);
	al_flip_display();
	Level level{ekran,mapa};

	//level.init_model_timer_queue();

	play_level(&level);


	//al_rest(1);
	al_destroy_display(ekran);

	ALLEGRO_TIMER* my_timer = al_create_timer(1.0 / MAX_TICKS_PER_SEC);
	al_start_timer(my_timer);
	cout << al_get_timer_count(my_timer)<<endl;
	al_rest(1);
	cout << al_get_timer_count(my_timer) << endl; 
	al_rest(1);
	cout << al_get_timer_count(my_timer) << endl;
	al_rest(1);
	cout << al_get_timer_count(my_timer) << endl;

	base_uninstal();
	getchar();
	return 0;
}