//#include <iostream>
#include <cstdio>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

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
	al_get_allegro_image_version();
/*	if (!al_init_image_addon()) {
		fprintf(stderr, "Nie mozna zainicjowac image add");
		al_uninstall_keyboard();
		return -1;
	}
	else fprintf(stderr, "Zainicjowano image add\n");
	*/
	//ALLEGRO_DISPLAY *ekran;



	
	al_uninstall_keyboard();
	getchar();
	return 0;
}