#include "../include/point.h"
#include <cmath>

Point3D::Point3D() : x(0), y(0), z(0) {
}

Point3D::Point3D(double x, double y, double z)
        : x(x), y(y), z(z) {
}

double Point3D::getX() const {
    return x;
}

double Point3D::getY() const {
    return y;
}

double Point3D::getZ() const {
    return z;
}

void Point3D::setX(double newX) {
    x = newX;
}

void Point3D::setY(double newY) {
    y = newY;
}

void Point3D::setZ(double newZ) {
    z = newZ;
}

//расстояние от начала координат для Point3D
double Point3D::distanceFromOrigin() const {
    return sqrt(x * x + y * y + z * z);
}

Point2D::Point2D() : Point3D() {
}

Point2D::Point2D(double x, double y)
        : Point3D(x, y, 0) {//z всегда устанавливаем в 0
}

//расстояние от начала координат для Point2D (только по x и y)
double Point2D::distanceFromOrigin() const {
    return sqrt(x * x + y * y);
}