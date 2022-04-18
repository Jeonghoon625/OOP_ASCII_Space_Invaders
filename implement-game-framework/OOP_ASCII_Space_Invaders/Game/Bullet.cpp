#include "stdafx.h"
#include "Bullet.h"
#include "Framework/Timer.h"

Bullet::Bullet(MapType maptype, int xpos, int ypos) : maptype(maptype), xpos(xpos), ypos(ypos), bulletTimer(0.0)
{
}

int Bullet::GetXpos()
{
	return xpos;
}

int Bullet::GetYpos()
{
	return ypos;
}

MapType Bullet::GetType()
{
	return maptype;
}

void Bullet::Move()
{
	bulletTimer += GetDeltaTime();
	double delayTime = 0.2;

	if (bulletTimer >= delayTime)
	{
		if (maptype == MAPTYPE_PLAYER)
		{
			ypos--;
		}
		else
		{
			ypos++;
		}

		bulletTimer = 0.0;
	}
}