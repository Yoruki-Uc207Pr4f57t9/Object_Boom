#pragma once
#include <cmath>

namespace Core {

    class Vector2 {
    public:
        float x{ 0.0f };
        float y{ 0.0f };

        Vector2() = default;
        Vector2(float _x, float _y) : x(_x), y(_y) {}

        Vector2 operator+(const Vector2& o) const { return { x + o.x, y + o.y }; }
        Vector2 operator-(const Vector2& o) const { return { x - o.x, y - o.y }; }
        Vector2& operator+=(const Vector2& o) { x += o.x; y += o.y; return *this; }
        Vector2& operator-=(const Vector2& o) { x -= o.x; y -= o.y; return *this; }
    };

} // namespace Core
