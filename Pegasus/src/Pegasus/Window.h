#pragma once

#include "pgpch.h"

#include "Pegasus/Core.h"
#include "Pegasus/Events/Event.h"

namespace Pegasus {
	struct WindowProps {
		std::string Title;
		unsigned int Width, Height;

		WindowProps(const std::string& title = "Pegasus", unsigned int width = 1920, unsigned int height = 1080)
			: Title(title), Width(width), Height(height) {

		}
	};

	class PEGASUS_API Window {
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window() {}

		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		static Window* Create(const WindowProps& props = WindowProps());
	};
}