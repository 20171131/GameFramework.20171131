#pragma once
#include "Vector2D.h"
#include "GameObject.h"
#include "InputHandler.h"

class SDLGameObject : public GameObject
{
public:
	SDLGameObject(const LoaderParams* pParams);
	virtual void draw() override;
	virtual void update() override;
	virtual void clean() override;

protected:
	int m_width;
	int m_height;
	int m_currentRow;
	int m_currentFrame;

	std::string m_textureID;

	Vector2D m_position;
	Vector2D m_velocity;
	Vector2D m_acceleration;
};