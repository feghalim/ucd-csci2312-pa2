#ifndef CLUSTERING_CLUSTER_H
#define CLUSTERING_CLUSTER_H

#include "Point.h"
#include <sstream>
#include <string>

namespace Clustering {

    typedef struct LNode *LNodePtr;

    struct LNode {

        Point point;
        LNodePtr next;
        LNode(const Point &p, LNodePtr n);

    };

    class Cluster {

        int __size;
        LNodePtr __points;

        void __del();
        void __cpy(LNodePtr pts);
        bool __in(const Point &p) const;


    public:
        Cluster();

        // The big three: cpy ctor, overloaded operator=, dtor
        Cluster(const Cluster &c);
        Cluster &operator=(const Cluster &c);
        ~Cluster();

        // Getters/setters
        int getSize() const; // TODO add to the requirements

        // Set functions: They allow calling c1.add(c2.remove(p));
        void add(const Point &p); // TODO add asc order to the requirements
        const Point &remove(const Point &p);
        bool contains(const Point &p);

        // Overloaded operators

        // Members: Subscript
        const Point &operator[](unsigned int index) const; // notice: const

        // Members: Compound assignment (Point argument)
        Cluster &operator+=(const Point &p) {
            add(p);

            return *this;
        }
        Cluster &operator-=(const Point &p) {
            remove(p);

            return *this;
        }

        // Members: Compound assignment (Cluster argument)
        Cluster &operator+=(const Cluster &c) {
            for(int i = 0; i < c.getSize(); i++) {
                add(c[i]);
            }

            return  *this;
        } // union
        Cluster &operator-=(const Cluster &c) {
            for(int i = 0; i < c.getSize(); i++) {
                remove(c[i]);
            }

            return *this;
        } // (asymmetric) difference

        // Friends: IO
        friend std::ostream &operator<<(std::ostream &os, const Cluster &c) {
            for(int i = 0; i < c.getSize(); i++) {
                os << c[i] << ", ";
            }
            return os;
        }
        friend std::istream &operator>>(std::istream &is, Cluster &c) {
            std::string input;
            for(int i = 0; is.good(); i++) {
                getline(is, input);
                int size = std::count(input.begin(), input.end(), ',') + 1;

                std::stringstream ss(input);
                Point p(size);

                ss >> p;

                c.add(p);
            }
            return is;
        }

        // Friends: Comparison
        friend bool operator==(const Cluster &c1, const Cluster &c2) {
            if (c1.getSize() != c2 .getSize()) {
                return false;
            }
            else {
                for(int i = 0; i < c1.getSize(); i++) {
                    if (c1[i] != c2[i]) {
                        return false;
                    }
                }
            }

            return true;
        }
        friend bool operator!=(const Cluster &c1, const Cluster &c2) {
            if(c1 == c2) {
                return true;
            }
            else {
                return false;
            }
        }

        // Friends: Arithmetic (Cluster and Point)
        friend const Cluster operator+(const Cluster &c1, const Point &c2) {
            Cluster temp(c1);

            temp += c2;
            
            return temp;
        }
        friend const Cluster operator-(const Cluster &c1, const Point &c2) {
            Cluster temp(c1);

            temp -= c2;

            return temp;
        }

        // Friends: Arithmetic (two Clusters)
        friend const Cluster operator+(const Cluster &c1, const Cluster &c2) {
            Cluster temp(c1);

            temp += c2;
            
            return temp;
        } // union
        friend const Cluster operator-(const Cluster &c1, const Cluster &c2) {
            Cluster temp(c1);

            temp -= c2;

            return temp;
        } // (asymmetric) difference

    };

}
#endif //CLUSTERING_CLUSTER_H
