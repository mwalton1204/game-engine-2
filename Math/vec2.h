#pragma once

struct Vec2 {

    Vec2();
    Vec2(float, float);

    Vec2 operator+(const Vec2&) const;
    Vec2 operator-(const Vec2&) const;
    Vec2 operator*(float) const;
    Vec2 operator*(const Vec2&) const;
    Vec2 operator/(float) const;
    Vec2 operator/(const Vec2&) const;

    Vec2& operator+=(const Vec2&);
    Vec2& operator-=(const Vec2&);
    Vec2& operator*=(float);
    Vec2& operator/=(float);

    Vec2& operator++();
    Vec2 operator++(int);
    Vec2& operator--();
    Vec2 operator--(int);

    Vec2& operator=(const Vec2&);

    bool operator==(const Vec2&) const;
    bool operator!=(const Vec2&) const;
    bool operator<(const Vec2&) const;
    bool operator<=(const Vec2&) const;
    bool operator>(const Vec2&) const;
    bool operator>=(const Vec2&) const;

    float x, y, z;

};