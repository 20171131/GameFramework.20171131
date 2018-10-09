#include "SDL.h"

class Game
{
	SDL_Texture* m_pTexture; // the new SDL_Texture variable
	SDL_Rect m_sourceRectangle; // 원본 사각형 
	SDL_Rect m_destinationRectangle; // 대상 사각형 

public:
	Game() { init("Chapter 1", 100, 100, 640, 480, false); }
	~Game() { }

	bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void render();
	void update();
	void handleEvents();
	void clean();
	bool running() { return m_bRunning; }
	void drawsprite(int x, int y, int w, int h);

private:
	SDL_Window * m_pWindow;
	SDL_Renderer* m_pRenderer;

	bool m_bRunning;
};