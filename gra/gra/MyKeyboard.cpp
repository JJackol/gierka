#include "MyKeyboard.h"

constexpr float oneover2 = 0.70710678118;

void MyKeyboard::clear()
{
	w = false;
	a = false;
	s = false;
	d = false;
}

Wektor MyKeyboard::get_normalized_vel()
{
	Wektor vel{ 0.0,0.0 };
	if (w)vel += { 0.0, -1.0};
	if (a)vel += {-1.0, 0.0};
	if (s)vel += { 0.0, 1.0};
	if (d)vel += { 1.0, 0.0};
	if (vel*vel==2.0)
		return vel*oneover2;
	return vel;
}

MyKeyboard::MyKeyboard()
{
}


MyKeyboard::~MyKeyboard()
{
}
