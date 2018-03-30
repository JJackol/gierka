#pragma once
#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "Wektor.h"
#include "Level.h"

struct InitError
{
};

const int SCREEN_W = 800;
const int SCREEN_H = 600;
const int MAX_FPS = 30;

const int MAX_TICKS_PER_SEC = 60;
const double TIME_SKIP = static_cast<double>(1)/ MAX_TICKS_PER_SEC;
const int MAX_FRAME_SKIPS = 5;

void base_init();
void base_uninstal();

void play_level(Level* level);

void update_control(Level* level);
void update_game_model(Level* level);
void update_view(Level* level );

