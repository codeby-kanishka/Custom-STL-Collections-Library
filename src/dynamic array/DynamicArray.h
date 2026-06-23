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

    void resize() {

        int newCapacity = currentCapacity * 1.5;

        if(newCapacity <= currentCapacity)
            newCapacity = currentCapacity + 1;

        // raw memory allocation
        T* newArr = (T*)malloc(sizeof(T) * newCapacity);

        // copy old objects into new memory
        for(int i = 0; i < currentSize; i++) {

            new(&newArr[i]) T(arr[i]);   // placement new

            arr[i].~T();                 // destroy old object
        }


        free(arr);

        arr = newArr;
        currentCapacity = newCapacity;
    }


   
    void clear() {
        for(int i = 0; i < currentSize; i++) {

            arr[i].~T();
        }
        currentSize = 0;
    }


public:
   

    DynamicArray() {

        currentSize = 0;
        currentCapacity = 4; //initial capacity = 4

        arr = (T*)malloc(sizeof(T) * currentCapacity);
    }

   
DynamicArray(int size, const T& value) {
    currentSize = size;
    currentCapacity = size;

    arr = (T*)malloc(sizeof(T)*currentCapacity);

        for(int i = 0; i < currentSize; i++) {
            new(&arr[i]) T(value);
        }
}

 DynamicArray(const DynamicArray& other) {

        currentSize = other.currentSize;
        currentCapacity = other.currentCapacity;

        arr = (T*)malloc(sizeof(T) * currentCapacity);

        for(int i = 0; i < currentSize; i++) {
            new(&arr[i]) T(other.arr[i]);
        }
    }

     ~DynamicArray() {
        clear();
        free(arr);
    }

    void append(const T& value){
               if(currentSize == currentCapacity) {
                     resize();
        }
          new(&arr[currentSize]) T(value);
        currentSize++;
    }

    
        T& get(int index) {
        if(index < 0 || index >= currentSize)
            throw std::out_of_range("Invalid index");

        return arr[index];
    }

        int size() {
        return currentSize;
    }


    int capacity() {
        return currentCapacity;
    }

    bool isEmpty() {
        return currentSize == 0;
    }

    void insert(int index,const T& value) {

        if(index < 0 || index > currentSize)
            throw std::out_of_range("Invalid index");

        if(currentSize == currentCapacity)
            resize();

        for(int i = currentSize; i > index; i--) {
            new(&arr[i]) T(arr[i-1]);
            arr[i-1].~T();
        }

        new(&arr[index]) T(value);
        currentSize++;
    }

    void remove(int index) {

    if(index < 0 || index >= currentSize)
        throw std::out_of_range("Invalid index");


    // destroy element to remove
    arr[index].~T();


    // shift remaining elements left
    for(int i = index; i < currentSize - 1; i++) {

        new(&arr[i]) T(arr[i + 1]);

        arr[i + 1].~T();
    }


    currentSize--;
}

  
  };
  
  #endif