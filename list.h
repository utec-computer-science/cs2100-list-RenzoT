//
// Created by Renzo on 20/04/2020.
//

#ifndef CS2100_LIST_RENZOT_LIST_H
#define CS2100_LIST_RENZOT_LIST_H

#include "node.h"
#include <iostream>
#include <ostream>
#include "ForwardIterator.h"
using namespace std;
template <typename T>
class List {
protected:
    Node<T> *head;
    Node<T> *tail;
    int l_size;

public:

/*
    List(T*){
        //Constructor  parametro,
        //llena una lista a partir de un array
    }

    List(Node<T>*){
        //Constructor por parametro,
        //retorna una lista con un nodo
    }

    List(int){
        //Constructor por parametro,
        //retorna un lista de randoms de tamaño n
    }
*/
    List() : head(nullptr), tail(nullptr), l_size(0) {};

    ~List(){
    }

    T front(){
        if(this->head!= nullptr) return this->head->value;
    }


    T back() {
        if(this->tail!= nullptr) return this->tail->value;
    }

    void push_back(const T& element){
        Node<T>* temp = new Node<T>(element);
        if(empty()){
            this->head = temp;
            this->tail = temp;
        }
        else{
            //Inicializado en el constructor    temp->next = nullptr;
            temp->prev = this->tail;
            this->tail->next = temp;
            this->tail = temp;
        }
        (this->l_size)++;
    }

    // Inserta un elemento al inicio
    void push_front(const T& element){
        Node<T>* temp = new Node<T>(element);
        if(empty()){
            this->head = temp;
            this->tail = temp;
        }
        else{
            // Inicializado en el constructor   temp->prev = nullptr;
            temp->next = this->head;
            this->head->prev = temp;
            //El head es el temp;
            this->head = temp;
        }
        (this->l_size)++;
    }

    // Quita el ultimo elemento y retorna una referencia
     void pop_back(){
        if( !empty() ) {

            Node<T>* temp = this->tail;
            this->tail = this->tail->prev;
            this->tail->next = nullptr;

            delete temp;

            (this->l_size)--;

        }
    }

    // Quita el primer elemento y retorna una referencia
    void pop_front(){
        if( !empty() ) {
            Node<T>* temp = this->head;
            this->head = this->head->next;
            this->head->prev = nullptr;

            delete temp;

            (this->l_size)--;
        }

    }
    // Acceso aleatorio
    T& operator[] (int index){
        Node<T> * temp = head;
        for (int i = 0; i < index; i++, temp = temp->next);
        return temp->value;
    }


    bool empty(){
        return this->head == nullptr;
    }


    int size(){
        return this->l_size;
    }
    
    void clear(){
        while( !empty() ) {
            pop_back();
        }
    }
    /*
    // Elimina un elemento en base a un puntero
    void erase(Node<T>* node) = 0;

    // Inserta un elemento  en base a un puntero
    void insert(Node<T>* node, const T& element) = 0;

    // Elimina todos los elementos por similitud
    void remove(const T& element) = 0;
    */

    void sort(){
        Node<T>* temp = this->head;
        int size = this->l_size;
        T* elements = new T[size];

        for(int i  = 0; i < size; i++){
            elements[i] = temp->value;
            temp = temp->next;
        }

        sort(elements,elements+size);

        temp = this->head;
        for(int i  = 0; i <size; i++){
            temp->value = elements[i];
            temp = temp->next;
        }

    }

    void reverse() {
        if(!empty()) {
            Node<T>* temp = this->head;
            int length = this->l_size;
            T* elements = new T[length];

            for (int i = 0; i < length; ++i) {
                elements[i] = temp->value;
                temp = temp->next;
            }
            reverse(elements,elements+length);
            temp = this->head;

            for (int j = 0; j < length; ++j) {
                temp->value = elements[j];
                temp = temp->next;
            }
        }

    }

    ForwardIterator<T> begin() {
        ForwardIterator<T> it(this->head);
        return it;
    }

    ForwardIterator<T> end() {
        ForwardIterator<T> it(this->tail);
        return it;
    }

    // Imprime la lista con cout
    inline friend std::ostream& operator<<(std::ostream& o, const List& list) {
        auto temp = list.head;
        while (temp != nullptr) {
            o << temp->value << ' ';
            temp = temp->next;
        }
        return o;
    }

};
#endif //CS2100_LIST_RENZOT_LIST_H
