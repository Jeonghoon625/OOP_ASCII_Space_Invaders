#include "stdafx.h"
#include "Framework/Input.h"
#include "Framework/Timer.h"
#include "ControlHandler.h"
#include "Stage.h"

ControlHandler::ControlHandler() : player(nullptr), s_map(nullptr), 
bulletNum(0), enemyNum(0), shootTimer(0.0)
{
	for (int i = 0; i < BULLET_MAX; i++)
	{
		bullet[i] = nullptr;
	}

	for (int i = 0; i < ENEMY_MAX; i++)
	{
		enemy[i] = nullptr;
	}
}

void ControlHandler::NewPlayer(Player* player)
{
	this->player = player;
}

void ControlHandler::NewEnemy(Enemy* enemy)
{
	this->enemy[enemyNum] = enemy;
	enemyNum++;
}

void ControlHandler::NewMap(char(* s_map)[MAP_SIZE])
{
	this->s_map = s_map;
}

void ControlHandler::NewBullet()
{
	shootTimer += GetDeltaTime();
	double shootDelayTime = 0.3;
	if (GetButtonDown(KEYCODE_W) && shootTimer >= shootDelayTime && bulletNum < BULLET_MAX)
	{
		this->bullet[bulletNum] = new Bullet(MAPTYPE_PLAYER, player->GetXpos(), player->GetYpos() - 1);
		s_map[bullet[bulletNum]->GetYpos()][bullet[bulletNum]->GetXpos()] = MAPTYPE_PLAYER_BULLET;
		bulletNum++;
		shootTimer = 0.0;
	}
}

void ControlHandler::Update()
{
	NewBullet();
	for (int i = 0; i < bulletNum; i++)
	{
		if (bullet[i] != nullptr)
		{
			int currXpos = bullet[i]->GetXpos();
			int currYpos = bullet[i]->GetYpos();
			bullet[i]->Move();
			CrashBullet(currXpos, currYpos, i);
		}
	}

	int currXpos = player->GetXpos();
	int currYpos = player->GetYpos();
	player->Move();
	CrashPlayer(currXpos, currYpos, player->GetXpos(), player->GetYpos());

	
}

void ControlHandler::CrashBullet(int currXpos, int currYpos, int idx)
{
	int EnemyIdx = -1;

	switch (s_map[bullet[idx]->GetYpos()][bullet[idx]->GetXpos()])
	{
	case MAPTYPE_WALL: 
		s_map[currYpos][currXpos] = ' ';
		delete bullet[idx];
		bullet[idx] = nullptr;

		for (int i = idx; i < bulletNum - 1; i++)
		{
			bullet[i] = bullet[i + 1];
		}

		bullet[bulletNum - 1] = nullptr;

		bulletNum--;
		break;

	case MAPTYPE_ENEMY_TYPE_A:
		EnemyIdx = FindEnemyIdx(bullet[idx]->GetXpos(), bullet[idx]->GetYpos());
		enemy[EnemyIdx]->Damage();
		s_map[bullet[idx]->GetYpos()][bullet[idx]->GetXpos()] = enemy[EnemyIdx]->GetType();

		s_map[currYpos][currXpos] = ' ';
		delete bullet[idx];
		bullet[idx] = nullptr;

		for (int i = idx; i < bulletNum - 1; i++)
		{
			bullet[i] = bullet[i + 1];
		}

		bullet[bulletNum - 1] = nullptr;

		bulletNum--;
		break;
	
	case MAPTYPE_ENEMY_TYPE_B:
		EnemyIdx = FindEnemyIdx(bullet[idx]->GetXpos(), bullet[idx]->GetYpos());
		enemy[EnemyIdx]->Damage();
		if (enemy[EnemyIdx]->Die())
		{
			delete enemy[EnemyIdx];
			enemy[EnemyIdx] = nullptr;
			for (int i = EnemyIdx; i < enemyNum - 1; i++)
			{
				enemy[i] = enemy[i + 1];
			}
			enemy[enemyNum - 1] = nullptr;
			enemyNum--;
			s_map[bullet[idx]->GetYpos()][bullet[idx]->GetXpos()] = ' ';
		}

		s_map[currYpos][currXpos] = ' ';
		delete bullet[idx];
		bullet[idx] = nullptr;

		for (int i = idx; i < bulletNum - 1; i++)
		{
			bullet[i] = bullet[i + 1];
		}

		bullet[bulletNum - 1] = nullptr;

		bulletNum--;
		break;

	case MAPTYPE_PATH:
		s_map[currYpos][currXpos] = ' ';
		s_map[bullet[idx]->GetYpos()][bullet[idx]->GetXpos()] = MAPTYPE_PLAYER_BULLET;
		break;

	default:
		break;
	}
}

int ControlHandler::FindEnemyIdx(int xpos, int ypos)
{
	for (int i = 0; i < enemyNum; ++i)
	{
		if (enemy[i]->GetXpos() == xpos && enemy[i]->GetYpos() == ypos)
		{
			return i;
		}
	}

	return -1;
}

void ControlHandler::CrashPlayer(int currXpos, int currYpos, int xpos, int ypos)
{
	switch (s_map[ypos][xpos])
	{
	case MAPTYPE_WALL :
		player->SetXpos(currXpos);
		player->SetYpos(currYpos);
		break;

	case MAPTYPE_PATH :
		s_map[currYpos][currXpos] = ' ';
		s_map[player->GetYpos()][player->GetXpos()] = 'A';
		break;

	default :
		break;
	}
}

ControlHandler::~ControlHandler()
{
	delete player;
	for (int i = 0; i < enemyNum; i++ )
	{
		delete enemy[i];
	}
}


