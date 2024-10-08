#pragma once

#include "Core.hpp"

namespace Spot {

	class SPOT_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// to be defined in client
	Application* CreateApplication();

}
