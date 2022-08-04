#include <Tangram.h>
#include "imgui/imgui.h"


//------------------------------
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
	virtual void OnImGuiRender() override
	{
		ImGui::Begin("Test");
		ImGui::Text("Hello World");
		ImGui::End();
	}

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

	}
	~Sandbox() 
	{

	}
};

Tangram::Application* Tangram::CreateApplication() {
	return new Sandbox();
}
