#include "Level.h"
#include "MyGameLib.h"


Level::Level(): topleft({100, 100}, "bmp/punkt.png" ,10,10)
{
	
}

Level::Level(	ALLEGRO_DISPLAY* display,
				ALLEGRO_BITMAP* map=nullptr) : 	my_display{ display }, my_map { map }, already_rendered{ true }	, topleft({ 100, 100 }, "bmp/punkt.png", 10, 10)
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
/*
	enemy_list = new Enemy*[64];
	enemy_count = 0;

	static_list = new StaticObject*[64];
	static_count = 0;

	projectile_list = new Projectile*[64];
	projectile_count = 0;
	*/
}

Level::~Level()
{
	al_destroy_event_queue(my_fps_timer_queue);
	al_destroy_event_queue(my_model_timer_queue);
	al_destroy_event_queue(my_input_queue);
	al_destroy_timer(my_fps_timer);
	al_destroy_timer(my_model_timer);
/*
	delete[] enemy_list;
	enemy_list = nullptr;

	delete[] static_list;
	static_list = nullptr;

	delete[] projectile_list;
	projectile_list = nullptr;
*/
	delete[] obj_list;
	obj_list = nullptr;
}

void Level::update_mouse()
{
	al_get_mouse_state(&mouse_state);
	mouse_pos = { (float)mouse_state.x , (float)mouse_state.y };
}

void Level::init_model_timer_queue()
{


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

void Level::update_camera_pos()
{
	Wektor old_camera = camera_pos;
	mouse_pos += old_camera;
	target_camera_pos = mouse_pos * 0.3 + player.my_pos * 0.7 - Wektor{ static_cast<float>(SCREEN_W) / 2, static_cast<float>(SCREEN_H) / 2 };

	camera_pos = old_camera + (target_camera_pos - old_camera)*0.1;
	player_pos = player.my_pos - camera_pos;

	mouse_pos -= player.my_pos;
	player.angle = mouse_pos.get_angle_d();
}

double Level::update_dt()
{
	return 0;
}

void Level::draw_map()
{
	al_set_target_backbuffer(my_display);
	map.draw(camera_pos);
}

void Level::draw_object(GameObject* object)
{

}
