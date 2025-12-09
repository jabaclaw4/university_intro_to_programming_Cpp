#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <cmath>

class Vector {
private:
    double x, y, z;

public:
    Vector();
    Vector(double x, double y, double z);

    double getX() const;
    double getY() const;
    double getZ() const;

    void setX(double newX);
    void setY(double newY);
    void setZ(double newZ);

    double length() const;
    Vector operator+(const Vector& other) const;

    void print() const;
};

class VectorCollection {
private:
    Vector* vectors;        // Массив объектов Vector (агрегирование)
    int capacity;           // Вместимость массива
    int size;               // Текущее количество векторов

public:
    VectorCollection();
    ~VectorCollection();
    void addVector(const Vector& vec);        // Добавление нового вектора в коллекцию
    void sortByDistance();                    // Сортировка векторов по расстоянию от начала координат
    void addSumOfAllVectors();                // Сложение векторов с добавлением результата в набор
    Vector computeTotalVector() const;        // Вычисление суммарного вектора коллекции
};

#endif