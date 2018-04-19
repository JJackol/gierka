#pragma once
#include "MyGameLib.h"
#include <allegro5/allegro.h>
#include <allegro5/bitmap.h>
#include <allegro5/bitmap_io.h>

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


void play_level(Level* level)
{
	level->game_is_running = true;
	ALLEGRO_EVENT_QUEUE* fps_queue = level->my_fps_timer_queue;
	ALLEGRO_EVENT_QUEUE* model_queue = level->my_model_timer_queue;

	level->camera_pos = level->player.my_pos;
	level->start_timers();
	
	ALLEGRO_EVENT ev;
	al_flush_event_queue(fps_queue);
	al_flush_event_queue(model_queue);
	level->keyboard.clear();
	double prev_t=0;
	double dt=0;
	double curr_t=al_get_time();
	while (level->game_is_running)
	{
		
		if(level->already_rendered || al_is_event_queue_empty(fps_queue))
		{
			al_wait_for_event(model_queue, &ev);
			prev_t = curr_t;
			curr_t = ev.any.timestamp;
			dt = curr_t - prev_t;
			level->curr_tick_time = curr_t;
			level->dt = dt;

			update_control( level ,&ev);
			update_game_model( level ,dt, curr_t);

			level->already_rendered = false;
			al_flush_event_queue(level->my_model_timer_queue);
		}
		else
		{
			al_wait_for_event(fps_queue, &ev);

			update_view( level ) ;

			level->already_rendered = true;
			al_flush_event_queue(level->my_fps_timer_queue);
		}
	}
	
}

void update_control(Level* level, ALLEGRO_EVENT* p)
{
	ALLEGRO_EVENT input_event;
	
	while (!al_is_event_queue_empty(level->my_input_queue))
	{
		al_wait_for_event(level->my_input_queue, &input_event);
		if (input_event.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
			level->game_is_running = false;
		else if (input_event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
			level->game_is_running = false;

		if (input_event.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			switch (input_event.keyboard.keycode)
			{
			case ALLEGRO_KEY_W:
				level->keyboard.w = true;
				break;
			case ALLEGRO_KEY_A:
				level->keyboard.a = true;
				break;
			case ALLEGRO_KEY_S:
				level->keyboard.s = true;
				break;
			case ALLEGRO_KEY_D:
				level->keyboard.d = true;
				break;
			default:
				break;
			}
		}
		else if (input_event.type == ALLEGRO_EVENT_KEY_UP)
		{
			switch (input_event.keyboard.keycode)
				{
				case ALLEGRO_KEY_W:
					level->keyboard.w = false;
					break;
				case ALLEGRO_KEY_A:
					level->keyboard.a = false;
					break;
				case ALLEGRO_KEY_S:
					level->keyboard.s = false;
					break;
				case ALLEGRO_KEY_D:
					level->keyboard.d = false;
					break;
				default:;
				}
		}		
	}
	level->update_mouse();
	std::cout	<< "Control update " << al_get_timer_count(level->my_model_timer)
				<<"---"<<p->any.timestamp <<"---------------"<< std::endl;
}



void update_game_model(Level* level, double dt, double curr_time)
{

	Player* player= &(level->player);
	Wektor new_normalized_vel = level->keyboard.get_normalized_vel();

	player->update_state(dt, new_normalized_vel);

	level->update_camera_pos();

	level->manage_collisions();

	std::cout << "Game update " <<  std::endl;
}



void update_view(Level* level)

{
	
	al_set_target_backbuffer(level->my_display); 
	level->draw_map();

	al_draw_rotated_bitmap(level->player.my_bitmap, level->player.width / 2, level->player.height / 2, level->player_pos.x, level->player_pos.y, level->player.angle, 0);
	al_flip_display();

	//al_flush_event_queue(level->my_fps_timer_queue);
std::cout << "View update " << al_get_timer_count(level->my_fps_timer) << "***************" << std::endl;
}

void manage_collisions(Level* level)
{//unused
	
	//sector_divide(level);
	level->mapp->keep_on_map(level->player);

	for(int i=0;i<level->static_count;i++)
	{
		for(int j=0; j<level->enemy_count; j++)
		{
			collision(*(level->static_list[i]), *(level->enemy_list[j]));
		}
		for (int j = 0; j<level->projectile_count; j++)
		{
			collision(*(level->static_list[i]), *(level->projectile_list[j]));
		}
		collision(*(level->static_list[i]), level->player);
	}
	//for(int i=0;i<)


}

void collision(Player& player, Enemy& enemy)
{
	Wektor w= enemy.my_pos - player.my_pos;
	float r = player.radius + enemy.radius;
	if ((w)*(w) < (r)*(r))
		w.normalize();
	w = (-w)*r;
	enemy.my_pos += w;
}

void collision(Projectile& projectile, Enemy& enemy)
{
}
void collision(StaticObject& object, Projectile& pr)
{
}

void collision(Enemy& enemy, MeleeWeapon& weapon)
{
}

void collision(StaticObject& static_object, DynamicObject& object)
{/*
	Wektor z1 = {static_cast<float>(object.radius) ,static_cast<float>(object.radius) };
	Wektor z2 = static_object.top_left - z1;
	z1 += static_object.botom_right;
	z1 -= object.my_pos;
	z2-= object.my_pos;

	Wektor rex;
	Wektor rey;
		if (z1.x>0 && z1.y>0 && z2.x > 0 && z2.y > 0)
		{
			if(z1.x<z2.x)
				rex = { z1.x,0 };
			else
				rex = { -z2.x,0 };
			if (z1.y < z2.y)
				rey = { 0,z1.y };
			else
				rey = { 0,-z2.y };
			object.my_pos += abs(rex.x) < abs(rey.y) ? rex : rey;
		}
		
	*/
}

void sector_divide(Level *level)
{
	
	float range1 = 300;
	float range2 = 1000;
	Wektor player = level->player.my_pos;
	Enemy* enemy = nullptr;
	for(int i=0;i<level->enemy_count;i++)
	{
		enemy = level->enemy_list[i];

		if ((enemy->my_pos - player)*(enemy->my_pos - player) <(range1 + enemy->radius)*(range1 + enemy->radius))
			level->sector0.add(enemy);

		if( (enemy->my_pos-player)*(enemy->my_pos - player) > (range1+enemy->radius)*(range1 + enemy->radius)
			&& (enemy->my_pos - player)*(enemy->my_pos - player) < (range2 + enemy->radius)*(range2 + enemy->radius))
			level->sector1.add(enemy);

		else
			level->sector2.add(enemy);
	}
	Projectile* projectile = nullptr;
	for (int i = 0; i<level->projectile_count; i++)
	{
		projectile = level->projectile_list[i];

		if ((projectile->my_pos - player)*(projectile->my_pos - player) <(range1 + projectile->radius)*(range1 + projectile->radius))
			level->sector0.add(projectile);

		if ((projectile->my_pos - player)*(projectile->my_pos - player) > (range1 + projectile->radius)*(range1 + projectile->radius)
			&& (projectile->my_pos - player)*(projectile->my_pos - player) < (range2 + projectile->radius)*(range2 + projectile->radius))
			level->sector1.add(projectile);

		else
			level->sector2.add(projectile);
	}
}





