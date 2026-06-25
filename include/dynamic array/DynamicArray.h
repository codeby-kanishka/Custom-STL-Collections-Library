#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include<cstdlib>
#include<new>
#include<stdexcept>

template <typename T>
class DynamicArray {

private:

    T* arr;
    int currentSize;
    int currentCapacity;

    void resize();
    void clear();


public:

    DynamicArray();

    DynamicArray(int size, const T& value);

    DynamicArray(int capacityValue);

    DynamicArray(const DynamicArray& other);

    DynamicArray<T>& operator=(const DynamicArray<T>& other);

    ~DynamicArray();


    // methods

    void append(const T& value);

    void insert(int index,const T& value);

    void remove(int index);

    T& get(int index);


    // utility

    int size() const;

    int capacity() const;

    bool isEmpty() const;

};


#include "../src/DynamicArray.tpp"

#endif