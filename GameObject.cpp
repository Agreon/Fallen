#include "GameObject.h"

static int GO_ID;

GameObject::GameObject(GameObject *obj)
{
	m_ObjectID = ++GO_ID;
	m_Type = obj->GetType();
	m_Name = obj->GetName();
	m_Destroyed = false;
	m_Visible = obj->IsVisible();
	m_Rect = obj->GetRect();
	m_Scene = obj->GetScene();
	m_Graphics = obj->GetGraphics();
	m_Animations = obj->GetAnimations();
	m_Input = obj->GetInput();
	m_Sound = obj->GetSound();
}

GameObject::GameObject(std::string type, std::string name, Rect rect, Scene *scene, AL::Graphics *graphics, AL::AnimationManager *animManager, AL::Input *input, AL::Sound *sound)
{
	m_ObjectID = ++GO_ID;
	m_Type = type;
	m_Name = name;
	m_Destroyed = false;
	m_Visible = true;
	m_Rect = rect;

	m_Scene = scene;
	m_Graphics = graphics;
	m_Animations = animManager;
	m_Input = input;
	m_Sound = sound;
}

GameObject::~GameObject()
{
}

void GameObject::Update()
{
}

void GameObject::Draw()
{
	if(m_Visible) m_Graphics->drawTexture(m_Name,m_Rect.x,m_Rect.y);
}