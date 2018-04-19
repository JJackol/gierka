#pragma once
#include "Level.h"
#include "MyGameLib.h"


Level::Level()
{
	
}

Level::Level(	ALLEGRO_DISPLAY* display
			) : 	my_display{ display }, already_rendered{ true }	
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

	camera_pos = old_camera + (target_camera_pos - old_camera)*0.2;
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
	mapp->draw(camera_pos);
}

void Level::draw_object(GameObject* object)
{
	object->draw(camera_pos);
}

void Level::flush()
{
	for (int i = 0; i<enemy_count; i++)
	{
		enemy_list[i] = nullptr;
	}
	enemy_count = 0;
	for (int i = 0; i<static_count; i++)
	{
		static_list[i] = nullptr;
	}
	static_count = 0;
	for (int i = 0; i<projectile_count; i++)
	{
		projectile_list[i] = nullptr;
	}
	projectile_count = 0;
}

//COLLISIONS   //////////////////////

void Level::add(Enemy* enemy)
{
	enemy_list[enemy_count] = enemy;
	enemy_count++;
}

void Level::add(StaticObject* st)
{
	static_list[static_count] = st;
	static_count++;
}

void Level::add(Projectile* pr)
{//unused
	projectile_list[projectile_count] = pr;
	pr->index = projectile_count;
	projectile_count++;

}

void Level::remove_projectile(Projectile* pr)
{
	projectile_list[pr->index] = nullptr;
}


void Level::manage_collisions()
{
	this->sector_divide();
	mapp->keep_on_map(player);

	
	for (int i = 0; i<static_count; i++)
	{
		for (int j = 0; j<enemy_count; j++)
		{
			mapp->keep_on_map(*(enemy_list[j]));
			collision(*(static_list[i]), *(enemy_list[j]));
		}
		for (int j = 0; j<projectile_count; j++)
		{
			collision(*(static_list[i]), *(projectile_list[j]));
		}
		collision(*(static_list[i]), player);
	}
//sector0
	for(int i=0;i<sector0.enemy_count; i++)
	{
		collision(player, *(sector0.enemy_list[i]));

		for (int j=0;j<sector0.projectile_count; j++)
		{
			collision(*(sector0.projectile_list[j]) , *(sector0.enemy_list[i]));
			//player projectile
		}
	}

//sector1
	for (int i = 0; i<sector1.enemy_count; i++)
	{
		collision(player, *sector1.enemy_list[i]);

		for (int j = 0; j<sector1.projectile_count; j++)
		{
			collision(*(sector1.projectile_list[j]), *(sector1.enemy_list[i]));
		}
	}
//sector2
	for (int i = 0; i<sector2.enemy_count; i++)
	{
		collision(player, *sector2.enemy_list[i]);

		for (int j = 0; j<sector2.projectile_count; j++)
		{
			collision(*(sector2.projectile_list[j]), *(sector2.enemy_list[i]));
		}
	}


}
void Level::sector_divide()
{
	sector0.flush();
	sector1.flush();
	sector2.flush();
	float range1 = 300;
	float range2 = 1000;
	Wektor player = Level::player.my_pos;
	Enemy* enemy = nullptr;
	for (int i = 0; i<enemy_count; i++)
	{
		enemy = enemy_list[i];

		if ((enemy->my_pos - player)*(enemy->my_pos - player) <(range1 + enemy->radius)*(range1 + enemy->radius))
			sector0.add(enemy);

		if ((enemy->my_pos - player)*(enemy->my_pos - player) > (range1 + enemy->radius)*(range1 + enemy->radius)
			&& (enemy->my_pos - player)*(enemy->my_pos - player) < (range2 + enemy->radius)*(range2 + enemy->radius))
			sector1.add(enemy);

		if ((enemy->my_pos - player)*(enemy->my_pos - player) > (range2 + enemy->radius)*(range2 + enemy->radius))
			sector2.add(enemy);
	}
	Projectile* projectile = nullptr;
	for (int i = 0; i<projectile_count; i++)
	{
		projectile = projectile_list[i];

		if ((projectile->my_pos - player)*(projectile->my_pos - player) <(range1 + projectile->radius)*(range1 + projectile->radius))
			sector0.add(projectile);

		if ((projectile->my_pos - player)*(projectile->my_pos - player) > (range1 + projectile->radius)*(range1 + projectile->radius)
			&& (projectile->my_pos - player)*(projectile->my_pos - player) < (range2 + projectile->radius)*(range2 + projectile->radius))
			sector1.add(projectile);

		if ((enemy->my_pos - player)*(enemy->my_pos - player) > (range2 + enemy->radius)*(range2 + enemy->radius))
			sector2.add(projectile);
	}
}
/*
void Level::collision(Player& player, Enemy& enemy)
{
}

void Level::collision(DynamicObject& object, Projectile& enemy)
{
}

void Level::collision(StaticObject& static_object, DynamicObject& dynamic_object)
{
}



void Level::collision(StaticObject& object, Projectile& enemy)
{
}
*/