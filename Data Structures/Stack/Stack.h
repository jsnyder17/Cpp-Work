//*______ Joshua Snyder ______*//

#ifndef STACK_H
#define STACK_H

#include "Node.h"

class Stack {
    public:
        Stack();
        virtual ~Stack();

        void push(const int& DATA);
        void pop();
        void display() const;
        
    private:
        Node* head;
        Node* top;
        int count;
};

#endif