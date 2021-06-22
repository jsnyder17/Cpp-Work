//*______ Joshua Snyder ______*//

#include "Circle.h"

Circle::Circle() {
    start = nullptr;
    count = 0;
}
Circle::~Circle() {

}

void Circle::add(const int& DATA) {
    Node* newNode = new Node(DATA);

    if (start == nullptr) {
        start = newNode;
        newNode->setNext(start);
    }
    else {
        Node* currNode = start;

        while(currNode->getNext() != start) {
            currNode = currNode->getNext();
        }

        currNode->setNext(newNode);
        newNode->setNext(start);
    }

    count += 1;
}
void Circle::remove(const int& DATA) {
    if (count > 0) {
        Node* currNode = start;
        Node* prevNode = nullptr;
        bool found = false;

        while (currNode != nullptr && !found) {  /* find node in the circle */
            if (currNode->getData() == DATA) {
                found = true;
            }
            else {
                prevNode = currNode;
                currNode = currNode->getNext();

                //std::cout << prevNode->getData() << std::endl;
                //std::cout << currNode->getData() << std::endl;
            }
        }
        if (!found) {                                   /* display message if not found */
            std::cout << "Not found. " << std::endl;
        }
        else {
            prevNode->setNext(currNode->getNext());
            delete currNode;

            count -= 1;
        }
    }
    else {
        start = nullptr;
        count -= 1;
    }
}

void Circle::display() const {
    Node* currNode = start;
    int countCheck = 0;

    while (currNode != nullptr && countCheck < count) {
        std::cout << currNode->getData() << std::endl;
        currNode = currNode->getNext();
        countCheck += 1;
    }
}