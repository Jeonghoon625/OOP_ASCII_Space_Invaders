#pragma once

//����
//1. ���������� �ҷ���
//2. �������� ���� ��Ȳ�� ����
//3. ���������� Ŭ���� �ƴ���

typedef enum MapType
{
	MAPTYPE_WALL = '|',
	MAPTYPE_PLAYER = 'A',
	MAPTYPE_PLAYER_BULLET = '^',
	MAPTYPE_ENEMY_TYPE_A = 'O',
	MAPTYPE_ENEMY_TYPE_B = 'M',
	MAPTYPE_ENEMY_DEAD = 'X',
	MAPTYPE_ENEMY_BULLET = 'U',
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
