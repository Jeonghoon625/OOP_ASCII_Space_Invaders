#include "stdafx.h"
#include "Framework/Game.h"

/*
1. Object : 적탄환, 플레이어 탄환, 플레이어, 적
2. 이동처리 : 키입력 이동 - 플레이어(열이동, 행이동), 런타임에 따라 자동 이동 - 적탄환(아래로 이동), 플레이어 탄환(아래로 이동), 적(열이동, 행이동)
3. 충돌처리 : 플레이어 - 벽(이동불가), 적 또는 적탄환(사망, 깜빡깜빡 원위치) 적 - 벽(아래로 한칸 이동(행이동)), 플레이어 탄환(사망, 깜빡깜빡), 플레이어 탄환 - 적탄환(서로 사라짐), 탄환 - 벽(사라짐)
4. 실행순서 : 좌표 이동 처리 -> 충돌처리 -> 화면 이동 처리
*/

int main()
{
	if (false == Initialize())
	{
		puts("게임을 로딩하는 데 문제가 생겼습니다.");
		
		return 1;
	}

	return Run();
}