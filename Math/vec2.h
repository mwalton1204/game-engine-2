#pragma once

struct Vec2 {

    Vec2();
    Vec2(float, float);

// Binary Arithmetic
    Vec2 operator+(const Vec2&) const;
    Vec2 operator-(const Vec2&) const;
    Vec2 operator*(const float) const;
    Vec2 operator*(const Vec2&) const;
    Vec2 operator/(const float) const;
    Vec2 operator/(const Vec2&) const;

//Unary Arithmetic
    Vec2& operator++();
    Vec2 operator++(int);
    Vec2& operator--();
    Vec2 operator--(int);

//Assignment
    Vec2& operator+=(const Vec2&);
    Vec2& operator-=(const Vec2&);
    Vec2& operator*=(const float);
    Vec2& operator*=(const Vec2&);
    Vec2& operator/=(const float);
    Vec2& operator/=(const Vec2&);
    Vec2& operator=(const Vec2&);

//Relational
    bool operator==(const Vec2&) const;
    bool operator!=(const Vec2&) const;

    float x, y, z;

};