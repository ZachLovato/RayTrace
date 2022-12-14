#include "Sphere.h"

bool Sphere::Hit(const Ray& ray, float min, float max, RaycastHit& hit)
{
    glm::vec3 oc = ray.origin - m_center;
    float a = glm::dot(ray.direction, ray.direction);
    float b = 2 * glm::dot(ray.direction, oc);
    float c = glm::dot(oc, oc) - (m_radius * m_radius);

    // b^2 - 4ac 
    float discriminant = (b * b) - (4 * a * c);

    // 0 - 1 hit
    // 1 - 2 hit

    if (discriminant >= 0)
    {
        float t = (-b - sqrt(discriminant)) / (2 * a);

        if (t > min && t < max)
        {
            hit.distance = t;
            hit.point = ray.GetPoint(t);
            hit.normal = (hit.point - m_center) / m_radius;

            hit.material = std::move(m_material).get();
            
            return true;
        }

        float t2 = (-b + sqrt(discriminant)) / (2 * a);

        if (t2 > min && t2 < max)
        {
            hit.distance = t2;
            hit.point = ray.GetPoint(t2);
            hit.normal = (hit.point - m_center) / m_radius;

            hit.material = std::move(m_material).get();

            return true;
        }
    }

    return false;
}
