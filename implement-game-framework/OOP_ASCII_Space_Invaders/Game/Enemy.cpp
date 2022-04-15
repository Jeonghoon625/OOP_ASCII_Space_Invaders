#include "stdafx.h"
#include "Framework/Input.h"
#include "Enemy.h"
#include "Framework/Timer.h"

Enemy::Enemy(int xpos, int ypos) : enemyXpos(xpos), enemyYpos(ypos), enemyTimer(0.0)
{
}

int Enemy::GetXpos()
{
	return enemyXpos;
}

int Enemy::GetYpos()
{
	return enemyYpos; 
}

void Enemy::UpdatePos()
{
	enemyTimer += GetDeltaTime();
	double delayTime = 1.0;

	if (enemyTimer > delayTime)
	{
		enemyTimer = 0.0;
		enemyYpos++;
	}
}