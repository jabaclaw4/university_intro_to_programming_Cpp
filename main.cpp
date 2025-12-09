#include <iostream>
#include "include/point.h"
#include "include/vector.h"

int main() {
    int choice;
    std::cout << "1. Inheritance (Point classes)" << std::endl;
    std::cout << "2. Aggregation (Vector collections)" << std::endl;
    std::cout << "choose demonstration: ";
    std::cin >> choice;
    switch (choice) {
        case 1:
            std::cout << "\n=== INHERITANCE DEMONSTRATION ===" << std::endl;
            Point3D p3d(3.0, 4.0, 5.0);
            Point2D p2d(6.0, 8.0);
            std::cout << "\nPoint3D object:" << std::endl;
            std::cout << "Coordinates: (" << p3d.getX() << ", " << p3d.getY() << ", " << p3d.getZ() << ")" << std::endl;
            std::cout << "Distance from origin: " << p3d.distanceFromOrigin() << std::endl;
            std::cout << "\nPoint2D object (inherits from Point3D):" << std::endl;
            std::cout << "Coordinates: (" << p2d.getX() << ", " << p2d.getY() << ")" << std::endl;
            std::cout << "z-coordinate is hidden in Point2D!" << std::endl;
            std::cout << "Distance from origin (2D only): " << p2d.distanceFromOrigin() << std::endl;
            std::cout << "\n--- Testing setters ---" << std::endl;
            std::cout << "Before changes: x=" << p2d.getX() << ", y=" << p2d.getY() << std::endl;
            p2d.setX(10.0);
            p2d.setY(12.0);
            std::cout << "After changes: x=" << p2d.getX() << ", y=" << p2d.getY() << std::endl;
            std::cout << "setZ() is not available in Point2D!" << std::endl;
        case 2:
            std::cout << "\n=== AGGREGATION DEMONSTRATION ===" << std::endl;

            // Create vector collection
            VectorCollection collection;

            // Add vectors to collection
            collection.addVector(Vector(3.0, 4.0, 0.0));
            collection.addVector(Vector(1.0, 1.0, 1.0));
            collection.addVector(Vector(5.0, 0.0, 0.0));

            std::cout << "\nCollection contains " << collection.size() << " vectors:" << std::endl;
            collection.printAll();

            std::cout << "\n--- Sorting vectors by distance from origin ---" << std::endl;
            collection.sortByDistance();
            collection.printAll();

            std::cout << "\n--- Adding sum of all vectors to collection ---" << std::endl;
            collection.addSumOfAllVectors();

            std::cout << "\n--- Computing total vector ---" << std::endl;
            Vector total = collection.computeTotalVector();
            std::cout << "Total vector: ";
            total.print();
            std::cout << " (length = " << total.length() << ")" << std::endl;

            break;

        default:
            std::cout << "invalid choice!" << std::endl;
    }
    return 0;
}