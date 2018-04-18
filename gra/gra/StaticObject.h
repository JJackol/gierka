#pragma once
#include "GameObject.h"
class StaticObject :
	public GameObject
{
public:
	StaticObject();
	StaticObject(Wektor pos,const char* filename,float w, float h);
	~StaticObject();
};

