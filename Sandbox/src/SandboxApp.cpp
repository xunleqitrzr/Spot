#include <Spot.hpp>

class Sandbox : public Spot::Application
{
public:
	
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Spot::Application* Spot::CreateApplication()
{
	return new Sandbox();
}