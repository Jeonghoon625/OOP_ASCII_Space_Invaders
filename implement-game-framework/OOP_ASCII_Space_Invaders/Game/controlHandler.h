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
	Enemy* enemy[ENEMY_MAX];
	Bullet* bullet[BULLET_MAX];
	char(*s_map)[MAP_SIZE];

	double shootTimer;
	int bulletNum;
	int enemyNum;
	enum class direction{RIGHT};

public:
	ControlHandler();

	void NewPlayer(Player* player);
	void NewEnemy(Enemy* enemy);
	void NewMap(char(* s_map)[MAP_SIZE]);
	void NewBullet();

	void CrashBullet(int currXpos, int currYpos, int i);
	void CrashPlayer(int currXpos, int currYpos, int xpos, int ypos);

	int FindEnemyIdx(int xpos, int ypos);
	void Update();

	~ControlHandler();

};
