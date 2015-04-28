#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "AgreonLibrary2/AL.h"
#include <string>

class Scene;

class GameObject
{
protected:
	int m_ObjectID;
	std::string m_Type;
	std::string m_Name;
	bool m_Destroyed;
	bool m_Visible;
	Rect m_Rect;
	Scene *m_Scene;
	std::map<std::string,ushort> m_Attributes;

	AL::Graphics *m_Graphics;
	AL::Input *m_Input;
	AL::AnimationManager *m_Animations;
	AL::Sound *m_Sound;
public:
	GameObject(GameObject *obj);
	GameObject(std::string type, std::string name, Rect rect, Scene *scene, AL::Graphics *graphics, AL::AnimationManager *animManager, AL::Input *input, AL::Sound *sound);
	~GameObject();
	virtual void Update();
	virtual void Draw();

	int		GetObjectID() { return m_ObjectID; }
	std::string	GetType(){ return m_Type; }
	std::string  GetName(){ return m_Name; }
	bool 	IsDestroyed(){return m_Destroyed; }
	bool 	IsVisible(){ return m_Visible; }
	Rect 	GetRect(){ return m_Rect; }
	ushort 	GetAttribute(std::string name){ return m_Attributes[name]; }
	Scene*	GetScene(){ return m_Scene; }
	AL::Graphics* GetGraphics(){ return m_Graphics; }
	AL::AnimationManager* GetAnimations(){ return m_Animations; }
	AL::Input* GetInput(){ return m_Input; }
	AL::Sound* GetSound(){ return m_Sound; }

	void SetDestroyed(bool d){ m_Destroyed = d; }
	void SetVisible(bool v){ m_Visible = v; }
	void SetRect(Rect r){ m_Rect = r; }
	void SetScene(Scene *scene){ m_Scene = scene; }
	void SetAttribute(std::string name, ushort attr){ m_Attributes[name] = attr; }
};

#endif // GAME_OBJECT_H
