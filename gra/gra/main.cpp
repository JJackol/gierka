#include <iostream>
#include <cstdio>
#include <allegro5/allegro.h>
#include <allegro5/allegro.h>

int main() {

	if (!al_init()) {
		fprintf(stderr, "Nie mozna zainicjowac Allegro5!");
		return -1;
	}
	else fprintf(stderr, "Zainicjowano Allegro5!\n");





	getchar();
	return 0;
}