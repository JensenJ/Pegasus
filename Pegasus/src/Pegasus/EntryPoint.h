#pragma once

#ifdef PG_PLATFORM_WINDOWS

extern Pegasus::Application* Pegasus::CreateApplication();

int main(int argc, char** argv) {
	Pegasus::Log::Init();
	PG_CORE_WARN("Initialised Log");
	PG_INFO("Initialised Log");

	auto app = Pegasus::CreateApplication();
	app->Run();
	delete app;
	}

#endif