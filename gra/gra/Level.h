#pragma once
#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "Wektor.h"
#include "GameControl.h"
#include "GameModel.h"
#include "GameView.h"

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
	ALLEGRO_TIMER *my_model_timer;
	ALLEGRO_TIMER *my_fps_timer;
	bool already_rendered;
	

	Level();
	Level(	ALLEGRO_DISPLAY *display,
			ALLEGRO_BITMAP *map);
	~Level();
	void init_model_timer_queue();
	void start_timers();

};

