#ifndef SCENE_H
#define SCENE_H

#include "AgreonLibrary2/AL.h"
#include "GameObject.h"
#include <vector>
#include <map>

class Scene
{
private:
	std::map<std::string,std::vector<GameObject*>> m_Objects;
	GameObject *m_LastAddedObject;
	Vec2 m_Translation;
	// Map m_CurrentMap;
public:
	Scene();
	~Scene();

	void Update();
	void Draw();
	void Clear();
	//void LoadMap(Map *map);

	// Objects
	void AddObject(GameObject* object);
	GameObject* GetObject(int ID);
	std::vector<GameObject*> GetObjects(std::string type);
	std::vector<GameObject*> GetObjects(std::vector<std::string> types);
	GameObject* GetFirstObject(std::string type);
	std::vector<GameObject*> GetAllObjects();
	GameObject* GetLastAddedObject(); 

	bool IsColliding(const Rect& rect1, const Rect& rect2) const;
	bool IsColliding(const Vec2& vec, const Rect& rect) const;

	void Translate(int x, int y);
	void SetTranslation(int x, int y);
};

#endif // SCENE_H