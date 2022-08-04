#pragma once
namespace Tangram {
	class GraphicsContext 
	{
	public:
		virtual void Init() = 0;
		virtual void SwapBuffers() = 0;
	};
}