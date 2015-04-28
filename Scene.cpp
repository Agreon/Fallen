#include "Scene.h"

Scene::Scene()
{
}

Scene::~Scene()
{
	for(auto& types : m_Objects)
	{
		for(auto& obj : types.second)
		{
			delete obj;
		}
	}
}

void Scene::Update()
{
	for(auto& types : m_Objects)
	{
		for(auto& obj : types.second)
		{
			obj->Update();
		}
	}
}

void Scene::Draw()
{
	glTranslatef(m_Translation.x,m_Translation.y,0);
	for(auto& types : m_Objects)
	{
		for(auto& obj : types.second)
		{
			obj->Draw();
		}
	}
	glLoadIdentity();
}

void Scene::Clear()
{
	m_Objects.clear();
}

/*void LoadMap(Map *map)
{

}*/

// Objects
void Scene::AddObject(GameObject* object)
{
	m_Objects[object->GetType()].push_back(object);
	m_LastAddedObject = object;
}

GameObject* Scene::GetObject(int ID)
{
	for(auto& types : m_Objects)
	{
		for(auto& obj : types.second)
		{
			if(obj->GetObjectID() == ID)
			{
				return obj;
			}
		}
	}
	AL::Log::write(AL::LOG_WARNING,"Scene Manager","Could not find Object with ID: "+ID);
	return NULL;
}

std::vector<GameObject*> Scene::GetObjects(std::string type)
{
	return m_Objects[type];
}

std::vector<GameObject*> Scene::GetObjects(std::vector<std::string> types)
{
	std::vector<GameObject*> v;

	for (int i = 0; i < types.size(); i++)
	{
		v.insert(v.end(), m_Objects[types[i]].begin(), m_Objects[types[i]].end());
	}
	return v;
}

GameObject* Scene::GetFirstObject(std::string type)
{
	return m_Objects[type][0];
}

std::vector<GameObject*> Scene::GetAllObjects()
{
	std::vector<GameObject*> v;

	for(auto& types : m_Objects)
	{
		v.insert(v.end(), types.second.begin(), types.second.end());
	}
	return v;
}

GameObject* Scene::GetLastAddedObject()
{
	return m_LastAddedObject;
} 

bool Scene::IsColliding(const Rect& rect1, const Rect& rect2) const
{
	if(rect1.y >= rect2.y + rect2.h) return false;
    if(rect1.x >= rect2.x+ rect2.w) return false;
    if(rect1.y + rect1.h <= rect2.y) return false;
    if(rect1.x + rect1.w <= rect2.x) return false;

	return true;
}

bool Scene::IsColliding(const Vec2& vec, const Rect& rect) const
{
	return IsColliding(rect,Rect(vec.x,vec.y,1,1));
}

void Scene::Translate(int x, int y)
{
	m_Translation.x += x;
	m_Translation.y += y;
}

void Scene::SetTranslation(int x, int y)
{
	m_Translation.x = x;
	m_Translation.y = y;
}