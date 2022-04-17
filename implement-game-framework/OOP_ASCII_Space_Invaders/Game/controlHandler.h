#pragma once
#include "Player.h"
#include "Enemy.h"
#include "Game/Stage.h"
#include "Move.h"
#include "Crash.h"
#include "Bullet.h"

class ControlHandler
{
public:
	Player* player;
	Enemy* enemy;
	Bullet* bullet;
	char(*s_map)[MAP_SIZE];

public:
	ControlHandler();

	void NewPlayer(Player* player);
	void NewEnemy(Enemy* enemy);
	void NewMap(char(* s_map)[MAP_SIZE]);
	void NewBullet();

	void CrashBullet(int currXpos, int currYpos, int xpos, int ypos);
	void CrashPlayer(int currXpos, int currYpos, int xpos, int ypos);
	void Update();

	~ControlHandler();

};
