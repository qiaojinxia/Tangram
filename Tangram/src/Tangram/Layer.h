#pragma once
#include "Tangram/Core.h"
#include "Tangram/Events/Event.h"

namespace Tangram {
	class TANGRAM_API Layer {
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer();
		virtual void OnAttach() {};
		virtual void OnDetach() {};
		virtual void OnImGuiRender() {};
		virtual void OnUpdate() {};
		virtual void OnEvent(Event& event) {};

		inline const std::string& GetName() const { return m_DebugName; };
	protected:
		std::string m_DebugName;
	};
}