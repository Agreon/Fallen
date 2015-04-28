#include "MenuObject.h"

MenuObject::MenuObject(std::string name, std::string command, Rect rect)
{
	m_Name = name;
	m_Command = command;
	m_Rect = rect;
}

MenuObject::~MenuObject()
{
	EraseChildren();
}
	
std::string MenuObject::Update()
{
	for(auto& obj : m_Children)
	{
		std::string command = obj->Update();
		if(command != "")
		{
			return command;
		}
	}


} 

void MenuObject::Draw()
{
	m_Graphics->drawRectangle(m_Rect.x,m_Rect.y,m_Rect.w,m_Rect.h);
}
	
void MenuObject::AddChild(MenuObject *object)
{
	object->SetParent(this);
	object->SetManager(m_Scene, m_Graphics,m_Animations,m_Input,m_Sound);

	m_Children.push_back(object);
}

void MenuObject::EraseChildren()
{	
	for (int i = 0; i < m_Children.size(); i++)
	{
		delete m_Children[i];
	}
	//TODO: m_Children.erase();
}


void MenuObject::SetManager(Scene *scene, AL::Graphics *graphics, AL::AnimationManager *animManager, AL::Input *input, AL::Sound *sound)
{
	m_Scene = scene;
	m_Graphics = graphics;
	m_Animations = animManager;
	m_Input = input;
	m_Sound = sound;
}


void MenuObject::SetParent(MenuObject *obj)
{
	m_Parent = obj;
}

void MenuObject::SetActive(bool b)
{
	m_Active = b;
}

bool MenuObject::IsActive()
{
	return m_Active;
}

std::string MenuObject::GetName()
{
	return m_Name;
}