
#ifndef SINGLE_LINKED_LIST_H
#define SINGLE_LINKED_LIST_H


#include<iostream>
#include<stdexcept>


template<typename T>
class SingleLinkedList {


private:

    struct Node {

        T data;
        Node* next;

        Node(const T& value);

    };


    Node* head;
    Node* tail;
    int currentSize;



public:


    SingleLinkedList();


    ~SingleLinkedList();


    SingleLinkedList(
        const SingleLinkedList<T>& other
    );


    SingleLinkedList<T>& operator=(
        const SingleLinkedList<T>& other
    );


    void insertFront(const T& value);


    void insertBack(const T& value);


    void insertAt(int index,const T& value);


    void deleteFront();


    void deleteAt(int index);


    T& get(int index);


    bool search(const T& value) const;


    int size() const;


    bool isEmpty() const;


    void print() const;

};



#include "../src/SingleLinkedList/SingleLinkedList.tpp"


#endif