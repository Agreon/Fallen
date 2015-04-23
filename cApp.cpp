#include "cApp.h"

cApp::cApp()
{
}

cApp::~cApp()
{
}

void cApp::Run()
{
	m_Running = Init();

	while(m_Running) 
	{
	    m_Input->handleInput();

	    if(m_Input->isKeyReleased(SDLK_ESCAPE))
	    {
	    	m_Running = false;
	    }

	    glClear(GL_COLOR_BUFFER_BIT);
	    glClearColor(1,1,1,1);
	    m_Graphics->setColor(AL::color(1,1,1,1));
	    m_Graphics->drawTexture("agreon_logo",0,0);
	    m_Graphics->swapWindow();
	}

	AL::Log::write(AL::LOG_INFORMATION,"App","Shutting down..");
	SDL_Quit();
}

bool cApp::Init()
{
	AL::Log::reset();
	m_Graphics 		= new AL::Graphics();
	m_Animations	= new AL::AnimationManager(m_Graphics);
	m_Input 		= new AL::Input();
	m_Sound    		= new AL::Sound();

	if(LoadConfig() == false)
	{
		AL::Log::write(AL::LOG_ERROR,"App Initialisation", "Could not load config file!");
		return false;
	}

	m_Graphics->init(SCREEN_WIDTH,SCREEN_HEIGHT,APP_NAME.c_str(),NULL);
	SDL_ShowCursor(0);

	if(LoadResources() == false)
	{
		AL::Log::write(AL::LOG_ERROR,"App Initialisation", "Could not load resources!");
		return false;
	}


	return true;
}

bool cApp::LoadConfig()
{
	Document config = JsonParser::LoadJSON("data/config.json");
	if(config == NULL || config.IsObject() == false)
	{
		AL::Log::write(AL::LOG_ERROR,"Resource Loader","Could not load data/config.json !");
		return false;
	}	

	if((config.HasMember("AppName") 
	&& config.HasMember("ScreenWidth") 
	&& config.HasMember("ScreenHeight")
	&& config.HasMember("ResourceFile")) == false)
	{
		AL::Log::write(AL::LOG_ERROR,"Config Loader","Could not load a needed value!");
		return false;
	}

 	APP_NAME 		= config["AppName"].GetString();	
	SCREEN_WIDTH 	= config["ScreenWidth"].GetInt();
	SCREEN_HEIGHT 	= config["ScreenHeight"].GetInt();
	RESOURCE_FILE	= config["ResourceFile"].GetString();

	return true;
}

bool cApp::LoadResources()
{
	Document resources = JsonParser::LoadJSON(RESOURCE_FILE);
	if(resources == NULL)
	{
		AL::Log::write(AL::LOG_ERROR,"Resource Loader","Could not load data/config.json !");
		return false;
	}	

	for (int i = 0; i < resources["textures"].Size(); i++)
	{
		Value& obj = resources["textures"][i];
		if( m_Graphics->loadTexture(obj["src"].GetString(),obj["name"].GetString()) == false)
		{
			string error = "Could not load Texture '";
			error += obj["name"].GetString();
			error += "' from Path '";
			error += obj["src"].GetString();
			error += "'";
			AL::Log::write(AL::LOG_ERROR,"Resource Loader",error);
			return false;
		}
	}

	return true;	
}

void cApp::ChangeState()
{
}