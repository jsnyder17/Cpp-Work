//*_______ Joshua Snyder ______*//

#ifndef NODE_H
#define NODE_H

class Node {
    public:
        Node();
        Node(const int& DATA);
        Node(Node* node);
        virtual ~Node();

        Node* getNext() const;
        int getData() const;

        void setNext(Node* next);
        void setData(const int& DATA);
    private:
        Node* next;
        int data;
};

#endif