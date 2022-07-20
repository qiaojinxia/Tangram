#include <Tangram.h>
#include <Tangram/Events/KeyEvent.h>

class ExampleLayer :public Tangram::Layer
{
public:
	ExampleLayer():Layer("Example") {}


	void OnEvent(Event& event) override {
		if (event.GetEventType() == EventType::KeyPressed) {
			Tangram::KeyPressedEvent& e = (Tangram::KeyPressedEvent&)event;
			TG_TRACE("{0}", e.GetKeyCode());
		}

	};

	virtual void OnUpdate() override {
		if (Tangram::Input::IsKeyPressed(TG_KEY_TAB)) {
			TG_TRACE("TAB PRESSED");
		}	
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
