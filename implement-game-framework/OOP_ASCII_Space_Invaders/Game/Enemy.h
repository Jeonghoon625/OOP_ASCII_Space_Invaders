#pragma once
#include "Game/Stage.h"

class Enemy
{
private:
	int enemyXpos;
	int enemyYpos;
	int life;
	MapType type;
	double enemyTimer;

public:
	Enemy(MapType type, int xpos, int ypos, int life);
	int GetXpos();
	int GetYpos();
	MapType GetType();
	void SetXpos(int xpos);
	void SetYpos(int ypos);
	void Damage();
	bool Die();
};