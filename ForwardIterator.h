#ifndef CS2100_LIST_RENZOT_FORWARDITERATOR_H
#define CS2100_LIST_RENZOT_FORWARDITERATOR_H
#include "node.h"

template <typename T>
class Iterator {
protected:
    Node<T> *current;

public:
    Iterator() : current(nullptr) {};
    Iterator(Node<T> *node) : current(node) {};
    virtual T operator*() = 0;
};

template <typename T>
class ForwardIterator : public Iterator<T> {
public:
    ForwardIterator() : Iterator<T>() {};
    ForwardIterator(Node<T> *node) : Iterator<T>(node) {};

    ForwardIterator<T> operator=(ForwardIterator<T> other) {
        this->current = other.current;
        return (*this);
    }

    bool operator!=(ForwardIterator<T> other) {
        return (this->current != other.current);
    }

    ForwardIterator<T> operator++() {
        this->current = this->current->next;
        return (*this);
    }

    T operator*() {
        // Falta controlar el caso vacío, esto puede explotar
        return this->current->data;
    }
};
#endif //CS2100_LIST_RENZOT_FORWARDITERATOR_H
