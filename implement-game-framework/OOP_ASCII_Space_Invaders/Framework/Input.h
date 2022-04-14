#pragma once

#include <stdint.h>
#include <stdbool.h>

typedef enum KeyCode
{
	KEYCODE_W = 'W',
	KEYCODE_A = 'A',
	KEYCODE_S = 'S',
	KEYCODE_D = 'D',
	KEYCODE_R = 'R'
}EKeyCode;

/// <summary>
/// �Է� ���¸� ������Ʈ�Ѵ�.
/// </summary>
void UpdateInput();

/// <summary>
/// ���� �����ӿ� ��ư�� �������� üũ�Ѵ�.
/// </summary>
/// <param name="KeyCode">���� Ű �ڵ�</param>
/// <returns>�����ٸ� true, �ƴϸ� false</returns>
bool GetButtonDown(EKeyCode keyCode);

/// <summary>
/// ���� �����ӿ� ��ư�� �������� üũ�Ѵ�.
/// </summary>
/// <param name="keyCode">����Ű�ڵ�</param>
/// <returns>�´ٸ� true, �ƴϸ� false</returns>
bool GetButtonUp(EKeyCode keyCode);

/// <summary>
/// ��ư�� ��� ���ȴ��� üũ�Ѵ�.
/// </summary>
/// <param name="keyCode">���� Ű �ڵ�</param>
/// <returns>�����ٸ� true, �ƴϸ� false</returns>
bool GetButton(EKeyCode keyCode);