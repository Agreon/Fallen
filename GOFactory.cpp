#include "GOFactory.h"

GOFactory::GOFactory(Scene *scene, AL::Graphics *graphic, AL::AnimationManager *animManager, AL::Input *input, AL::Sound *sound)
{
	m_Scene = scene;
	m_Graphics = graphic;
	m_Input = input;
	m_Animations = animManager;
	m_Sound = sound;
}

GOFactory::~GOFactory()
{
}

bool GOFactory::Init(std::string dataFile)
{
	Document objects = JsonParser::LoadJSON(dataFile);
	if(objects == NULL || objects.IsObject() == false)
	{
		AL::Log::write(AL::LOG_ERROR,"GameObject Factory","Could not load objects from "+dataFile);
		return false;
	}

	for (int i = 0; i < objects["GameObjects"].Size(); i++)
	{
		Value& obj = objects["GameObjects"][i];

		GameObject *object;

		/*if(obj["type"] == "enemy")
		{

		}
		else if(obj["type"] == "player")
		{

		}
		else if(obj["type"] == "item")
		{

		}
		else
		{*/
			int w, h;
			if(obj.HasMember("width") && obj.HasMember("height"))
			{
				w = obj["width"].GetInt();
				h = obj["height"].GetInt();
			}
			else
			{
				w = m_Graphics->getTextureWidth(obj["name"].GetString());
				h = m_Graphics->getTextureHeight(obj["name"].GetString());
			}

			object = new GameObject(obj["type"].GetString(), obj["name"].GetString(), Rect(0,0,w,h), m_Scene, m_Graphics, m_Animations, m_Input, m_Sound);
		//}

		AL::Log::write(AL::LOG_INFORMATION, "JSON Parser", "Loaded object: " + std::string(obj["name"].GetString()));

		for (Value::ConstMemberIterator itr = obj["attributes"].MemberBegin(); itr != obj["attributes"].MemberEnd(); ++itr)
		{
			object->SetAttribute(itr->name.GetString(),itr->value.GetInt());
			AL::Log::write(AL::LOG_INFORMATION, "JSON Parser", itr->name.GetString() + std::string(": ") + std::to_string(itr->value.GetInt()));
		}

		m_Objects[obj["name"].GetString()] = object;
	}

	return true;
}

/*
TODO: The right copy constuctor
*/
GameObject* GOFactory::CreateObject(std::string name)
{
	return new GameObject(*m_Objects[name]);
}

GameObject* GOFactory::CreateObject(std::string name, int x, int y)
{
	GameObject *obj = new GameObject(m_Objects[name]);
	Rect r = obj->GetRect();
	obj->SetRect(Rect(x,y,r.w,r.h));
	return obj;
}