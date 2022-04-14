#pragma once
//#include "Point.h"

class Player
{
private:
	int playerXpos;
	int playerYpos;

public:
	Player(int xpos, int ypos);
	int GetXpos();
	int GetYpos();
	void UpdatePos();
};

