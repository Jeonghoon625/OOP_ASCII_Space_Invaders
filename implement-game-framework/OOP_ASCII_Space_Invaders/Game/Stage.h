#pragma once

//����
//1. ���������� �ҷ���
//2. �������� ���� ��Ȳ�� ����
//3. ���������� Ŭ���� �ƴ���

typedef enum MapType
{
	MAPTYPE_WALL = '#',
	MAPTYPE_PLAYER = 'A',
	MAPTYPE_ENEMY_TYPE_A = '@',
	MAPTYPE_ENEMY_TYPE_B = 'O',
	MAPTYPE_PLAYER_BULLET = '^',
	MAPTYPE_ENEMY_BULLET = 'U',
	MAPTYPE_DEAD = 'X',
	MAPTYPE_PATH = ' '
} EMapType;

typedef enum StageLevel
{
	STAGE_01 = 1,
	STAGE_MAX = 3
} EStageLevel;

/// <summary>
/// ���������� �ε��Ѵ�.
/// </summary>
void LoadStage(EStageLevel level);

/// <summary>
/// ���������� ������Ʈ�Ѵ�.
/// </summary>
void UpdateStage();

/// <summary>
/// ���� ��ȯ�Ѵ�.
/// </summary>
/// <returns></returns>
const char** GetMap();
