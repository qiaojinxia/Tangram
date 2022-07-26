#pragma once

#include "Tangram/Layer.h"
#include "Tangram/Events/MouseEvent.h"
#include "Tangram/Events/KeyEvent.h"
#include "Tangram/Application.h"
namespace Tangram {
	class TANGRAM_API ImGuiLayer:public Layer {
	public:
		ImGuiLayer();
		~ImGuiLayer();
		void OnAttach() override;
		void OnDetach() override;
		void OnUpdate() override;
		void OnEvent(Event& event) override;

	private:
		bool OnMouseButtonPressedEvent(MouseButtonPressedEvent& e) ;
		bool OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& e);
		bool OnMouseMovedEvent(MouseMovedEvent& e);
		bool OnMouseScrolledEvent(MouseScrolledEvent& e);
		bool OnKeyPressedEvent(KeyPressedEvent& e);
		bool OnKeyTypedEvent(KeyTypedEvent& e);
		bool OnKeyKeyReleasedEvent(KeyReleasedEvent& e);
		bool OnWindowsResizeEvent(WindowsResizeEvent& e);

	private:
		float m_Time = 0.0f;
	};
}