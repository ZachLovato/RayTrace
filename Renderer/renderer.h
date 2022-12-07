#pragma once

#include "../Math//Ray.h"
#include "Canvas.h"
#include "../Objects/Object.h"
#include <SDL.h>

class Object;
class Scene;

class Renderer
{
public:
	Renderer() = default;

	bool Initialize(); 
	void Shutdown(); 
	bool CreateWindow(int width, int height);


	void Render(Canvas& canvas, Scene& scene);
	void CopyCanvas(const Canvas& canvas);
	void Present();

	friend class Canvas;

private:
	color3 GetBackgroundFromRay(const Ray& ray);

	SDL_Window* m_window{ nullptr }; 
	SDL_Renderer* m_renderer{ nullptr };
};