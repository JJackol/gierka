#pragma once
#include <iostream>
#include <cmath>
constexpr double PI_CONST = 3.141592653589793238463;
class Wektor
{
private:
	float x=0;
	float y=0;
public:
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
};

