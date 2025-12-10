#include "../include/vector.h"

Vector::Vector() : x(0), y(0), z(0) {}

Vector::Vector(double x, double y, double z) : x(x), y(y), z(z) {}

double Vector::getX() const { return x; }
double Vector::getY() const { return y; }
double Vector::getZ() const { return z; }

void Vector::setX(double newX) { x = newX; }
void Vector::setY(double newY) { y = newY; }
void Vector::setZ(double newZ) { z = newZ; }

double Vector::length() const {
    return sqrt(x * x + y * y + z * z);
}
Vector Vector::operator+(const Vector& other) const {
    return Vector(x + other.x, y + other.y, z + other.z);
}
void Vector::print() const {
    std::cout << "[" << x << ", " << y << ", " << z << "]";
}

VectorCollection::VectorCollection() : vectors(nullptr), capacity(0), size(0) {}

//добавление нового вектора в коллекцию
void VectorCollection::addVector(const Vector& vec) {
    if (size >= capacity) {
        //увеличиваем массив если нет мест. если коллкция пустая то делаем 2 места
        int newCapacity = (capacity == 0) ? 2 : capacity * 2;
        Vector* newVectors = new Vector[newCapacity];//выделяем память под новый массив
        for (int i = 0; i < size; i++) {
            newVectors[i] = vectors[i];
        }
        delete[] vectors;
        vectors = newVectors;
        capacity = newCapacity;
    }
    vectors[size] = vec;
    size++;
}

//cортировка векторов по расстоянию от начала координат
void VectorCollection::sortByDistance() {
    //пузырь
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (vectors[j].length() > vectors[j + 1].length()) {
                Vector temp = vectors[j];
                vectors[j] = vectors[j + 1];
                vectors[j + 1] = temp;
            }
        }
    }
}

//сложение векторов с добавлением результата в набор
void VectorCollection::addSumOfAllVectors() {
    Vector sum;
    for (int i = 0; i < size; i++) {
        sum = sum + vectors[i];
    }
    addVector(sum);
}

Vector VectorCollection::computeTotalVector() const {//суммарный вектор
    Vector total;
    for (int i = 0; i < size; i++) {
        total = total + vectors[i];
    }
    return total;
}

void VectorCollection::printAll() const {
    for (int i = 0; i < size; i++) {
        std::cout << i + 1 << ". ";
        vectors[i].print();
        std::cout << " (length = " << vectors[i].length() << ")" << std::endl;
    }
}