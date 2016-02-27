//
// Created by Mario on 2/25/2016.
//

#include <wincon.h>
#include "Cluster.h"

using namespace Clustering;

Cluster::Cluster() {
    __size = 0;
    __points = NULL;
}

Cluster::Cluster(const Cluster &c) {
    this->__points = c.__points;
    this->__size = c.__size;
}

Cluster& Cluster::operator=(const Cluster &c) {
    this->__points = c.__points;
    this->__size = c.__size;
}

Cluster::~Cluster() {
    LNodePtr cursor;
    while(__points != NULL) {
        cursor = __points;
        __points = cursor->next;
        delete cursor;
    }
}

int Cluster::getSize() const {
    return __size;
}

void Cluster::add(const Point &p) {
    if(__size == 0) {
        ++__size;
        __points = new LNode(p, NULL);
    }
    else {
        if (contains(p)) {
            return;
        }
        else {
            LNodePtr _new = NULL;
            LNodePtr  next = __points;
            while (next != NULL) {
                if (p < next->point) {
                    if (_new == NULL) {
                        __points = new LNode(p, next);
                        ++__size;

                        return;
                    }
                    else {
                        _new->next = new LNode(p, next);
                        ++__size;

                        return;
                    }
                }

                _new = next;
                next = next->next;

            }
            return;
        }
    }
}

const Point& Cluster::remove(const Point &p) {
    LNodePtr cursor = __points;

    while(cursor != __points) {

    }

    return p;
}

bool Cluster::contains(const Point &p) {
    LNodePtr cursor = __points;
    while(cursor != NULL) {
        if(cursor->point.getId() == p.getId()) {
            return true;
        }
        else {
            cursor = cursor->next;
        }
    }
    return false;
}

const Point& Cluster::operator[](unsigned int index) const {
    LNodePtr cursor = __points;

    for(int i = 0; i < index; i++) {
        cursor = cursor->next;
    }

    return cursor->point;
}