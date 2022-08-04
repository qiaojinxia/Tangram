#include "tgpch.h"
#include "OpenGLContext.h"
#include <GLFW/glfw3.h>
#include "glad/glad.h"
#include "Tangram/Log.h"

namespace Tangram {
	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
	{
		TG_CORE_ASSERT(windowHandle, "windowHandle not be null");
		m_WindowHandle = windowHandle;
	}
	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		TG_CORE_ASSERT(status, "Failed to initialize Glad!");
	}
	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(m_WindowHandle);
	}
}