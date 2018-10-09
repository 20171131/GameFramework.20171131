#include "Game.h"
#include <iostream>
using namespace std;

Game* g_game = 0;

int main(int argc, char* argv[])
{
	g_game = new Game();
	
	while (g_game->running())
	{
		g_game->handleEvents();
		g_game->update();
		g_game->render();
		
	}
	SDL_Delay(10000);
	g_game->clean();
	
	return 0;
}
