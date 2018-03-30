#include "Wektor.h"


Wektor::Wektor(float xx, float yy) :x{xx} , y{yy}
{
}
Wektor::Wektor() : x{ 0 }, y{ 0 }
{
}


Wektor sum(Wektor a, Wektor b)
{
	return Wektor{ a.x + b.x , a.y + b.y };
}


Wektor Wektor::add(Wektor a)
{
	x += a.x;
	y += a.y;
	return *this;
}

Wektor Wektor::rotate(float alpha)
{
	alpha *= PI_CONST/180;
	x = x * cos(alpha) + y*sin(alpha);
	y = -x * sin(alpha) + y * cos(alpha);
	return *this;
}

 Wektor Wektor::operator+(Wektor a)
{
	return { x + a.x , y + a.y };
}

Wektor Wektor::operator-()
{
	return { -x , -y };
}
Wektor Wektor::operator-(Wektor a)
{
	return { x - a.x , y - a.y };
}

Wektor Wektor::operator+=(Wektor a)
{
	x += a.x;
	y += a.y;
	return *this;
}
Wektor Wektor::operator-=(Wektor a)
{
	x -= a.x;
	y -= a.y;
	return *this;
}
