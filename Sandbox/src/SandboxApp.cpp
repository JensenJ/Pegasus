#include <Pegasus.h>

class ExampleLayer : public Pegasus::Layer {
public:
	ExampleLayer()
		: Layer("Example"){}

	void OnUpdate() override {
		PG_INFO("ExampleLayer::Update");
	}

	void OnEvent(Pegasus::Event& event) override {
		PG_TRACE("{0}", event);
	}
};

class Sandbox : public Pegasus::Application {
public:
	Sandbox() {
		PushLayer(new ExampleLayer());
		PushOverlay(new Pegasus::ImGuiLayer());
	}

	~Sandbox() {

	}
};

Pegasus::Application* Pegasus::CreateApplication() {
	return new Sandbox();
}