#ifndef SINGLE_LINKED_LIST_TPP
#define SINGLE_LINKED_LIST_TPP

#ifndef SINGLE_LINKED_LIST_H
#include "../include/linked list/SingleLinkedList.h"
#endif

// NODE CONSTRUCTOR

template<typename T>
SingleLinkedList<T>::Node::Node(const T& value) {

    data = value;

    next = nullptr;

}



// CONSTRUCTOR

template<typename T>
SingleLinkedList<T>::SingleLinkedList() {

    head = nullptr;

    tail = nullptr;

    currentSize = 0;

}



// DESTRUCTOR

template<typename T>
SingleLinkedList<T>::~SingleLinkedList() {


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




// COPY CONSTRUCTOR

template<typename T>
SingleLinkedList<T>::SingleLinkedList(
    const SingleLinkedList<T>& other
) {


    head = nullptr;

    tail = nullptr;

    currentSize = 0;



    Node* current = other.head;



    while(current != nullptr) {


        insertBack(current->data);


        current = current->next;

    }

}



// ASSIGNMENT OPERATOR

template<typename T>
SingleLinkedList<T>& 
SingleLinkedList<T>::operator=(
    const SingleLinkedList<T>& other
) {
    if(this == &other)
        return *this;
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




// INSERT FRONT

template<typename T>
void SingleLinkedList<T>::insertFront(
    const T& value
) {
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

// INSERT BACK

template<typename T>
void SingleLinkedList<T>::insertBack(
    const T& value
) {
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




// DELETE FRONT

template<typename T>
void SingleLinkedList<T>::deleteFront() {

    if(head == nullptr)

        throw std::runtime_error(
            "LinkedList is empty"
        );

    Node* temp = head;

    head = head->next;
    delete temp;
    currentSize--;

    if(currentSize == 0)
        tail = nullptr;

}
// DELETE AT

template<typename T>
void SingleLinkedList<T>::deleteAt(int index) {

    if(index < 0 || index >= currentSize)

        throw std::out_of_range(
            "Invalid index"
        );

    if(index == 0) {
        deleteFront();
        return;

    }
    Node* previous = head;

    for(int i=0; i<index-1; i++)

        previous = previous->next;

    Node* temp = previous->next;

    previous->next = temp->next;

    if(temp == tail)

        tail = previous;

    delete temp;

    currentSize--;

}




// GET

template<typename T>
T& SingleLinkedList<T>::get(int index) {


    if(index < 0 || index >= currentSize)

        throw std::out_of_range(
            "Invalid index"
        );



    Node* current = head;



    for(int i=0; i<index; i++)

        current = current->next;



    return current->data;

}




// INSERT AT

template<typename T>
void SingleLinkedList<T>::insertAt(
    int index,
    const T& value
) {


    if(index < 0 || index > currentSize)

        throw std::out_of_range(
            "Invalid index"
        );



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



    for(int i=0; i<index-1; i++)

        current = current->next;



    newNode->next = current->next;



    current->next = newNode;



    currentSize++;

}





// SEARCH

template<typename T>
bool SingleLinkedList<T>::search(
    const T& value
) const {


    Node* current = head;



    while(current != nullptr) {


        if(current->data == value)

            return true;



        current = current->next;

    }



    return false;

}



// SIZE

template<typename T>
int SingleLinkedList<T>::size() const {

    return currentSize;

}



// EMPTY

template<typename T>
bool SingleLinkedList<T>::isEmpty() const {

    return currentSize == 0;

}




// PRINT

template<typename T>
void SingleLinkedList<T>::print() const {


    Node* current = head;



    while(current != nullptr) {


        std::cout << current->data << " ";


        current = current->next;

    }



    std::cout << std::endl;

}



#endif