#ifndef UI_H
#define UI_H

#include "AgreonLibrary2/AL.h"
#include "MenuObject.h"

class Scene;

class UI
{
private:
	std::map<std::string,MenuObject*> m_MenuObjects;
	std::map<char,MenuObject*> m_KeyBindings;
	
	Scene *m_Scene;
	AL::Graphics *m_Graphics;
	AL::Input *m_Input;
	AL::AnimationManager *m_Animations;
	AL::Sound *m_Sound;
public:
	UI(Scene *scene, AL::Graphics *graphics, AL::AnimationManager *animManager, AL::Input *input, AL::Sound *sound);
	~UI();

	std::string Update();
	void Draw();
	void AddMenuObject(MenuObject *object);
	void AddMenuObject(MenuObject *object, char key);
	MenuObject* GetMenuObejct(std::string name);
};

#endif // UI_H

