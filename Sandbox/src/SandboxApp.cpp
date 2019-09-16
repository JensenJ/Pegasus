#include <Pegasus.h>

class Sandbox : public Pegasus::Application {
public:
	Sandbox() {

	}

	~Sandbox() {

	}
};

Pegasus::Application* Pegasus::CreateApplication() {
	return new Sandbox();
}