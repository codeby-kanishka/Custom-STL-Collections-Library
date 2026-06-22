#ifndef CTL_DYNAMIC_ARRAY_H
#define CTL_DYNAMIC_ARRAY_H


#include "../core/Exceptions.h"


namespace ctl {


template <typename T>

class DynamicArray {


private:


    T* data;

    int currentSize;

    int currentCapacity;



public:


    // Default Constructor

    DynamicArray() {

        currentSize = 0;
        currentCapacity = 4;

        data = new T[currentCapacity];

    }



    // Fill Constructor

    DynamicArray(int size, const T& value) {


        currentSize = size;
        currentCapacity = size;

        data = new T[currentCapacity];

        for(int i = 0; i < currentSize; i++) {

            data[i] = value;

        }
    }

    ~DynamicArray() {

        delete[] data;

    }