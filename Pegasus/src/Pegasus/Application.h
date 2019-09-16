#pragma once

namespace Pegasus {

	class __declspec(dllexport) Application;

	class Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	//To be defined in Application
	Application* CreateApplication();
}
