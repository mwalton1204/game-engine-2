#pragma once

class Vec2 {

    public:
        float x, y, z;

        Vec2();
        Vec2(float, float);

// Binary Arithmetic
        Vec2 operator+(const Vec2&) const;
        Vec2 operator-(const Vec2&) const;
        Vec2 operator*(const float) const; //scalar
        Vec2 operator*(const Vec2&) const; //element-wise
        Vec2 operator/(const float) const; //scalar
        Vec2 operator/(const Vec2&) const; //element-wise

//Unary Arithmetic
        Vec2& operator++();
        Vec2 operator++(int);
        Vec2& operator--();
        Vec2 operator--(int);

//Assignment
        Vec2& operator+=(const Vec2&);
        Vec2& operator-=(const Vec2&);
        Vec2& operator*=(const float); //scalar
        Vec2& operator*=(const Vec2&); //element-wise
        Vec2& operator/=(const float); //scalar
        Vec2& operator/=(const Vec2&); //element-wise
        Vec2& operator=(const Vec2&);

//Relational
        bool operator==(const Vec2&) const;
        bool operator!=(const Vec2&) const;

//Utility Methods

        //magnitude
        float magnitude () const;
        //normalize
        void normalize();
        //dot
        float dot(const Vec2&) const;
        //angle
        float angle(const Vec2&) const;
};