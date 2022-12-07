#include "Renderer/renderer.h"
#include "Objects/Sphere.h"
#include "Objects/Scene.h"
#include <iostream>

int main(int, char**)
{
    Renderer rend;
    rend.Initialize();
    rend.CreateWindow(600, 300);

    Canvas canvas(600, 300, rend);
    Camera camera({ 0, 1, 2 }, { 0, 0, 0 }, { 0, 1, 0 }, 25.0f, 600 / (float)300);
    Scene scene;

    //scene.AddObject(std::make_unique<Sphere>(glm::vec3{ 0, 0, -1 }, 100.0f, std::make_unique<Lambertian>(color3( 0.2f, 0.2f, 0.2f))));
    //scene.AddObject(std::make_unique<Sphere>(glm::vec3{ 0, 100.5f, -1 }, 100.0f, std::make_unique<Lambertian>(color3( 0.2f, 0.2f, 0.2f))));

    scene.AddObject(std::make_unique<Sphere>(glm::vec3{ 0, 0, -1 }, 0.5f, std::make_unique<Lambertian>(color3{ .7f, .5f, .4f })));
    //scene.AddObject(std::make_unique<Sphere>(glm::vec3{ 14.0f, 0, -1 }, 0.5f, std::make_unique<Lambertian>(color3{ .1f, .5f, .4f })));
    scene.AddObject(std::make_unique<Sphere>(glm::vec3{ 0, -100.5f, -1 }, 100.0f, std::make_unique<Lambertian>(color3{ 0.4f, 0.2f, 1 })));

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

        //      --- Dots ---
        //for (int i = 0; i <= 10000; i++)
        //{
        //    //canvas.DrawPoint({ random(0, 400), random(0, 300)}, {random01(), random01(), random01(), 1});

        //}


        rend.Render(canvas, scene, camera);
        canvas.Update();

        rend.CopyCanvas(canvas);
        rend.Present();

    }

    rend.Shutdown();

    return 0;
}