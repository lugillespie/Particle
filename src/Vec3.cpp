#include "Vec3.h"

Vec3::Vec3(float x, float y, float z) : cx(x), cy(y), cz(z) {

}

Vec3::Vec3() : cx(0), cy(0), cz(0) {

}

// Vec3 Vec3::multiply(float scalar) {
//     return Vec3(cx * scalar, cy * scalar, cz * scalar);
// }

// Vec3 Vec3::add(Vec3 vector) {
//     return Vec3(cx + vector.cx, cy + vector.cy, cz + vector.cz);
// }

Vec3 Vec3::operator+(const Vec3 &other) {
    return Vec3(cx + other.cx, cy + other.cy, cz + other.cz);
}

Vec3 Vec3::operator*(const float &other) {
    return Vec3(cx * other, cy * other, cz * other);
}