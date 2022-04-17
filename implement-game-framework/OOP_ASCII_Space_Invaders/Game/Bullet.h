#pragma once
#include "Stage.h"

class Bullet
{
private:
	int xpos;
	int ypos;
	MapType maptype;
	double bulletTimer;

public:
	Bullet(MapType maptype, int xpos, int ypos);
	int GetXpos();
	int GetYpos();
	MapType GetType();
	void Move();

};

