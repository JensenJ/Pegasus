#include "pgpch.h"
#include "Application.h"

#include "Pegasus/Events/ApplicationEvent.h"
#include "Pegasus/Log.h"

namespace Pegasus {
	Application::Application() {

	}
	Application::~Application() {

	}

	void Application::Run() {
		
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication)) {
			PG_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput)) {
			PG_TRACE(e);
		}
		while (true);
	}
}