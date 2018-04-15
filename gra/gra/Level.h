#pragma once
#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "Wektor.h"
#include "GameControl.h"
#include "GameModel.h"
#include "GameView.h"
#include <vector>
#include "GameObject.h"
#include "DynamicObject.h"
#include "StaticObject.h"
#include "Player.h"
#include "MyKeyboard.h"
#include "Sector.h"

class Level
{
public:
	//GameModel model;
	//GameControl control;
	bool game_is_running;
	ALLEGRO_DISPLAY *my_display;
	ALLEGRO_BITMAP *my_map;

	ALLEGRO_EVENT_QUEUE* my_fps_timer_queue;
	ALLEGRO_EVENT_QUEUE* my_model_timer_queue;
	ALLEGRO_EVENT_QUEUE* my_input_queue;
	ALLEGRO_EVENT_QUEUE* my_model_queue;
	ALLEGRO_TIMER *my_model_timer;
	ALLEGRO_TIMER *my_fps_timer;

	bool already_rendered;
	double curr_tick_time;
	double dt;

	StaticObject* static_objects;
	DynamicObject* dynamic_objects;
	int dynamic_objects_count;
	int static_objects_count;
	Player player;

	Wektor mouse_pos;
	ALLEGRO_MOUSE_STATE mouse_state;
	MyKeyboard  keyboard;

	Enemy ** enemy_list;
	int enemy_count;
	StaticObject ** static_list;
	int static_count;
	Projectile ** projectile_list;
	int projectile_count;

	Sector sector0, sector1, sector2, sector3, sector4, sector5;


	Level();
	Level(	ALLEGRO_DISPLAY *display,
			ALLEGRO_BITMAP *map);
	~Level();
	void update_mouse();
	void init_model_timer_queue();
	void start_timers();

	double update_dt();

};
