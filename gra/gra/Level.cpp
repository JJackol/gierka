#include "Level.h"
#include "MyGameLib.h"


Level::Level()
{
}

Level::Level(	ALLEGRO_DISPLAY* display,
				ALLEGRO_BITMAP* map=nullptr) : 	my_display{ display }, my_map { map }, already_rendered{ true }	
{
	my_model_timer_queue = al_create_event_queue();
	my_model_timer = al_create_timer(static_cast<double>(1) / MAX_TICKS_PER_SEC);
	al_register_event_source(my_model_timer_queue, al_get_timer_event_source(my_model_timer));

	my_fps_timer_queue = al_create_event_queue();
	my_fps_timer = al_create_timer(static_cast<double>(1) / MAX_FPS);
	al_register_event_source(my_fps_timer_queue, al_get_timer_event_source(my_fps_timer));

	my_input_queue = al_create_event_queue();
	al_register_event_source(my_input_queue, al_get_display_event_source(my_display));
	al_register_event_source(my_input_queue, al_get_keyboard_event_source());

	enemy_list = new Enemy*[64];
	enemy_count = 0;

	static_list = new StaticObject*[64];
	static_count = 0;

	projectile_list = new Projectile*[64];
	projectile_count = 0;
	
}

Level::~Level()
{
	al_destroy_event_queue(my_fps_timer_queue);
	al_destroy_event_queue(my_model_timer_queue);
	al_destroy_event_queue(my_input_queue);
	al_destroy_timer(my_fps_timer);
	al_destroy_timer(my_model_timer);
}

void Level::update_mouse()
{
	al_get_mouse_state(&mouse_state);
	mouse_pos = { (float)mouse_state.x , (float)mouse_state.y };
}

void Level::init_model_timer_queue()
{
	/*
	al_destroy_event_queue(my_fps_timer_queue);
	al_destroy_event_queue(my_model_timer_queue);
	al_destroy_event_queue(my_input_queue);
	al_destroy_timer(my_fps_timer);
	al_destroy_timer(my_model_timer);*/

	my_model_timer_queue = al_create_event_queue();
	my_model_timer = al_create_timer(static_cast<double>(1) / MAX_TICKS_PER_SEC);
	al_register_event_source(my_model_timer_queue, al_get_timer_event_source(my_model_timer));

	my_fps_timer_queue = al_create_event_queue();
	my_fps_timer = al_create_timer(static_cast<double>(1) / MAX_FPS);
	al_register_event_source(my_fps_timer_queue, al_get_timer_event_source(my_fps_timer));

	my_input_queue = al_create_event_queue();
	al_register_event_source(my_fps_timer_queue, al_get_display_event_source(my_display));
}

void Level::start_timers()
{
	al_start_timer(my_model_timer);
	al_start_timer(my_fps_timer);
}

double Level::update_dt()
{
	curr_tick_time=0;
	curr_tick_time = al_get_time();
	dt -= curr_tick_time;
	dt *= -1.0;
	return dt;
}
