#pragma once

#include "Core.h"

namespace Pegasus {

	class PEGASUS_API Application;

	class Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	//To be defined in application
	Application* CreateApplication();

}
