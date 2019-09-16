#include "Pegasus.h"

class Sandbox : public Pegasus::Application {
public:
	Sandbox() {

	}

	~Sandbox() {

	}
};

int main() {
	Sandbox* sandbox = new Sandbox();
	sandbox->Run();
	delete sandbox;
}