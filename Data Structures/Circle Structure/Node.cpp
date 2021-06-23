//*______ Joshua Snyder ______*//

#include "Node.h"

Node::Node() {
    next = nullptr;
    data = 0;
}
Node::Node(const int& DATA) {
    next = nullptr;
    this->data = DATA;
}
Node::Node(Node* node) {
    this->next = node->next;
    this->data = node->data;
}
Node::~Node() {

}

Node* Node::getNext() const {
    return next;
}
int Node::getData() const {
    return data;
}

void Node::setNext(Node* next) {
    this->next = next;
}
void Node::setData(const int& DATA) {
    this->data = data;
}