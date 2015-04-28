#include "AgreonLibrary2/AL.h"
#include "GameState.h"
#include "GS_Game.h"

using namespace rapidjson;
using namespace std;

class cApp
{
private:
	AL::Graphics 			*m_Graphics;
	AL::AnimationManager 	*m_Animations;
	AL::Input				*m_Input;
	AL::Sound				*m_Sound;

	bool 					m_Running;

	GameState 				*m_CurrentState;
	int 					m_NextState;
	int 					m_StateID;

	// ConfigValues
	string 					APP_NAME;
	int 					SCREEN_WIDTH;
	int 					SCREEN_HEIGHT;
	string					RESOURCE_FILE;
public:
	cApp();
	~cApp();

	void Run();
	bool Init();
	bool LoadConfig();
	bool LoadResources();

	void ChangeState();
};

