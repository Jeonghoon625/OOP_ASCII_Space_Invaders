#pragma once
//#include "Point.h"

class Player
{
public:
	int playerXpos;
	int playerYpos;

public:
	Player(int xpos, int ypos);
	int GetXpos();
	int GetYpos();
	void SetXpos(int xpos);
	void SetYpos(int ypos);
	void Move();
};