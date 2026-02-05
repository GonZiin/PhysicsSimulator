#pragma once
#include <cmath>

struct Vector2 {
    float x, y;

    Vector2(float x = 0.0f, float y = 0.0f) : x(x), y(y) {}

    Vector2 operator+(const Vector2& other) const {
        return Vector2(x + other.x, y + other.y);
    }

    Vector2 operator-(const Vector2& other) const {
        return Vector2(x - other.x, y - other.y);
    }

    Vector2 operator*(float scalar) const {
        return Vector2(x * scalar, y * scalar);
    }

    Vector2 operator/(float scalar) const {
        return Vector2(x / scalar, y / scalar);
    }

    void operator+=(const Vector2& other) {
        x += other.x;
        y += other.y;
    }

    void operator-=(const Vector2& other) {
        x -= other.x;
        y -= other.y;
    }

    void operator*=(float scalar) {
        x *= scalar;
        y *= scalar;
    }

    float LengthSquared() const { return x * x + y * y; }
    
    float Length() const { return std::sqrt(LengthSquared()); }

    float Distance(const Vector2& other) const {
        Vector2 diff = *this - other;
        return diff.Length();
    }

    float Dot(const Vector2& other) const {
        return x * other.x + y * other.y;
    }

    Vector2 Normalize() const {
        float len = Length();
        if (len == 0) return Vector2(0, 0);
        return *this * (1.0f / len);
    }
};