//*______ Joshua Snyder ______*//

#ifndef QUEUE_H
#define QUEUE_H

#include "Node.h"

class Queue {
    public:
        Queue();
        virtual ~Queue();

        void add(const int& DATA);
        int pop();
        void display() const;

    private:
        Node* head;
        Node* top;
        int count;
};

#endif