#include <Tangram.h>

class Sandbox :public Tangram::Application {
public:
	Sandbox() {

	}
	~Sandbox() {

	}
};

Tangram::Application* Tangram::CreateApplication() {
	return new Sandbox();
}
