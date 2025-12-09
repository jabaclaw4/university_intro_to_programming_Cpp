#ifndef POINT_H
#define POINT_H

class Point3D {
protected:
    double x, y, z;
public:
    Point3D();
    Point3D(double x, double y, double z);
    double getX() const;
    double getY() const;
    double getZ() const;
    void setX(double newX);
    void setY(double newY);
    void setZ(double newZ);
    double distanceFromOrigin() const;
};

class Point2D : private Point3D {
public:
    Point2D();
    Point2D(double x, double y);
    using Point3D::getX;
    using Point3D::getY;
    using Point3D::setX;
    using Point3D::setY;
    double distanceFromOrigin() const;
};
#endif