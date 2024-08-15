#pragma once

#ifdef SP_PLATFORM_WINDOWS

extern Spot::Application* Spot::CreateApplication();

int main(int argc, char* argv[])
{
	Spot::Log::Init();
	SP_CORE_WARN("Initialized log");
	int a = 3;
	SP_INFO("Initialized log Var={0}", a);
	

	auto app = Spot::CreateApplication();
	app->Run();
	delete app;
}

#else
#error Sport Engine only supports Windows Systems!
#endif