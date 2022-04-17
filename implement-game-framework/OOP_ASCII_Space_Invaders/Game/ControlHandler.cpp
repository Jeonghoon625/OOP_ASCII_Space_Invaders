#include "stdafx.h"
#include "Framework/Input.h"
#include "ControlHandler.h"
#include "Stage.h"

ControlHandler::ControlHandler() : player(nullptr), enemy(nullptr), s_map(nullptr), bullet(nullptr)
{
}

void ControlHandler::NewPlayer(Player* player)
{
	this->player = player;
}

void ControlHandler::NewEnemy(Enemy* enemy)
{
	this->enemy = enemy;
}

void ControlHandler::NewMap(char(* s_map)[MAP_SIZE])
{
	this->s_map = s_map;
}

void ControlHandler::NewBullet()
{
	if (GetButtonDown(KEYCODE_W))
	{
		this->bullet = new Bullet(MAPTYPE_PLAYER, player->GetXpos(), player->GetYpos() - 1);
		s_map[bullet->GetYpos()][bullet->GetXpos()] = MAPTYPE_PLAYER_BULLET;
	}
}

void ControlHandler::Update()
{
	NewBullet();
	if (bullet != nullptr)
	{
		int currXpos = bullet->GetXpos();
		int currYpos = bullet->GetYpos();
		bullet->Move();
		CrashBullet(currXpos, currYpos, bullet->GetXpos(), bullet->GetYpos());
	}
	int currXpos = player->GetXpos();
	int currYpos = player->GetYpos();
	player->Move();
	CrashPlayer(currXpos, currYpos, player->GetXpos(), player->GetYpos());
}

void ControlHandler::CrashBullet(int currXpos, int currYpos, int xpos, int ypos)
{
	switch (s_map[ypos][xpos])
	{
	case MAPTYPE_WALL:
		s_map[currYpos][currXpos] = ' ';
		delete bullet;
		bullet = nullptr;
		break;

	case MAPTYPE_PATH:
		s_map[currYpos][currXpos] = ' ';
		s_map[bullet->GetYpos()][bullet->GetXpos()] = MAPTYPE_PLAYER_BULLET;
		break;

	default:
		break;
	}
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
	delete enemy;
}


