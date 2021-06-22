//*______ Joshua Snyder ______*//

#include "Circle.h"

int main(void) {
    Circle* circle = new Circle();

    circle->add(1);
    circle->add(2);
    circle->add(3);

    circle->display();

    circle->remove(2);

    circle->display();

    circle->remove(3);

    circle->display();

    circle->remove(1);

    circle->display();

    return 0;
}