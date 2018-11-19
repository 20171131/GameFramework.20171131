#pragma once
#include "SDLGameObject.h"

class Player :public SDLGameObject
{
private:
	void handleInput();
	const int offset;

public:
	Player(const LoaderParams* pParams);
	Player(const LoaderParams* pParams, const int offset);

	void draw() override;
	void update() override;
	void clean() override;
};