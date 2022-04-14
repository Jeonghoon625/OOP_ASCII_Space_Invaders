#include "stdafx.h"
#include "Renderer.h"
#include "Game/Stage.h"

static HANDLE s_consoleHandle;
static char s_map[MAP_SIZE][MAP_SIZE];

void clear()
{
	memset(s_map, ' ', sizeof(s_map));

	for (int i = 0; i < MAP_SIZE; ++i)
	{
		s_map[i][MAP_SIZE - 1] = '\0';
	}
}

bool InitializeRenderer()
{
	//�ܼ� ���μ����� �ڵ��� ����Ͽ� �ܼ��� �Է� �� ȭ�� ���ۿ� �������Ѵ�.
	// GetStdHandle �Լ��� ���μ����� ���õ� ǥ�� ����� �� ���� �ڵ��� �˻� ���� ����� �����Ѵ�.
	s_consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

	// �������� �ڵ��� INVALID_HANDLE_VALUE������ ��ȿ���� �Ǵ��Ѵ�.
	// �Ϲ������� NULL���� ���� ���� ��ȿ�� �Ǵ��ϴ� ��ó��...
	if (INVALID_HANDLE_VALUE == s_consoleHandle)
	{
		return false;
	}

	return true;
}

void RenderMap()
{
	const COORD initialPos = { 0 , 0 };
	CONSOLE_CURSOR_INFO info= {1, false};

	SetConsoleCursorPosition(s_consoleHandle, initialPos);
	SetConsoleCursorInfo(s_consoleHandle, &info);
	
	const char** stage = GetMap();
	memcpy(s_map, stage, sizeof(s_map));

	for (int i = 0; i < MAP_SIZE; ++i)
	{
		puts(s_map[i]);
	}

	// ��� �Ŀ� ���� �������� ����.
	clear();


}