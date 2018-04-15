#pragma once
constexpr double PI_CONST = 3.141592653589793238463;

class WektorInt
{
public:
	~WektorInt();
private:
	int x = 0;
	int y = 0;
public:
	WektorInt(float xx, float yy);
	WektorInt();
	friend WektorInt sum(WektorInt a, WektorInt b);
	WektorInt add(WektorInt a);
	WektorInt rotate(float alpha);
	WektorInt operator+(WektorInt a);
	WektorInt operator-();
	WektorInt operator-(WektorInt a);
	WektorInt operator+=(WektorInt a);
	WektorInt operator-=(WektorInt a);
	WektorInt operator*(double a);
	WektorInt operator/(double a);
	double get_angle_d();
	int operator*(WektorInt a);
};




