#include <glEngine.h>

class Sandbox : public glEngine::Application
{

};

glEngine::Application* glEngine::CreateApplication()
{
	return new Sandbox();
}