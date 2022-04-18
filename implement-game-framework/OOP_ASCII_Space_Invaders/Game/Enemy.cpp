#include "stdafx.h"
#include "Framework/Input.h"
#include "Enemy.h"
#include "Framework/Timer.h"

Enemy::Enemy(MapType type, int xpos, int ypos, int life) : type(type), enemyXpos(xpos), enemyYpos(ypos), enemyTimer(0.0), life(life)
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

MapType Enemy::GetType()
{
	return type;
}

void Enemy::SetXpos(int xpos)
{
	enemyXpos = xpos;
}

void Enemy::SetYpos(int ypos)
{
	enemyYpos = ypos;
}

void Enemy::Damage()
{
	life--;
	if (life == 1)
	{
		type = MAPTYPE_ENEMY_TYPE_B;
	}
}

bool Enemy::Die()
{
	if (life == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}