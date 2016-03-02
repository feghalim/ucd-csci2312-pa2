//
// Created by Mario on 2/25/2016.
//

#include "Point.h"

using namespace Clustering;

Point::Point(int dim) {
//    __id = __idGen;
//    __idGen++;
    __dim = dim;
    __values = new double[dim];
}

Point::Point(const Point &p) {
    this->__id = p.__id;
    this->__dim = p.__dim;
    this->__values = p.__values;
}

Point& Point::operator=(const Point &p){
    for(int i = 0; i < p.getDims(); i++) {
        this->setValue(i, p.getValue(i));
    }
}

Point::~Point() {
    delete __values;
}

double& Point::operator[](int index) {
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
    if(p.__dim == this->__dim) {
        return 2;
    }
    else {
        return 3;
    }
}

const Point Point::operator*(double d) const {
    for(int i = 0; i < getDims(); i++) {
        __values[i] = __values[i] * d;
    }
}

Point& Point::operator*=(double d) {
    for(int i = 0; i < getDims(); i++) {
        __values[i] *= d;
    }
}

const Point Point::operator/(double d) const {
    for(int i = 0; i < getDims(); i++) {
        __values[i] = __values[i] / d;
    }
}

Point& Point::operator/=(double d) {
    for(int i = 0; i < getDims(); i++) {
        __values[i] /= d;
    }
}

const Point operator+(const Point p1, const Point p2) {
    Point* p3;
    int temp;
    p3 = new Point(p1.getDims() + p2.getDims());

    for(int i = 0; i < p1.getDims(); i++) {
        p3->setValue(i, p1.getValue(i));
        temp = i;
    }
    for(int i = temp; i < p2.getDims() + temp; i ++) {
        p3->setValue(i, p2.getValue(i - temp));
    }
    return *p3;
}