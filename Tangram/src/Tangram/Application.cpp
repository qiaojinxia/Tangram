#include "tgpch.h"
#include "Application.h"
#include "Events/ApplicationEvent.h"

#include "Tangram/Log.h"
namespace Tangram {
	Application::Application()
	{
	
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowsResizeEvent e(1280, 720);
		TG_TRACE(e);
		while (true);
	}

	
}