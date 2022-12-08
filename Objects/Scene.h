#pragma once

#include "../Math/Color.h"
#include <vector>
#include <memory>

class Object;
struct Ray;
struct RaycastHit;

class Scene
{
public:
    Scene() = default;
    Scene(const color3& topcolor, const color3& bottemColor) :
        m_topcolor{ topcolor },
        m_btmcolor{ bottemColor }
    {}

    color3 Trace(const Ray& ray, float min, float max, RaycastHit& hit, int depth);
    void AddObject(std::unique_ptr<Object> object);

private:
    color3 m_topcolor{ 0.7f, 0.36f, 0.7f };
    color3 m_btmcolor{ 1, 1, 1 };
    std::vector <std::unique_ptr<Object>> m_objects;

};