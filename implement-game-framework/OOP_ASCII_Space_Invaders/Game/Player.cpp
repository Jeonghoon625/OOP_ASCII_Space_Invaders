#include "stdafx.h"
#include "Framework/Input.h"
#include "Player.h"
#include "Stage.h"

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

void Player::SetXpos(int xpos)
{
	playerXpos = xpos;
}

void Player::SetYpos(int ypos)
{
	playerYpos = ypos;
}

void Player::Move() 
{
	if (GetButtonDown(KEYCODE_A))
	{
		playerXpos--;
	}

	else if (GetButtonDown(KEYCODE_D))
	{
		playerXpos++;
	}
}