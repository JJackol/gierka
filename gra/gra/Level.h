#pragma once
#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "Wektor.h"
#include "GameObject.h"
#include "DynamicObject.h"
#include "StaticObject.h"
#include "Player.h"
#include "MyKeyboard.h"
#include "Sector.h"
#include "Map1.h"
#include "Map2.h"

class Level
{
public:
	//GameModel model;
	//GameControl control;
	bool game_is_running;
	ALLEGRO_DISPLAY *my_display;

	ALLEGRO_EVENT_QUEUE* my_fps_timer_queue;
	ALLEGRO_EVENT_QUEUE* my_model_timer_queue;
	ALLEGRO_EVENT_QUEUE* my_input_queue;
	ALLEGRO_EVENT_QUEUE* my_model_queue;
	ALLEGRO_TIMER *my_model_timer;
	ALLEGRO_TIMER *my_fps_timer;

	bool already_rendered;
	double curr_tick_time;
	double dt;

	Wektor camera_pos;
	Wektor target_camera_pos;
	Wektor player_pos;
	Player player;

	Wektor mouse_pos;
	ALLEGRO_MOUSE_STATE mouse_state;
	MyKeyboard  keyboard;


	Map* mapp;

	Enemy** enemy_list;
	int enemy_count;
	StaticObject** static_list;
	int static_count;
	Projectile** projectile_list;
	int projectile_count;

	GameObject** obj_list;
	int obj_count;

	Sector sector0, sector1, sector2;
	

	Level();
	Level(	ALLEGRO_DISPLAY *display);
	virtual ~Level();
	
	void init_model_timer_queue();
	void start_timers();

	void update_mouse();
	void update_camera_pos();

	//
	double update_dt();

	void draw_map();
	void draw_object(GameObject* object);

	void flush();
	void add(Enemy *);
	void add(StaticObject *);
	void add(Projectile *);

	void remove_projectile(Projectile *);
	//COLLISIONS   //////////////////////
	void manage_collisions();
	void sector_divide();
	/*
	void collision(Player &player, Enemy &enemy);
	void collision(DynamicObject &object, Projectile &enemy);

	void collision(StaticObject &static_object, DynamicObject& dynamic_object);

	void collision(StaticObject& object, Projectile& enemy);
	*/
};

