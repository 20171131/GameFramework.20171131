#pragma once
#include "SDL.h"
#include <map>

class GameObject
{
public:
	void load(int x, int y, int width, int height, std::string textureID);
	void draw(SDL_Renderer* pRenderer);
	void update();
	void clean();

protected:
	std::string m_textureID;
	int m_currentFrame;
	int m_currentRow;
	int m_x;
	int m_y;
	int m_width;
	int m_height;

private:
	std::vector<GameObject*>m_gameObject;

	GameObject* m_go;
	GameObject* m_player;
	GameObject* m_enemy;
};
