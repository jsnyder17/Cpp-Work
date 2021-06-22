//*______ Joshua Snyder ______*//


#ifndef CIRCLE_H
#define CIRLCE_H

#include <iostream>
#include "Node.h"

class Circle {
    public:
        Circle();
        virtual ~Circle();

        void add(const int& data);
        void remove(const int& data);
        void display() const;

    private:
        Node* start;
        Node* end;
        int count;
};  

#endif