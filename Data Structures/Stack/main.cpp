//*______ Joshua Snyder ______*//

#include <iostream>
#include "Stack.h"

int main(void) {
    Stack* stack = new Stack();

    for (int i = 0; i < 10; i++) {
        stack->push(i);
    }

    stack->display();

    for (int i = 0; i < 4; i++) {
        stack->pop();
        stack->display();
    }

    delete stack;

    return 0;
}