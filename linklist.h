//
// Created by Renzo on 13/04/2020.
//

#ifndef CS2100_LIST_RENZOT_LINKLIST_H
#define CS2100_LIST_RENZOT_LINKLIST_H

#include "list.h"

template <typename T>
class linklist: public List<T> {
public:
    linklist() : List<T>() {}

    T front(){
        if(this->head != nullptr) return this->head->value;
    }
    T back(){
        if(this->tail != nullptr) return this->tail->value;
    }

    template <typename _T>
    inline friend ostream& operator<< (ostream& _out, const Node<T>& _node){
        _out << "Nodo: [v: " <<  _node.value << ", p: " << _node.next << "]";
        return _out;
    }

    void push_back(const T& element){
        auto new_node = new Node<T>(element);
        if(empty()){
            this->head = new_node;
            this->tail = new_node;
        } else {
            new_node->prev = this->tail;
            this->tail->next = new_node;
            this->tail = new_node;
        }
        (this->l_size)++;
    }

    virtual void push_front(T element){
        auto new_node = new Node<T>(element);
        if (empty()){
            this->head = new_node;
            this->tail = new_node;
        } else {
            new_node->next = this->head;
            this->head->prev = new_node;
            this->head = new_node;
        }
        (this->l_size)++;
    }

    virtual T& pop_back(){
        if (this->head != nullptr){
            Node<T>* holder = this->tail;
            this->tail = this->tail->prev;
            this->tail->next = nullptr;
            delete holder;
        }
        (this->l_size)--;
    }

    virtual T& pop_front(void){
        if (empty()){
            Node<T>* holder = this->head;
            this->head = this->tail->next;
            this->head->prev = nullptr;
            delete holder;
        }
        (this->l_size)--;
    }

    T& operator[] (int index){
        if(0<=index && index<=this->l_size){
            Node<T>* holder = this->head;
            while(index--)
                holder = holder->next;
            return holder->value;
        }
    }

    bool empty(){
        return this->head == nullptr;
    }

    unsigned int size(){
        return this->l_size;
    }

    void clear(){
        this->tail = nullptr;
        this->head->deleteNode();
        this->head = nullptr;
        this->l_size = 0;
    }

    void erase(Node<T>* node){
        if (!empty()) {
            Node<T>* holder = this->head;
            while (holder != nullptr) {
                if (holder->next == node) {
                    auto temp = holder->next;
                    holder->next = temp->next;
                    delete temp;
                    break;
                }
                holder = holder->next;
            }
        }
    }

    void insert(Node<T>* node, const T& element){
        if (!empty()) {
            Node<T>* holder = this->head;
            while (holder != nullptr) {
                if (holder->next == node) {
                    holder->next->value = element;
                    break;
                }
                holder = holder->next;
            }
        }
    }

    void remove(const T& element){
        Node<T> * holder = this->head;
        while(holder->next != nullptr){
            if(holder->value == element){
                holder->value = NULL;
            }
        }
    }

    void sort(void) {
            Node<T>* holder = this->head;
            int size = this->l_size;
            T* elements = new T[size];
            for (int i = 0 ; i < size ; i++){
                elements[i] = holder->value;
                holder = holder->next;
            }


    }



};


#endif //CS2100_LIST_RENZOT_LINKLIST_H
