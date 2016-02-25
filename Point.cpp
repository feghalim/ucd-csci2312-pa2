//
// Created by Mario on 2/25/2016.
//

#include "Point.h"

using namespace Clustering;

Point::Point(int dim) {
    __dim = dim;
    __values = new double[dim];
}

Point::Point(const Point &p) {
    this->__dim = p.__dim;
    this->__values = p.__values;
}

Point& Point::operator=(const Point &p){

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

std::ostream & operator<<(std::ostream &os, const Point& p) {
    for(int i = 0; i < p.getDims(); i++) {
        os << p.getValue(i);
    }
}

std::istream & operator>>(std::istream &is, Point &p) {
    double temp;

    for(int i =0; i < p.getDims(); i++) {
        is >> temp;
        p.setValue(i, temp);
    }
}