#include "UI.h"

UI::UI(Scene *scene, AL::Graphics *graphics, AL::AnimationManager *animManager, AL::Input *input, AL::Sound *sound)
{
	m_Scene = scene;
	m_Graphics = graphics;
	m_Animations = animManager;
	m_Input = input;
	m_Sound = sound;
}

UI::~UI()
{
	for(auto& obj : m_MenuObjects)
	{
		delete obj.second;
	}
}

std::string UI::Update()
{
	for(auto& keys : m_KeyBindings)
	{
		if(m_Input->isKeyReleased(keys.first))
		{
			if(keys.second->IsActive()) keys.second->SetActive(false);
			else keys.second->SetActive(true);
		}
	}
	for(auto& obj : m_MenuObjects)
	{
		if(obj.second->IsActive() == false) continue;

		std::string command = obj.second->Update();
		if(command != "")
		{
			return command;
		}
	}
}

void UI::Draw()
{
	for(auto& obj : m_MenuObjects)
	{
		obj.second->Draw();
	}
}

void UI::AddMenuObject(MenuObject *object)
{
	object->SetManager(m_Scene, m_Graphics,m_Animations,m_Input,m_Sound);
	m_MenuObjects[object->GetName()] = object;
}

void UI::AddMenuObject(MenuObject *object, char key)
{
	object->SetManager(m_Scene, m_Graphics,m_Animations,m_Input,m_Sound);
	m_MenuObjects[object->GetName()] = object;
	m_KeyBindings[key] = object;
}

MenuObject* UI::GetMenuObejct(std::string name)
{
	return m_MenuObjects[name];
}