#pragma once
#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "Wektor.h"
#include "Level.h"
#include "Enemy.h"
#include "Projectile.h"

class MeleeWeapon;

struct InitError
{
};

const int SCREEN_W = 800;
const int SCREEN_H = 600;

const int MAX_FPS = 30;
const int MAX_TICKS_PER_SEC = 60;
//const double TIME_SKIP = static_cast<double>(1)/ MAX_TICKS_PER_SEC;
//const int MAX_FRAME_SKIPS = 5;

//float inv_sqrt(float x);
void base_init();
void base_uninstal();

void play_level(Level* level);

void update_control(Level* level, ALLEGRO_EVENT* p );
void update_game_model(Level* level, double dt, double curr_time);
void update_view(Level* level );
double smooth_start(double t);

void manage_collisions(Level *level);
void collision(Player &player, Enemy &enemy);
void collision(DynamicObject &object, Projectile &enemy);
void collision(Enemy &enemy, MeleeWeapon &weapon);
void collision(StaticObject &static_object, DynamicObject dynamic_object);
void sector_divde(Level *level);

