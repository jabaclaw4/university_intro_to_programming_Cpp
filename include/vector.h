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
    Vector* vectors;
    int capacity; //cколько может
    int size; //количество уже векторов
public:
    VectorCollection();
    void addVector(const Vector& vec);        //добавление нового вектора в коллекцию
    void sortByDistance();                    //сортировка векторов по расстоянию от начала координат
    void addSumOfAllVectors();                //сложение векторов с добавлением результата в набор
    Vector computeTotalVector() const;        //вычисление суммарного вектора коллекции
    void printAll() const;
};
#endif