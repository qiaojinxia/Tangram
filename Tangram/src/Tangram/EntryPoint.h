#pragma once


#ifdef TG_PLATFORM_WINDOWS

extern Tangram::Application* Tangram::CreateApplication();

int main(int argc,char** argv) {
	Tangram::Log::Init();
	TG_CORE_WARN("Initialized Log!");
	TG_INFO("Hello {0}!",5);
	auto app = Tangram::CreateApplication();
	app->Run();
	delete app;
}
#endif // TG_PLATFORM_WINDOWS
