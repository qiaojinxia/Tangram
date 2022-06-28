#pragma once
#include "Event.h"
#include <sstream>

namespace Tangram {
	class TANGRAM_API WindowsResizeEvent :public Event {
	private:
		unsigned int m_Width, m_Height;
	public:
		WindowsResizeEvent(unsigned int width, unsigned int heigt) :m_Width(width),m_Height(heigt){}
		inline unsigned int GetWidth() const { return m_Width;}
		inline unsigned int GetHeight() const { return m_Height; }
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "WindowResizeEvent:" << m_Width << "," << m_Height;
			return ss.str();
		}
		EVENT_CLASS_TYPE(WindowResize)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};
	class TANGRAM_API WindowCloseEvent :public Event {
	public:
		WindowCloseEvent() {}
		EVENT_CLASS_TYPE(WindowClose)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)

	};

	class TANGRAM_API AppTickEvent :public Event {
	public:
		AppTickEvent() {}
		EVENT_CLASS_TYPE(AppTick)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class TANGRAM_API AppUpdateEvent :public Event {
	public:
		AppUpdateEvent() {}
		EVENT_CLASS_TYPE(AppUpdate)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};
	class TANGRAM_API AppRenderEvent :public Event {
		AppRenderEvent() {}
		EVENT_CLASS_TYPE(AppRender)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};
}