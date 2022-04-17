#pragma once

class Enemy
{
private:
	int enemyXpos;
	int enemyYpos;
	double enemyTimer;

public:
	Enemy(int xpos, int ypos);
	int GetXpos();
	int GetYpos();
	void Move();
};