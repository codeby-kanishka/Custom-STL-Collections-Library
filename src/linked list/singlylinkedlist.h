
#ifndef SINGLE_LINKED_LIST_H
#define SINGLE_LINKED_LIST_H

#include <iostream>
#include <stdexcept>

template <typename T>
class SingleLinkedList {

private:

    struct Node {

        T data;
        Node* next;

        Node(const T& value) {
            data = value;
            next = nullptr;
        }
    };


    Node* head;
    Node* tail;
    int currentSize;


public:

    // Constructor
    SingleLinkedList() {

        head = nullptr;
        tail = nullptr;
        currentSize = 0;
    }



    // Destructor
    ~SingleLinkedList() {

        Node* current = head;

        while(current != nullptr) {

            Node* nextNode = current->next;

            delete current;

            current = nextNode;
        }

        head = nullptr;
        tail = nullptr;
        currentSize = 0;
    }



    // Copy Constructor
    SingleLinkedList(const SingleLinkedList<T>& other) {

        head = nullptr;
        tail = nullptr;
        currentSize = 0;


        Node* current = other.head;


        while(current != nullptr) {

            insertBack(current->data);

            current = current->next;
        }
    }



    // Assignment Operator
    SingleLinkedList<T>& operator=(const SingleLinkedList<T>& other) {

        if(this == &other) {

            return *this;
        }


        Node* current = head;


        while(current != nullptr) {

            Node* nextNode = current->next;

            delete current;

            current = nextNode;
        }


        head = nullptr;
        tail = nullptr;
        currentSize = 0;



        current = other.head;


        while(current != nullptr) {

            insertBack(current->data);

            current = current->next;
        }


        return *this;
    }




    void insertFront(const T& value) {

        Node* newNode = new Node(value);
        if(head == nullptr) {
            head = tail = newNode;
        }
        else {
            newNode->next = head;
            head = newNode;
        }
        currentSize++;
    }




    void insertBack(const T& value) {
        Node* newNode = new Node(value);
        if(head == nullptr) {
            head = tail = newNode;
        }

        else {
            tail->next = newNode;
            tail = newNode;
        }
        currentSize++;
    }

    void deleteFront() {
        if(head == nullptr) {
            throw std::runtime_error("LinkedList is empty");
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        currentSize--;
        if(currentSize == 0) {
            tail = nullptr;
        }
    }

    void insert(int index, const T& value) {
        if(index < 0 || index > currentSize) {
            throw std::out_of_range("Invalid index");
        }
        if(index == 0) {
            insertFront(value);
            return;
        }
        if(index == currentSize) {
            insertBack(value);
            return;
        }
    Node* newNode = new Node(value);
     Node* current = head;

        for(int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
        currentSize++;
    }
    bool search(const T& value) const {
        Node* current = head;
        while(current != nullptr) {

            if(current->data == value) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    int size() const {
        return currentSize;
    }


    void print() const {
        Node* current = head;
        while(current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

};


#endif


    