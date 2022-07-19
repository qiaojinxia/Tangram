#include "tgpch.h"

#include "WindowsInput.h"
#include "Tangram/Application.h"
#include <GLFW/glfw3.h>

namespace Tangram {
	Input* Input::s_Instance = new WindowsInput();

	 bool WindowsInput::IsKeyPressedImpl(int keycode)
	{
		auto window =static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativateWindow());
		auto state = glfwGetKey(window, keycode);
		return  state == GLFW_PRESS || state ==  GLFW_REPEAT;
	}
	 bool WindowsInput::IsMouseButtonPressedImpl(int button)
	 {
		 auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativateWindow());
		 auto state = glfwGetMouseButton(window, button);
		 return  state == GLFW_PRESS ;

	 }
	 float WindowsInput::GetMouseXImpl()
	 {
		 auto [x, y] = GetMousePositionImpl();
		 return x;
	 }
	 float WindowsInput::GetMouseYImpl()
	 {
	
		 auto[x,y] = GetMousePositionImpl();	
		 return y;
	 }
	 std::pair<float, float> WindowsInput::GetMousePositionImpl()
	 {
		 auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativateWindow());
		 double xPos, yPos;
		 glfwGetCursorPos(window, &xPos, &yPos);
		 return { xPos,yPos };
	 }
}