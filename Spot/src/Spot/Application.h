#pragma once

#include "Core.h"

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
