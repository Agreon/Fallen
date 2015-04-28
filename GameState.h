#pragma once

#include "AgreonLibrary2/AL.h"


class GameState
{
protected:
	AL::Graphics* m_Graphics;
	AL::Input* m_Input;
	AL::AnimationManager* m_Animations;
	AL::Sound* m_Sound;

	int m_NextState;
public:
    virtual void	Event() = 0;
    virtual int		Update( double delta ) = 0;
    virtual void	Draw() = 0;
    virtual ~GameState(){};
};

