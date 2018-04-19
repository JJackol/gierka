//#include <iostream>
#include <cstdio>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "Wektor.h"
#include "MyGameLib.h"
#include "Level2.h"

using namespace std;

int main(int argc, char **argv) {

	base_init();

	ALLEGRO_DISPLAY *ekran = nullptr;
	ALLEGRO_BITMAP *mapa = nullptr;
	ekran = al_create_display(SCREEN_W , SCREEN_H);
	al_set_target_backbuffer(ekran);
	al_clear_to_color(al_map_rgb(0, 150, 0));
	al_flip_display();
	Level2 level{ekran};

	ALLEGRO_TIMER* my_timer = al_create_timer(1.0 );
	al_start_timer(my_timer);
	cout << al_get_timer_count(my_timer) << endl;

	play_level(&level);

	al_destroy_display(ekran);

	cout << al_get_timer_count(my_timer)<<endl;

	base_uninstal();
	getchar();
	return 0;
}