#include "GameState.h"
#include "Scene.h"
#include "GOFactory.h"
#include "UI.h"

#include <iostream>
using namespace std;

class GS_Game : 
	public GameState
{
private:
	Scene *m_Scene;
	GOFactory *m_GOFactory;
	UI *m_UI;
public:
	GS_Game( AL::Graphics *graphics, AL::AnimationManager *animManager, AL::Input *input, AL::Sound *sound);
	~GS_Game();
    void	Event();
    int		Update(double delta);
    void	Draw();
};