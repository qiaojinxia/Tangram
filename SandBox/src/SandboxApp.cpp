#include <Tangram.h>

class ExampleLayer :public Tangram::Layer
{
public:
	ExampleLayer():Layer("Example") {}


	void OnEvent(Event& event) override {
		TG_TRACE("{0}", event);
	};

	virtual void OnUpdate() override {
		TG_INFO("ExampleLayer::Update");
	};

};

class Sandbox :public Tangram::Application {
public:
	Sandbox() {
		PushLayer(new ExampleLayer());
		PushOverlay(new Tangram::ImGuiLayer());
	}
	~Sandbox() {

	}
};

Tangram::Application* Tangram::CreateApplication() {
	return new Sandbox();
}
