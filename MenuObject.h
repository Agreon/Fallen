#include "AgreonLibrary2/AL.h"
#include "Scene.h"
#include <vector>

class MenuObject
{
private:
	std::string m_Name;
	std::string m_Command;
	Rect m_Rect;
	bool m_Active;

	MenuObject *m_Parent;
	std::vector<MenuObject*> m_Children;

	Scene *m_Scene;
	AL::Graphics *m_Graphics;
	AL::Input *m_Input;
	AL::AnimationManager *m_Animations;
	AL::Sound *m_Sound;
public:
	MenuObject(std::string name, std::string command, Rect rect);
	~MenuObject();
	
	std::string Update();
	void Draw();
	void AddChild(MenuObject *object);
	void EraseChildren();

	void SetManager(Scene *scene, AL::Graphics *graphics, AL::AnimationManager *animManager, AL::Input *input, AL::Sound *sound);
	void SetParent(MenuObject *obj);
	void SetActive(bool b);

	bool IsActive();
	std::string GetName();
};