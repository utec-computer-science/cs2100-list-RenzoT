//
// Created by Renzo on 20/04/2020.
//

#ifndef CS2100_LIST_RENZOT_LIST_H
#define CS2100_LIST_RENZOT_LIST_H

#include "node.h"
template <typename T>
class List {
protected:
    Node<T> *head;
    Node<T> *tail;
    int l_size;

public:
    List(List){

    }// Constructor copia

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

    List(void){
        this->head = nullptr;
        this->tail = nullptr;
        this->l_size = 0;
    }

    ~List(void){
    }

    // Retorna una referencia al primer elemento
    virtual T front(void) = 0;

    // Retorna una referencia al ultimo elemento
    virtual T back(void) = 0;

    // Inserta un elemento al final
    virtual void push_back(const T& element) = 0;

    // Inserta un elemento al inicio
    virtual void push_front(const T& element) = 0;

    // Quita el ultimo elemento y retorna una referencia
    virtual T& pop_back(void) = 0;

    // Quita el primer elemento y retorna una referencia
    virtual T& pop_front(void) = 0;

    // Acceso aleatorio
    virtual T& operator[] (int) = 0;

    // la lista esta vacia?
    virtual bool empty(void) = 0;

    // retorna el tamaño de la lista
    virtual unsigned int size(void) = 0;

    // Elimina toda la lista
    virtual void clear(void) = 0;

    // Elimina un elemento en base a un puntero
    virtual void erase(Node<T>* node) = 0;

    // Inserta un elemento  en base a un puntero
    virtual void insert(Node<T>* node, const T& element) = 0;

    // Elimina todos los elementos por similitud
    virtual void remove(const T& element) = 0;

    // ordena la lista
    virtual void sort(void) = 0;

    // invierte la lista
    virtual void reverse(void) = 0;

    // Imprime la lista con cout
    template<typename __T>
    inline friend std::ostream& operator<<
            (std::ostream& , const List<__T>& );
}
#endif //CS2100_LIST_RENZOT_LIST_H
