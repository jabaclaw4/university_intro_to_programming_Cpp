#include <iostream>
#include "include/point.h"
#include "include/vector.h"

int main() {
    int choice;
    std::cout << "1. inheritance (point classes)" << std::endl;
    std::cout << "2. aggregation (vector collections)" << std::endl;
    std::cout << "choose demonstration: ";
    std::cin >> choice;
    Point3D p3d(3.0, 4.0, 5.0);
    Point2D p2d(6.0, 8.0);
    VectorCollection collection;
    switch (choice) {
        case 1:
            std::cout << "\n=== INHERITANCE DEMONSTRATION ===" << std::endl;
            std::cout << "\npoint3D object:" << std::endl;
            std::cout << "coordinates: (" << p3d.getX() << ", " << p3d.getY() << ", " << p3d.getZ() << ")" << std::endl;
            std::cout << "distance from origin: " << p3d.distanceFromOrigin() << std::endl;
            std::cout << "\npoint2D object (inherits from point3D):" << std::endl;
            std::cout << "coordinates: (" << p2d.getX() << ", " << p2d.getY() << ")" << std::endl;
            std::cout << "Distance from origin (2D only): " << p2d.distanceFromOrigin() << std::endl;
            std::cout << "\n--- testing setters ---" << std::endl;
            std::cout << "before changes: x=" << p2d.getX() << ", y=" << p2d.getY() << std::endl;
            p2d.setX(10.0);
            p2d.setY(12.0);
            std::cout << "after changes: x=" << p2d.getX() << ", y=" << p2d.getY() << std::endl;
        case 2:
            std::cout << "\n=== AGGREGATION DEMONSTRATION ===" << std::endl;
            collection.addVector(Vector(3.0, 4.0, 0.0));
            collection.addVector(Vector(1.0, 1.0, 1.0));
            collection.addVector(Vector(5.0, 0.0, 0.0));
            std::cout << "\n--- sorting vectors by distance from origin ---" << std::endl;
            collection.sortByDistance();
            collection.printAll();
            std::cout << "\n--- adding sum of all vectors to collection ---" << std::endl;
            collection.addSumOfAllVectors();
            collection.printAll();
            std::cout << "\n--- computing total vector ---" << std::endl;
            Vector total = collection.computeTotalVector();
            std::cout << "total vector: ";
            total.print();
            std::cout << " (length = " << total.length() << ")" << std::endl;
    }
    return 0;
}