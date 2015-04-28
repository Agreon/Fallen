#include "GS_Game.h"

GS_Game::GS_Game( AL::Graphics *graphics, AL::AnimationManager *animManager, AL::Input *input, AL::Sound *sound)
{
	m_Graphics 		= graphics;
	m_Animations	= animManager;
	m_Input 		= input;
	m_Sound 		= sound;

	m_Scene = new Scene();
	m_GOFactory = new GOFactory(m_Scene,m_Graphics,m_Animations,m_Input,m_Sound);
	m_GOFactory->Init("data/gameobjects.json");
	m_UI = new UI(m_Scene,m_Graphics,m_Animations,m_Input,m_Sound);

	m_Scene->AddObject(m_GOFactory->CreateObject("Skeleton",50,50));
}
GS_Game::~GS_Game()
{

}

void GS_Game::Event()
{
	m_NextState = STATE_NULL;
	if(m_Input->isKeyReleased('a'))
	{
		cout << "a released" << endl;
	}
}   

int GS_Game::Update(double delta)
{
	m_Scene->Update();
	string command = m_UI->Update();

	return m_NextState;
}

void GS_Game::Draw()
{
	m_Scene->Draw();
	m_UI->Draw();
}
