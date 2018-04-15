#include "Wektor.h"
#include <cmath>

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

Wektor Wektor::operator*(float a)
{
	return { x * a , y * a };
}

Wektor Wektor::operator/(float a)
{
	if(a!=0)
		return { x / a , y / a };
	return *this;
}

float Wektor::operator*(Wektor a)
{
	return(x * a.x) + (y * a.y);
}

bool Wektor::operator==(Wektor a)
{
	return (x == a.x && y == a.y);
}

bool Wektor::operator!=(Wektor a)
{
	return (x != a.x || y != a.y);
}

Wektor Wektor::operator*=(float a)
{
	x *= a;
	y *= a;
	return *this;
}

double Wektor::get_angle_d()
{
	return atan2(y, x);
}

Wektor Wektor::normalize()
{
	if (x == 0 && y == 0)
		return *this;
	return *this *= inv_sqrt((*this) * (*this));
}

Wektor normalize(Wektor a)
{
	if (a.x != 0 || a.y!=0 )
		return a*inv_sqrt(a * a);
	return a;
}

float inv_sqrt(float x) {
	float xhalf = 0.5f*x;
	int i = *(int*)&x;
	i = 0x5f3759df - (i >> 1);
	x = *(float*)&i;
	x = x * (1.5f - xhalf * x*x);
	return x;
}


