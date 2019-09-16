#pragma once

#ifdef PG_PLATFORM_WINDOWS

extern Pegasus::Application* Pegasus::CreateApplication();

int main(int argc, char** argv) {
	auto app = Pegasus::CreateApplication();
	app->Run();
	delete app;
	}

#endif