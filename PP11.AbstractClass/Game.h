#pragma once
#include "SDL.h"
#include "GameObject.h"
#include "Player.h"
#include <vector>

class Game
{
private:
	Game();

	bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void render();
	void update();
	void handleEvents();
	void clean();

	bool running() { return m_bRunning; }
	static Game* s_pInstance;
	static Game* Instance();
	
	SDL_Renderer* getRenderer() const { return m_pRenderer; }

private:
	SDL_Window * m_pWindow;
	SDL_Renderer* m_pRenderer;
	bool m_bRunning;
};

typedef Game TheGame;