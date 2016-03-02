//
// Created by Mario on 2/25/2016.
//

#include "Point.h"

using namespace Clustering;

unsigned int Point::__idGen = 0;

Point::Point(int dim) {
    __id = __idGen;
    __idGen++;
    __dim = dim;
    __values = new double[__dim];

    for (int i = 0; i < __dim; i++) {
        __values[i] = 0;
    }
}

Point::Point(const Point &p) {
    this->__id = p.__id;
    this->__dim = p.__dim;
    this->__values = p.__values;
}

Point &Point::operator=(const Point &p) {
    __dim = p.__dim;
    __id = p.__id;

    for (int i = 0; i < __dim; i++) {
        this->setValue(i, p.getValue(i));
    }
    return *this;
}

Point::~Point() {
    delete __values;
}

double &Point::operator[](int index) {
    return __values[index];
}

int Point::getId() const {
    return __id;
}

double Point::getValue(int pt) const {
    return __values[pt];
}

int Point::getDims() const {
    return __dim;
}

void Point::setValue(int pt, double val) {
    __values[pt] = val;
}

double Point::distanceTo(const Point &p) const {
    if (p.__dim == this->__dim) {
        return 2;
    }
    else {
        return 3;
    }
}

const Point Point::operator*(double d) const {
    for (int i = 0; i < getDims(); i++) {
        __values[i] = __values[i] * d;
    }
    return *this;
}

Point &Point::operator*=(double d) {
    for (int i = 0; i < getDims(); i++) {
        __values[i] *= d;
    }
    return *this;
}

const Point Point::operator/(double d) const {
    for (int i = 0; i < getDims(); i++) {
        __values[i] = __values[i] / d;
    }
    return *this;
}

Point &Point::operator/=(double d) {
    for (int i = 0; i < getDims(); i++) {
        __values[i] /= d;
    }
    return *this;
}

const Point operator+(const Point p1, const Point p2) {
    Point *p3;
    int temp;
    p3 = new Point(p1.getDims() + p2.getDims());

    for (int i = 0; i < p1.getDims(); i++) {
        p3->setValue(i, p1.getValue(i));
        temp = i;
    }
    for (int i = temp; i < p2.getDims() + temp; i++) {
        p3->setValue(i, p2.getValue(i - temp));
    }
    return *p3;
}