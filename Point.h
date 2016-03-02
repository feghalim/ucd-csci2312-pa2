#ifndef CLUSTERING_POINT_H
#define CLUSTERING_POINT_H

#include <iostream>

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

        }
        friend Point &operator-=(Point &p1, const Point &p2) {

        }
        friend const Point operator+(const Point &p1, const Point &p2) {

        }
        friend const Point operator-(const Point &p1, const Point &p2) {

        }
        friend bool operator==(const Point &p1, const Point &p2) {
            if(p1.getId() == p2.getId()) {
                for(int i = 0; i < p1.getDims();) {
                    if(p1.getValue(i) == p2.getValue(i)) {
                        i++;
                    }
                    else {
                        return false;
                    }
                }
            }
            else {
                return false;
            }
            return true;
        }
        friend bool operator!=(const Point &p1, const Point &p2) {
            if(p1.getDims() == p2.getDims()) {
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
            double temp;

            for(int i =0; i < p.getDims(); i++) {
                is >> temp;
                p.setValue(i, temp);
            }
        }
    };

}
#endif //CLUSTERING_POINT_H
