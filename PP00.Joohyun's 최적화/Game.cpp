#include "Game.h"
#include <SDL_image.h>
#include <iostream>

using namespace std;

//스프라이트 파일의 크기를 상수로 선언
const int spr_width = 128;
const int spr_height = 82;

bool Game::init(const char*title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, SDL_WINDOW_SHOWN);

		if (m_pWindow != 0)
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

		m_bRunning = true;
		drawsprite(50,0,spr_width, spr_height);
		SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);
	}
	else
		return false;

	return true;
}

void Game::render()
{
	SDL_RenderClear(m_pRenderer);
	SDL_RenderCopy(m_pRenderer, m_pTexture, &m_sourceRectangle, &m_destinationRectangle);
	SDL_RenderPresent(m_pRenderer);	//draw to the screen
}

void Game::update()
{
	m_sourceRectangle.x = spr_width * int(((SDL_GetTicks() / 10) % 6));	//애니메이션 속도를 빠르게 바꿈
}

void Game::handleEvents()
{
	SDL_Event event;
	if (SDL_PollEvent(&event))
		m_bRunning = false;
}

void Game::clean()
{
	std::cout << "cleaning game" << endl;
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
	/*bool done = false;
	SDL_Event event;

	while (!done)
	{
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
				done = 1;
				break;

			case SDL_KEYDOWN:
				switch (event.key.keysym.sym)
				{
				case SDLK_ESCAPE:
					done = 1;
					break;
				}
				break;
			}
		}
	}
	SDL_Quit();*/
}

//스프라이트를 출력하는 함수 따로 정의
void Game::drawsprite(int x, int y, int w, int h)
{
	SDL_Surface* pTempSurface = IMG_Load("assets/animate-alpha.png");

	m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);
	SDL_FreeSurface(pTempSurface);

	m_destinationRectangle.x = x;
	m_sourceRectangle.x = x;
	m_destinationRectangle.y = y;
	m_sourceRectangle.y = y;
	m_destinationRectangle.w = w;
	m_sourceRectangle.w = w;
	m_destinationRectangle.h = h;
	m_sourceRectangle.h = h;
}