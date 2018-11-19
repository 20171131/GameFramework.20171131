#pragma once
#include "SDLGameObject.h"

class Enemy : public SDLGameObject
{
private:
	void handleInput();
	float speed = 1.5f;

public:
	Enemy(const LoaderParams* pParams);

	void draw() override;
	void update() override;
	void clean() override;

};