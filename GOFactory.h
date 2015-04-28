#ifndef GO_FACTORY_H
#define GO_FACTORY_H

#include "AgreonLibrary2/AL.h"
#include "GameObject.h"

using namespace rapidjson;

class Scene;

class GOFactory
{
private:
	std::map<std::string,GameObject*> m_Objects;

	Scene *m_Scene;
	AL::Graphics *m_Graphics;
	AL::Input *m_Input;
	AL::AnimationManager *m_Animations;
	AL::Sound *m_Sound;

public:
	GOFactory(Scene *scene, AL::Graphics *graphic, AL::AnimationManager *animManager, AL::Input *input, AL::Sound *sound);
	~GOFactory();

	bool Init(std::string dataFile);

	GameObject* CreateObject(std::string name);
	GameObject* CreateObject(std::string name, int x, int y);
};

#endif // GO_FACTORY_H