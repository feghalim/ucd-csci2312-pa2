#ifndef CLUSTERING_POINT_H
#define CLUSTERING_POINT_H

#include <iostream>
#include <sstream>
#include <algorithm>

namespace Clustering {

    class Point {
        unsigned int __id;
        int __dim;        // number of dimensions of the point
        double *__values; // values of the point's dimensions
        static unsigned int __idGen; // id generator

    public:
        Point(int dim);
        Point(int dim, double * val);

        // Big three: cpy ctor, overloaded operator=, dtor
        Point(const Point &p);
        Point &operator=(const Point &p);
        ~Point();

        // Accessors & mutators
        int getId() const;
        int getDims() const;
        void setValue(int pt, double val);
        double getValue(int pt) const;

        // Functions
        double distanceTo(const Point &p) const;

        // Overloaded operators

        // Members
        Point &operator*=(double d); // p *= 6; p.operator*=(6);
        Point &operator/=(double d);
        const Point operator*(double d) const; // prevent (p1 * 2) = p2;
        const Point operator/(double d) const; // p3 = p2 / 2;

        double &operator[](int index);

        // Friends
        friend Point &operator+=(Point &p1, const Point &p2) {
            int dim;

            if (p1.getDims() > p2.getDims()) {
                dim = p1.getDims();
            }
            else {
                dim = p2.getDims();

                delete [] p1.__values;
                p1.__values = new double[dim];
            }

            for (int i = 0; i < dim; i++) {
                p1.setValue(i, p2.getValue(i));
            }

            return p1;
        }
        friend Point &operator-=(Point &p1, const Point &p2) {
            int dim;

            if (p1.getDims() > p2.getDims()) {
                dim = p1.getDims();
            }
            else {
                dim = p2.getDims();

                delete [] p1.__values;
                p1.__values = new double[dim];
            }

            for (int i = 0; i < dim; i++) {
                p1.setValue(i, p1.getValue(i) - p2.getValue(i));
            }

            return p1;
        }
        friend const Point operator+(const Point &p1, const Point &p2) {

        }
        friend const Point operator-(const Point &p1, const Point &p2) {

        }
        friend bool operator==(const Point &p1, const Point &p2) {
            if(p1.getId() != p2.getId()) {
                return false;
            }
            else {
                for (int i = 0; i < p1.__dim; i++) {
                    if (p1.__values[i] != p2.__values[i]) {
                        return false;
                    }
                }
            }
            return true;
        }
        friend bool operator!=(const Point &p1, const Point &p2) {
            if(p1.getId() == p2.getId()) {
                for(int i = 0; i < p1.getDims();) {
                    if(p1.getValue(i) == p2.getValue(i)) {
                        return false;
                    }
                    else {
                        i++;
                    }
                }
                return true;
            }
            else {
                return true;
            }
        }

        friend bool operator<(const Point &p1, const Point &p2) {
            for (int i = 0; i < p1.getDims();) {
                if(p1.getValue(i) < p2.getValue(i)) {
                    i++;
                }
                else {
                    return false;
                }
            }
            return true;
        }
        friend bool operator>(const Point &p1, const Point &p2) {
            for (int i = 0; i < p1.getDims();) {
                if (p1.getValue(i) > p2.getValue(i)) {
                    i++;
                }
                else {
                    return false;
                }
                return true;
            }
        }
        friend bool operator<=(const Point &p1, const Point &p2) {
            for (int i = 0; i < p1.getDims();) {
                if (p1.getValue(i) <= p2.getValue(i)) {
                    i++;
                }
                else {
                    return false;
                }
                return true;
            }
        }
        friend bool operator>=(const Point &p1, const Point &p2) {
            for (int i = 0; i < p1.getDims();) {
                if (p1.getValue(i) >= p2.getValue(i)) {
                    i++;
                }
                else {
                    return false;
                }
                return true;
            }
        }

        friend std::ostream &operator<<(std::ostream &os, const Point &p) {
            for(int i = 0; i < p.getDims(); i++) {
                os << p.getValue(i) << ", ";
            }
        }
        friend std::istream &operator>>(std::istream &is, Point &p) {
            std::string input;


            std::getline(is, input);
            int size = std::count(input.begin(), input.end(), ',') + 1;

            std::stringstream ss(input);


            if (p.getDims() != size) {
                delete [] p.__values;
                p.__dim = size;
                p.__values = new double[size];
            }

            int i = 0;

            while (!ss.eof()) {
                std::string values;
                getline(ss, values, ',');

                std::stringstream ssIn(values);
                ssIn >> p.__values[i];

                ++i;
            }
            return is;
        }
    };

}
#endif //CLUSTERING_POINT_H
