//
// Created by Renzo on 20/04/2020.
//

#ifndef CS2100_LIST_RENZOT_NODE_H
#define CS2100_LIST_RENZOT_NODE_H

using namespace std;
// Node.h
template <typename T>
class Node {
public:
    T value;
    Node<T> * next;
    Node<T> * prev;

public:
    Node(T value): value(value), next(nullptr), prev(nullptr){};
    void deleteNode(){
        if (next != nullptr)
            next->deleteNode();
        delete this;
    }
};

/*
template <typename T>
class ForwardListNode : public Node<T> {
public:
    typedef typename Node<T>::value_t value_t;

public:
    ForwardListNode<T>* next;

public:
    ForwardListNode(const T& _value):Node<T>(_value),next(nullptr){
    }

    ~ForwardListNode(){
    }
};

template <typename T>
class DoubleListNode : public Node<T> {
public:
    typedef typename Node<T>::value_t value_t;

public:
    DoubleListNode<T>* next;
    DoubleListNode<T>* prev;

public:
    DoubleListNode(const T& _value):Node<T>(_value),next(nullptr){
    }

    ~DoubleListNode(){
    }
};

#define DEFAULT_NODE 0
#define FOWARD_NODE 1
#define DOUBLE_NODE 2


template <typename T, typename NT>
struct NodeTraits{
    static const int nodeType = DEFAULT_NODE;
};

template <typename NT>
struct NodeTraits< ForwardListNode<NT>, NT >{
    static const int nodeType = FOWARD_NODE;
};

template <typename NT>
struct NodeTraits< DoubleListNode<NT>, NT >{
    static const int nodeType = DOUBLE_NODE;
};
*/

#endif //CS2100_LIST_RENZOT_NODE_H
