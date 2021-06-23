//*______ Joshua Snyder ______*//

#include <iostream>
#include "Queue.h"

Queue::Queue() {
    head = nullptr;
    top = nullptr;
    count = 0;
}
Queue::~Queue() {
    Node* tempNode;

    while (head != nullptr) {
        tempNode = head->getNext();

        std::cout << "Deleting " << head->getData() << " ... " << std::endl;

        delete head;
        head = tempNode;
    }

    std::cout << "Queue deleted. " << std::endl;
}

void Queue::add(const int& DATA) {
    Node* newNode = new Node(DATA);

    if (head == nullptr) {
        head = newNode;
    }
    else {
        Node* currNode = head;

        while (currNode->getNext() != nullptr) {
            currNode = currNode->getNext();
        }

        currNode->setNext(newNode);
    }

    count++;

    //std::cout << "Added " << DATA << " to queue. " << std::endl;
}

int Queue::pop() {
    int data = head->getData();

    head = head->getNext();

    count--;

    return data;
}

void Queue::display() const {
    Node* currNode = head;

    std::cout << "------ QUEUE ------" << std::endl;
    
    while (currNode != nullptr) {
        std::cout << currNode->getData() << " ";
        currNode = currNode->getNext();
    }
    std::cout << std::endl;
    std::cout << "-------------------" << std::endl;
    std::cout << "(" << count << ") items. " << std::endl;
}