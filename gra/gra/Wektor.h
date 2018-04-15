#pragma once
#include <iostream>
#include <cmath>
constexpr double PI_CONST = 3.141592653589793238463;
class Wektor
{
public:
	float x=0;
	float y=0;

	Wektor( float xx, float yy );
	Wektor();
	friend Wektor sum(Wektor a, Wektor b);
	Wektor add(Wektor a);
	Wektor rotate(float alpha);
	Wektor operator+(Wektor a);
	Wektor operator-();
	Wektor operator-(Wektor a);
	Wektor operator+=(Wektor a);
	Wektor operator-=(Wektor a);
	Wektor operator*(float a);
	Wektor operator/(float a);
	float operator*(Wektor a);
	bool operator==(Wektor a);
	bool operator!=(Wektor a);
	Wektor operator*=(float a);
	double get_angle_d();
	Wektor normalize();
	
	
};
float inv_sqrt(float x);
Wektor normalize(Wektor a);