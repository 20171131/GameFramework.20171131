#pragma once
#include "SDL.h"
#include "GameObject.h"
#include <vector>
#include <map>

class Game
{
private:
	Game() {}
	static Game* s_pInstance;

	SDL_Window * m_pWindow;
	SDL_Renderer* m_pRenderer;
	bool m_bRunning;
	int m_currentFrame;

	std::vector<GameObject*> m_gameObjects;

public:
	~Game() {}
	static Game* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new Game();
			return s_pInstance;
		}
		return s_pInstance;
	}
	
	SDL_Renderer* getRenderer() const { return m_pRenderer; }
	bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void render();
	void update();
	void handleEvents();
	const bool running() const { return m_bRunning; }
	void clean();
	void quit();

	SDL_Texture* m_pTexture; 
	SDL_Rect m_sourceRectangle;
	SDL_Rect m_destinationRectangle; 

};	typedef Game TheGame;
