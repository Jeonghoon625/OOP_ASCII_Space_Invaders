#include "stdafx.h"
#include "Stage.h"
#include "Framework/Timer.h"
#include "Framework/Input.h"
#include "Player.h"
#include "Enemy.h"
#include "ControlHandler.h"

static int stageNum = STAGE_01;
static char s_map[MAP_SIZE][MAP_SIZE];
static ControlHandler handler;

bool gameOver = false;

char parseMapType(size_t i, size_t j, char mapType)
{
	switch (mapType)
	{
	case '\n':
		return false;

	case MAPTYPE_WALL:
		s_map[i][j] = mapType;
		return true;

	case MAPTYPE_PLAYER:
		handler.NewPlayer(new Player((int)j, (int)i));
		s_map[i][j] = mapType;
		return true;

	case MAPTYPE_ENEMY_TYPE_A:
		handler.NewEnemy(new Enemy(MAPTYPE_ENEMY_TYPE_A, (int)j, (int)i, 2));
		s_map[i][j] = mapType;
		return true;

	case MAPTYPE_ENEMY_TYPE_B:
		handler.NewEnemy(new Enemy(MAPTYPE_ENEMY_TYPE_B, (int)j, (int)i, 1));
		s_map[i][j] = mapType;
		return true;

	default :
		s_map[i][j] = mapType;
		return true;
	}
}

void clearStage()
{
	memset(s_map, ' ', sizeof(s_map));
	for (size_t i = 0; i < MAP_SIZE; ++i)
	{
		s_map[i][MAP_SIZE - 1] = '\0';
	}
}

void LoadStage(EStageLevel level)
{
	assert(STAGE_01 <= level && level <= STAGE_MAX);

	static char path[MAX_PATH] = { 0 };

	sprintf_s(path, sizeof(path), "Stage/Stage%02d.txt", level);
	FILE* fp = NULL;
	fopen_s(&fp, path, "r");
	assert(fp != NULL);

	clearStage();

	for (size_t i = 0; i < MAP_SIZE; ++i)
	{
		for (size_t j = 0; j < MAP_SIZE; ++j)
		{
			char ch = fgetc(fp);

			if (false == parseMapType(i, j, ch))
			{
				break;
			}
		}

		if (feof(fp))
		{
			break;
		}
	}

	handler.NewMap(s_map);
	fclose(fp);
}

bool StageOver()
{
	return false;
}

void UpdateStage()
{
	handler.Update();
}

const char** GetMap()
{
	return (const char**)s_map;
}