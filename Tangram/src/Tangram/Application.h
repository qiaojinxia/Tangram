#pragma once
#include "Core.h"
namespace Tangram {
	class TANGRAM_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();

	};
	//to be define in client
	Application* CreateApplication();
}
