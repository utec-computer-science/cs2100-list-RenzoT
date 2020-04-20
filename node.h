//
// Created by Renzo on 20/04/2020.
//

#ifndef CS2100_LIST_RENZOT_NODE_H
#define CS2100_LIST_RENZOT_NODE_H
// Node.h
template <typename T>
class Node {
protected:
    T value;
    Node<T> * next;
    Node<T> * prev;

public:
    Node(T value){this->value=value; this->next= nullptr; this->prev= nullptr;}

    void deleteNode(){
        if (next != nullptr)
            next->deleteNode();
        delete this;
    }
};

#endif //CS2100_LIST_RENZOT_NODE_H
