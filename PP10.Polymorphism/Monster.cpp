#include "Game.h"
#include <SDL_image.h>
#include <iostream>
#include "TextureManager.h"
#include "Monster.h"
#include "GameObject.h"

void Monster::update()
{
	if (m_x > 350)
	{
		a = -num;
	}
	else if (m_x < 100)
	{
		a = num;
	}
	m_x += a;

	m_currentFrame = int(((SDL_GetTicks() / 100) % 4));
}
