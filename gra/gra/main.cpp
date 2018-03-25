//#include <iostream>
#include <cstdio>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "Wektor.h"

const int SCREEN_W = 800;
const int SCREEN_H = 600;

int main(int argc, char **argv) {

	if (!al_init()) {
		fprintf(stderr, "Nie mozna zainicjowac Allegro5!");
		return -1;
	}
	else fprintf(stderr, "Zainicjowano Allegro5!\n");

	if (!al_install_keyboard()) {
		fprintf(stderr, "Nie mozna zainicjowac klawiatury");

		return -1;
	}
	else fprintf(stderr, "Zainicjowano Klawiature\n");

	if (!al_init_image_addon()) {
		fprintf(stderr, "Nie mozna zainicjowac image add");
		al_uninstall_keyboard();
		return -1;
	}
	else fprintf(stderr, "Zainicjowano image add\n");

	if (!al_install_mouse()) {
		fprintf(stderr, "Nie mozna zainicjowac myszy");
		al_uninstall_keyboard();
		return -1;
	}
	else fprintf(stderr, "Zainicjowano mysz\n");

	ALLEGRO_DISPLAY *ekran = nullptr;
	ALLEGRO_BITMAP *mapa = nullptr;
	ekran = al_create_display(SCREEN_W , SCREEN_H);
	mapa = al_create_bitmap(2000, 2000);
	al_set_target_bitmap(mapa);
	mapa = al_load_bitmap("mapatest.png");
	al_set_target_backbuffer(ekran);
	al_draw_bitmap_region(mapa ,	0, 0, SCREEN_W, SCREEN_H, 0, 0,0);
	al_flip_display();
	al_rest(1);

	al_destroy_display(ekran);
	al_uninstall_keyboard();
	getchar();
	return 0;
}