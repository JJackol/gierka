#include "WektorInt.h"
#include <cmath>


WektorInt::WektorInt(float xx, float yy) :x{ xx }, y{ yy }
{
}
WektorInt::WektorInt() : x{ 0 }, y{ 0 }
{
}


WektorInt sum(WektorInt a, WektorInt b)
{
	return WektorInt{ a.x + b.x , a.y + b.y };
}


WektorInt WektorInt::add(WektorInt a)
{
	x += a.x;
	y += a.y;
	return *this;
}

WektorInt WektorInt::rotate(float alpha)
{
	alpha *= PI_CONST / 180;
	x = x * cos(alpha) + y * sin(alpha);
	y = -x * sin(alpha) + y * cos(alpha);
	return *this;
}

WektorInt WektorInt::operator+(WektorInt a)
{
	return { x + a.x , y + a.y };
}

WektorInt WektorInt::operator-()
{
	return { -x , -y };
}
WektorInt WektorInt::operator-(WektorInt a)
{
	return { x - a.x , y - a.y };
}

WektorInt WektorInt::operator+=(WektorInt a)
{
	x += a.x;
	y += a.y;
	return *this;
}
WektorInt WektorInt::operator-=(WektorInt a)
{
	x -= a.x;
	y -= a.y;
	return *this;
}

WektorInt WektorInt::operator*(double a)
{
	return { x * a , y * a };
}

WektorInt WektorInt::operator/(double a)
{
	if (a != 0)
		return { x / a , y / a };
	return *this;
}

double WektorInt::get_angle_d()
{
	return atan2(x, y);
}



int WektorInt::operator*(WektorInt a)
{
	return( x * a.x ) + ( y * a.y );
}

