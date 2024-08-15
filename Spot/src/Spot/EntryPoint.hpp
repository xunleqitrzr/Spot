#pragma once

#ifdef SP_PLATFORM_WINDOWS

extern Spot::Application* Spot::CreateApplication();

int main(int argc, char* argv[])
{
	auto app = Spot::CreateApplication();
	app->Run();
	delete app;
}

#else
#error Sport Engine only supports Windows Systems!
#endif