#include "MyGameLib.h"


void base_init()
{
	InitError init_error;
	if(!al_init()) {
		fprintf(stderr, "Nie mozna zainicjowac Allegro5!");
		throw init_error;
	}
	else fprintf(stderr, "Zainicjowano Allegro5!\n");

	if (!al_install_keyboard()) {
		fprintf(stderr, "Nie mozna zainicjowac klawiatury");
		throw init_error;

	}
	else fprintf(stderr, "Zainicjowano Klawiature\n");

	if (!al_init_image_addon()) {
		fprintf(stderr, "Nie mozna zainicjowac image add");
		throw init_error;
	}
	else fprintf(stderr, "Zainicjowano image add\n");

	if (!al_install_mouse()) {
		fprintf(stderr, "Nie mozna zainicjowac myszy");
		throw init_error;
	}
	else fprintf(stderr, "Zainicjowano mysz\n");
}

void base_uninstal()
{
	al_uninstall_keyboard();
	al_uninstall_mouse();
}

Level *level;

void play_level(Level* level)
{
	level->game_is_running = true;
	
	level->start_timers();
	while (level->game_is_running)
	{
		ALLEGRO_EVENT ev;
		if(level->already_rendered || al_is_event_queue_empty(level->my_fps_timer_queue))
		{
			al_wait_for_event(level->my_model_timer_queue, &ev);
			update_control( level );
			update_game_model( level );
			level->already_rendered = false;
		}
		else
		{
			al_wait_for_event(level->my_fps_timer_queue, &ev);
			update_view( level ) ;
			level->already_rendered = true;
		}
	}
	
}

void update_control(Level* level)
{
	while(!al_is_event_queue_empty(level->my_input_queue))
	{
		ALLEGRO_EVENT input_event;
		al_wait_for_event(level->my_input_queue, &input_event);
		if(input_event.keyboard.keycode==ALLEGRO_KEY_ESCAPE)
			level->game_is_running = false;
		if(input_event.type==ALLEGRO_EVENT_DISPLAY_CLOSE)
			level->game_is_running = false;
	}

	std::cout << "Control update " << al_get_time() << std::endl;

}

void update_game_model(Level* level)
{
	std::cout << "Game update " << al_get_time() << std::endl;

}

void update_view(Level* level)

{
	std::cout << "View update " << al_get_time() << std::endl;
	al_set_target_backbuffer(level->my_display);
	al_draw_bitmap_region(level->my_map, 0, 0, SCREEN_W, SCREEN_H, 0, 0, 0);
	al_flip_display();

}


	


