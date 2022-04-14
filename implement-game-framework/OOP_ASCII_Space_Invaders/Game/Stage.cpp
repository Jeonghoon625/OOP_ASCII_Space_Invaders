#include "stdafx.h"
#include "Stage.h"
#include "Framework/Timer.h"
#include "Framework/Input.h"
#include "Player.h"

static int stageNum = STAGE_01;
static char s_map[MAP_SIZE][MAP_SIZE];
static Player* player;
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
		player = new Player(j, i);
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
	int currentPlayerPosX = player->GetXpos();
	int currentPlayerPosY = player->GetYpos();
	player->UpdatePos();
	if (!((currentPlayerPosX == player->GetXpos()) && (currentPlayerPosY == player->GetYpos())))
	{
		s_map[currentPlayerPosY][currentPlayerPosX] = ' ';
		s_map[player->GetYpos()][player->GetXpos()] = 'A';
	}

}

const char** GetMap()
{
	return (const char**)s_map;
}