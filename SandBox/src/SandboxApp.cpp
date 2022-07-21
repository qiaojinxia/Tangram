#include <Tangram.h>
#include <Tangram/Events/KeyEvent.h>
#include "glm/glm.hpp"

#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/ext/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale
#include <glm/ext/matrix_clip_space.hpp> // glm::perspective
#include <glm/ext/scalar_constants.hpp> // glm::pi


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
