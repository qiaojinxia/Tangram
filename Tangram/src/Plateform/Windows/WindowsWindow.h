#pragma once
#include "Tangram/Window.h"
#include <GLFW/glfw3.h>
#include "Tangram/Renderer/GraphicsContext.h"

struct GLFWwindow ;
 namespace Tangram{
	class TANGRAM_API WindowsWindow : public Window {
	public:
		WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow();
		void OnUpdate() override;

		inline unsigned int GetWeight() const override { return m_Data.Width; }
		inline unsigned int GetHeight() const override { return m_Data.Height;}

		inline void SetEventCallback  (const EventCallbackFn& callback) override {
			m_Data.EventCallback = callback;} 
		void  SetVSync(bool enabled) override;
		bool IsVSync() const override;
	private:
		virtual void Init (const WindowProps& props) ;
		virtual void Shutdown();
		inline virtual void* GetNativateWindow() const { return m_Window; };
	private:
		GLFWwindow* m_Window;
		GraphicsContext* m_Context;
		struct  WindowData
		{
			std::string Title;
			unsigned int Width{0}, Height{0};
			bool Vsync;
			EventCallbackFn EventCallback;
		};

		WindowData m_Data;
	};
}