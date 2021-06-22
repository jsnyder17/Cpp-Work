//*______ Joshua Snyder ______*//

#include "Circle.h"

int main(void) {
    int i, j;

    Circle* circle = new Circle();

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 10; j++) {
            circle->add(j);
        }

        circle->display();

        std::cout << "BEFORE: " << sizeof(circle) << std::endl;

        for(j = 0; j < 10; j++) {
            circle->remove(j);
            circle->display();
        }

        circle->display();

        std::cout << "AFTER: " << sizeof(circle) << std::endl;
    }

    return 0;
}