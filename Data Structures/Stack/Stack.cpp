//*______ Joshua Snyder ______*//

#include "Stack.h"
#include <iostream>

Stack::Stack() {
    head = nullptr;
    count = 0;
}
Stack::~Stack() {
    Node* tempNode;

    while (head != nullptr) {
        std::cout << "Deleting " << head->getData() << " ... " << std::endl;

        tempNode = head->getNext();
        delete head;
        head = tempNode;
    }

    std::cout << "Stack deleted " << std::endl;
}

void Stack::push(const int& DATA) {
    Node* newNode = new Node(DATA);

    if (head == nullptr) {
        head = newNode;
    }
    else {
        newNode->setNext(head);
        head = newNode;
    }    

    count++;
}
void Stack::pop() {
    head = head->getNext();
    count--;
}

void Stack::display() const {
    Node* currNode = head;

    std::cout << "------ STACK ------" << std::endl;

    while (currNode != nullptr) {
        std::cout << currNode->getData() << " ";

        currNode = currNode->getNext();
    }

    std::cout << std::endl;
    std::cout << "-------------------" << std::endl;
    std::cout << "(" << count << ") items. " << std::endl;
}