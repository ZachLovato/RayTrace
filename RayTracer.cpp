#include "Renderer/renderer.h"
#include "Renderer/Camera.h"
#include "Objects/Sphere.h"
#include "Objects/Scene.h"
#include "Objects/Plane.h"
#include <iostream>

int main(int, char**)
{
    const int width = 600;
    const int height = 300;
    const int samples = 10;

    Renderer rend;
    rend.Initialize();
    rend.CreateWindow(width, height);

    Canvas canvas(width, height, rend);
    Camera camera({ 0, 1, 2 }, { 0, 0, 0 }, { 0, 1, 0 }, 85.0f, width / (float)height);
    Scene scene;

    scene.AddObject(std::make_unique<Sphere>(glm::vec3{ 0, 0, -1 }, 0.5f, std::make_unique<Lambertian>(color3{ .4f, .4f, .9f })));
    scene.AddObject(std::make_unique<Sphere>(glm::vec3{ -1.3, 0, -1 }, 0.8f, std::make_unique<Metal>(color3{ 1, 1, 1 }, 0.3f)));
    scene.AddObject(std::make_unique<Sphere>(glm::vec3{ 0, -100.5f, -1 }, 100.0f, std::make_unique<Lambertian>(color3{ .1f, .7f, .2f })));
    scene.AddObject(std::make_unique<Plane>(glm::vec3{ 0, 0, -8 }, glm::vec3{ 0, 1, 0 }, std::make_unique<Lambertian>(color3{ 0.2f, 0.2f, 0.2f })));

    bool quit = false;
    while (!quit)
    {
        SDL_Event event;
        SDL_PollEvent(&event);
        switch (event.type)
        {
        case SDL_QUIT:
            quit = true;
            break;
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {
            case SDLK_ESCAPE:
                quit = true;
                break;
            }
            break;
        }

        //      -- renderer Scene --
        canvas.Clear({ 0, 0, 0, 1 });

        rend.Render(canvas, scene, camera, samples);
        canvas.Update();

        rend.CopyCanvas(canvas);
        rend.Present();

    }

    rend.Shutdown();

    return 0;
}