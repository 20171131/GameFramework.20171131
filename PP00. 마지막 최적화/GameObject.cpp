#include "GameObject.h"
#include <SDL_image.h>

void GameObject::draw()
{
}

void GameObject::update()
{
	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
}

void GameObject::clean()
{

}