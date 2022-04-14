#include "stdafx.h"
#include "Stage.h"
#include "Framework/Timer.h"
#include "Framework/Input.h"
#include "Player.h"

static int stageNum = STAGE_01;
static char s_map[MAP_SIZE][MAP_SIZE];
static int32_t s_playerX = 0;
static int32_t s_playerY = 0;

bool gameOver = false;

void PlayerMove()
{
	int32_t s_nextPlayerX = s_playerX;
	int32_t s_nextPlayerY = s_playerY;

	if (GetButtonDown(KEYCODE_A))
	{
	}

	else if (GetButtonDown(KEYCODE_D))
	{
	}

	else if (GetButtonDown(KEYCODE_R))
	{
		LoadStage((EStageLevel)stageNum);
	}
}

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
		s_playerX = (int)i;
		s_playerY = (int)j;
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

	fclose(fp);
}

bool StageOver()
{
	return false;
}

void UpdateStage()
{
	PlayerMove();
}

const char** GetMap()
{
	return (char**)s_map;
}