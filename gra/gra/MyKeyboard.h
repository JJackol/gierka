#pragma once
#include "Wektor.h"

class MyKeyboard
{
public:
	bool w, a, s, d;
	void clear();
	Wektor get_normalized_vel();

	MyKeyboard();
	~MyKeyboard();
};

