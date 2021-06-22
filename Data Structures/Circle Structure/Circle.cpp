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
        bool found = false;

        while (currNode->getNext() != nullptr && !found) {
            if (currNode->getNext()->getData() == DATA) {
                found = true;
            }
            else {
                currNode = currNode->getNext();
            }
        }
        if (!found) {
            std::cout << "Not found. " << std::endl;
        }
        else {
            std::cout << "Deleting " << currNode->getNext()->getData() << " ... " << std::endl;
            
            if (count == 1) {
                std::cout << "Count is 1" << std::endl;
                start = nullptr;
            }
            else {
                if (currNode->getNext() == start) {
                    currNode->setNext(start->getNext());
                    delete start;
                    start = currNode;
                }
                else {
                    Node* temp = new Node(currNode->getNext()->getNext());
                    delete currNode->getNext();
                    currNode->setNext(temp);
                    std::cout << "Set next to: " << currNode->getNext()->getData() << std::endl;
                }
            }

            count -= 1;
        }
    }
    else {
        std::cout << "No items in the list. " << std::endl;
    }
}

void Circle::display() const {
    Node* currNode = start;
    int countCheck = 0;

    std::cout << "----- LIST -----" << std::endl;

    while (currNode != nullptr && countCheck < count) {
        std::cout << currNode->getData() << std::endl;
        currNode = currNode->getNext();
        countCheck += 1;
    }

    std::cout << "----------------" << std::endl << std::endl;
}