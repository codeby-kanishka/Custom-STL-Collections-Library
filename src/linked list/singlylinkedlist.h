#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
#include <stdexcept>

template <typename T>
class LinkedList {

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
    int currentSize;



public:


    // Constructor
    LinkedList() {

        head = nullptr;
        currentSize = 0;
    }





    // Destructor
    ~LinkedList() {

        Node* current = head;

        while(current != nullptr) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
        head = nullptr;
        currentSize = 0;
    }

    // Copy Constructor
    LinkedList(const LinkedList<T>& other) {

        head = nullptr;
        currentSize = 0;

        Node* current = other.head;
        while(current != nullptr) {

            insert(currentSize, current->data);

            current = current->next;
        }
    }

    // Assignment Operator
    LinkedList<T>& operator=(const LinkedList<T>& other) {
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
        currentSize = 0;
        current = other.head;

      while(current != nullptr) {
            insert(currentSize, current->data);
            current = current->next;
        }
     return *this;
    }


    void insertFront(const T& value) {

        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
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
    }

    void insert(int index, const T& value) {
        if(index < 0 || index > currentSize) {
            throw std::out_of_range("Invalid index");
        }

        if(index == 0) {
            insertFront(value);
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

    bool search(const T& value) {

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