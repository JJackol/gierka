#include "MyGameLib.h"

double smooth_start(double t)
{
	
	return 0;
}

/*

float inv_sqrt(float x) {
	float xhalf = 0.5f*x;
	int i = *(int*)&x;
	i = 0x5f3759df - (i >> 1);
	x = *(float*)&i;
	x = x * (1.5f - xhalf * x*x);
	return x;
}
*/
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

	
	level->start_timers();
	
	ALLEGRO_EVENT ev;
	al_flush_event_queue(fps_queue);
	al_flush_event_queue(model_queue);
	level->keyboard.clear();
	double prev_t=0;
	double dt=0;
	double curr_t=al_get_time();
	level->player.load_resource();
	level->player.my_pos = { 1000,1000 };
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

	player->update_velocity(new_normalized_vel, curr_time);
	player->update_position(dt);
	player->update_angle(level->mouse_pos);

	std::cout << "Game update " <<  std::endl;
}



void update_view(Level* level)

{
	Wektor camera_pos = (level->player.my_pos) - Wektor{static_cast<float>(SCREEN_H)/2, static_cast<float>(SCREEN_W)/2} ;
	Wektor player_pos = level->player.my_pos - camera_pos;

	int x = static_cast<int>(camera_pos.x);
	int y = static_cast<int>(camera_pos.y);

	
	al_set_target_backbuffer(level->my_display);
	al_draw_bitmap_region(level->my_map, camera_pos.x , camera_pos.y , SCREEN_W, SCREEN_H,  0, 0, 0);

	al_draw_rotated_bitmap(level->player.my_bitmap, level->player.width / 2, level->player.height / 2, SCREEN_W / 2, SCREEN_H / 2, level->player.angle, 0);
	al_flip_display();

	//al_flush_event_queue(level->my_fps_timer_queue);
std::cout << "View update " << al_get_timer_count(level->my_fps_timer) << "***************" << std::endl;
}

void manage_collisions(Level* level)
{
	sector_divde(level);



}

void collision(Player& player, Enemy& enemy)
{
}

void collision(DynamicObject& object, Projectile& enemy)
{
}

void collision(Enemy& enemy, MeleeWeapon& weapon)
{
}

void collision(StaticObject& static_object, DynamicObject dynamic_object)
{
}

void sector_divde(Level *level)
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
		{
			if(enemy->my_pos.x>player.x)
			{
				if (enemy->my_pos.y > player.y)
					level->sector1.add(enemy);
				if (enemy->my_pos.y < player.y)
					level->sector4.add(enemy);
			}
			if (enemy->my_pos.x<player.x)
				if (enemy->my_pos.y > player.y)
					level->sector2.add(enemy);
				if (enemy->my_pos.y < player.y)
					level->sector3.add(enemy);
		}
		else
			level->sector5.add(enemy);
	}
	Projectile* projectile = nullptr;
	for (int i = 0; i<level->projectile_count; i++)
	{
		projectile = level->projectile_list[i];

		if ((projectile->my_pos - player)*(projectile->my_pos - player) <(range1 + projectile->radius)*(range1 + projectile->radius))
			level->sector0.add(projectile);
		if ((projectile->my_pos - player)*(projectile->my_pos - player) > (range1 + projectile->radius)*(range1 + projectile->radius)
			&& (projectile->my_pos - player)*(projectile->my_pos - player) < (range2 + projectile->radius)*(range2 + projectile->radius))
		{
			if (projectile->my_pos.x>player.x)
			{
				if (projectile->my_pos.y > player.y)
					level->sector1.add(projectile);
				if (projectile->my_pos.y < player.y)
					level->sector4.add(projectile);
			}
			if (projectile->my_pos.x<player.x)
				if (projectile->my_pos.y > player.y)
					level->sector2.add(projectile);
			if (projectile->my_pos.y < player.y)
				level->sector3.add(projectile);
		}
		else
			level->sector5.add(projectile);
	}
}





