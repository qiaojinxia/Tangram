#pragma once

#include "Tangram/Layer.h"
#include "Tangram/Events/MouseEvent.h"
#include "Tangram/Events/KeyEvent.h"
#include "Tangram/Events/ApplicationEvent.h"

namespace Tangram {
	class TANGRAM_API ImGuiLayer:public Layer {
	public:
		ImGuiLayer();
		~ImGuiLayer();
		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;
		void Begin();
		void End();
	private:
		float m_Time = 0.0f;
	};
}