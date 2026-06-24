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
        if(!newArr) throw std::bad_alloc();

        // copy old objects into new memory
        
        int i = 0;
        try{
        for(; i < currentSize; i++) {
            new(&newArr[i]) T(arr[i]);   // placement new
        }
    }
    catch(...) {

    for(int j = 0; j < i; j++)
        newArr[j].~T();

    free(newArr);

    throw;
}


for(int j = 0; j < currentSize; j++) {
    arr[j].~T();
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

        if(!arr)
    throw std::bad_alloc();
    }

   
DynamicArray(int size, const T& value) {
    currentSize = size;
      currentCapacity = (size > 4) ? size : 4;

    arr = (T*)malloc(sizeof(T)*currentCapacity);

    if(!arr)
    throw std::bad_alloc();

        for(int i = 0; i < currentSize; i++) {
            new(&arr[i]) T(value);
        }
}

DynamicArray(int capacityValue) {


    currentSize = capacityValue;

    currentCapacity = capacityValue;


    arr = (T*)malloc(sizeof(T) * currentCapacity);


    if(!arr)
        throw std::bad_alloc();



    for(int i = 0; i < currentSize; i++) {

        new(&arr[i]) T();

    }

}
// COPY CONSTRUCTOR

DynamicArray(const DynamicArray& other) {

    currentSize = other.currentSize;
    currentCapacity = other.currentCapacity;

    arr = (T*)malloc(sizeof(T) * currentCapacity);

    if(!arr)
        throw std::bad_alloc();


    int i = 0;

    try {

        for(; i < currentSize; i++) {
            new(&arr[i]) T(other.arr[i]);
        }

    }
    catch(...) {

        for(int j = 0; j < i; j++) {
            arr[j].~T();
        }

        free(arr);

        throw;
    }
}

DynamicArray<T>& operator=(const DynamicArray<T>& other) {

    if(this == &other)
        return *this;


    T* newArr = 
    (T*)malloc(sizeof(T)*other.currentCapacity);


    if(!newArr)
        throw std::bad_alloc();


    int i = 0;

    try {

        for(; i < other.currentSize; i++) {

            new(&newArr[i]) T(other.arr[i]);
        }

    }
    catch(...) {

        for(int j = 0; j < i; j++)
            newArr[j].~T();


        free(newArr);

        throw;
    }

    clear();
    free(arr);


    arr = newArr;
    currentSize = other.currentSize;
    currentCapacity = other.currentCapacity;


    return *this;
}

     ~DynamicArray() {
        clear();
        free(arr);
    }

    // METHODS

    //APPEND
    void append(const T& value){
               if(currentSize == currentCapacity) {
                     resize();
        }
          new(&arr[currentSize]) T(value);
        currentSize++;
    }
        
    //INSERT
    
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

    //REMOVE

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


        // get method 

        T& get(int index) {

    if(index < 0 || index >= currentSize)
        throw std::out_of_range("Invalid index");

    return arr[index];
}

   


    //utility methods

        int size() const{
        return currentSize;
    }


    int capacity() const{
        return currentCapacity;
    }

    bool isEmpty() const {
        return currentSize == 0;
    }
   
  };
  
  #endif