#pragma once

#include "Core.h"
#include "Window.h"
#include "Pegasus/LayerStack.h"
#include "Pegasus/Events/Event.h"
#include "Pegasus/Events/ApplicationEvent.h"

namespace Pegasus {

	class __declspec(dllexport) Application;

	class Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);
	private:
		bool OnWindowClose(WindowCloseEvent& e);
		
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	};

	//To be defined in Application
	Application* CreateApplication();
}
