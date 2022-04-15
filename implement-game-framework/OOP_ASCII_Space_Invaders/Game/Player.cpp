#include "stdafx.h"
#include "Framework/Input.h"
#include "Player.h"

Player::Player(int xpos, int ypos) : playerXpos(xpos), playerYpos(ypos)
{
}

int Player::GetXpos()
{
	return playerXpos;
}

int Player::GetYpos()
{
	return playerYpos;
}

void Player::nextPos() 
{
	if (GetButtonDown(KEYCODE_A))
	{
		playerXpos--;
	}

	else if (GetButtonDown(KEYCODE_D))
	{
		playerXpos++;
	}

	else if (GetButtonDown(KEYCODE_W))
	{
		playerYpos--;
	}

	else if (GetButtonDown(KEYCODE_S))
	{
		playerYpos++;
	}
}