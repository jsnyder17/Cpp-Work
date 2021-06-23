//*______ Joshua Snyder ______*//

#include <iostream>
#include "Queue.h"

int main(void) {
    Queue* queue = new Queue();

    for (int i = 0; i < 10; i++) {  /* add elements to queue */
        queue->add(i);
        queue->display();
    }

    std::cout << "All items added. " << std::endl;

    for (int i = 0; i < 10; i++) {  /* pop elements from queue */
        std::cout << "Popped " << queue->pop() << std::endl;
        queue->display();
    }

    std::cout << "All items popped. " << std::endl;

    delete queue;

    return 0;
}