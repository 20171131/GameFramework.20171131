#pragma once
#include "GameState.h"

class GameStateMachine
{
public:
	void changeState(GameState* pState);
	void pushState(GameState* pState);
	void update();
	void render();

	static GameStateMachine* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new GameStateMachine();
			return s_pInstance;
		}
		return s_pInstance;
	}

private:
	std::vector<GameState*> m_gameStates;
	GameState * m_currentState;
	GameState* m_prevState;

	static GameStateMachine* s_pInstance;
};