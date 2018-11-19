#include "Enemy.h"

Enemy::Enemy(const LoaderParams* pParams) : SDLGameObject(pParams)
{

}

void Enemy::draw()
{
	SDLGameObject::draw();
}

void Enemy::update()
{
	m_velocity.setX(0);
	m_velocity.setY(0);

	handleInput();

	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
	printf("%f %f\n", m_position.getX(), m_position.getY());
	SDLGameObject::update();
}

void Enemy::clean()
{

}

void Enemy::handleInput()
{
	Vector2D* vec = TheInputHandler::Instance()->getMousePosition();
	Vector2D direction = *vec - m_position;
	m_velocity = direction * speed / 100;
}

