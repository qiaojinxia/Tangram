#pragma once

#ifdef TG_PLATFORM_WINDOWS

extern Tangram::Application* Tangram::CreateApplication();

int main(int argc,char** argv) {
	auto app = Tangram::CreateApplication();
	app->Run();
	delete app;
}
#endif // TG_PLATFORM_WINDOWS
