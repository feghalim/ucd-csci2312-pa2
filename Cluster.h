#ifndef CLUSTERING_CLUSTER_H
#define CLUSTERING_CLUSTER_H

#include "Point.h"

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

        }
        Cluster &operator-=(const Point &p) {

        }

        // Members: Compound assignment (Cluster argument)
        Cluster &operator+=(const Cluster &c) {

        } // union
        Cluster &operator-=(const Cluster &c) {

        } // (asymmetric) difference

        // Friends: IO
        friend std::ostream &operator<<(std::ostream &os, const Cluster &c) {

        }
        friend std::istream &operator>>(std::istream &is, Cluster &c) {

        }

        // Friends: Comparison
        friend bool operator==(const Cluster &c1, const Cluster &c2) {

        }
        friend bool operator!=(const Cluster &c1, const Cluster &c2) {

        }

        // Friends: Arithmetic (Cluster and Point)
        friend const Cluster operator+(const Cluster &c1, const Point &c2) {

        }
        friend const Cluster operator-(const Cluster &c1, const Point &c2) {

        }

        // Friends: Arithmetic (two Clusters)
        friend const Cluster operator+(const Cluster &c1, const Cluster &c2) {

        } // union
        friend const Cluster operator-(const Cluster &c1, const Cluster &c2) {

        } // (asymmetric) difference

    };

}
#endif //CLUSTERING_CLUSTER_H
