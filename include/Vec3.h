#pragma once
#include <iostream>

class Vec3 {
    public :
        float cx;
        float cy;
        float cz;

        Vec3(float x, float y, float z);
        Vec3();

        // Vec3 multiply(float scalar);
        // Vec3 add(Vec3 vector);

        Vec3 operator+(const Vec3& other);
        Vec3 operator*(const float& other);
};