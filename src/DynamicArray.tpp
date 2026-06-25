#ifndef DYNAMIC_ARRAY_TPP
#define DYNAMIC_ARRAY_TPP


// RESIZE

template<typename T>
void DynamicArray<T>::resize() {

    int newCapacity = currentCapacity * 1.5;

    if(newCapacity <= currentCapacity)
        newCapacity = currentCapacity + 1;


    T* newArr = (T*)malloc(sizeof(T) * newCapacity);

    if(!newArr)
        throw std::bad_alloc();


    int i = 0;

    try {

        for(; i < currentSize; i++) {
            new(&newArr[i]) T(arr[i]);
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



// CLEAR

template<typename T>
void DynamicArray<T>::clear() {

    for(int i = 0; i < currentSize; i++) {
        arr[i].~T();
    }

    currentSize = 0;
}



// DEFAULT CONSTRUCTOR

template<typename T>
DynamicArray<T>::DynamicArray() {

    currentSize = 0;
    currentCapacity = 4;


    arr = (T*)malloc(sizeof(T) * currentCapacity);


    if(!arr)
        throw std::bad_alloc();
}



// PARAMETERIZED CONSTRUCTOR

template<typename T>
DynamicArray<T>::DynamicArray(int size, const T& value) {

    currentSize = size;

    currentCapacity = (size > 4) ? size : 4;


    arr = (T*)malloc(sizeof(T) * currentCapacity);


    if(!arr)
        throw std::bad_alloc();


    for(int i = 0; i < currentSize; i++) {

        new(&arr[i]) T(value);

    }
}



// CAPACITY CONSTRUCTOR

template<typename T>
DynamicArray<T>::DynamicArray(int capacityValue) {


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

template<typename T>
DynamicArray<T>::DynamicArray(
    const DynamicArray<T>& other
) {

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




// ASSIGNMENT OPERATOR

template<typename T>
DynamicArray<T>& DynamicArray<T>::operator=(
    const DynamicArray<T>& other
) {


    if(this == &other)
        return *this;



    T* newArr =
    (T*)malloc(sizeof(T) * other.currentCapacity);



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



// DESTRUCTOR

template<typename T>
DynamicArray<T>::~DynamicArray() {

    clear();

    free(arr);

}



// APPEND

template<typename T>
void DynamicArray<T>::append(const T& value) {


    if(currentSize == currentCapacity)
        resize();



    new(&arr[currentSize]) T(value);


    currentSize++;

}




// INSERT

template<typename T>
void DynamicArray<T>::insert(
    int index,
    const T& value
) {


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



// REMOVE

template<typename T>
void DynamicArray<T>::remove(int index) {


    if(index < 0 || index >= currentSize)

        throw std::out_of_range("Invalid index");



    arr[index].~T();



    for(int i = index; i < currentSize - 1; i++) {


        new(&arr[i]) T(arr[i+1]);


        arr[i+1].~T();

    }


    currentSize--;

}




// GET

template<typename T>
T& DynamicArray<T>::get(int index) {


    if(index < 0 || index >= currentSize)

        throw std::out_of_range("Invalid index");



    return arr[index];

}




// SIZE

template<typename T>
int DynamicArray<T>::size() const {

    return currentSize;

}



// CAPACITY

template<typename T>
int DynamicArray<T>::capacity() const {

    return currentCapacity;

}



// EMPTY

template<typename T>
bool DynamicArray<T>::isEmpty() const {

    return currentSize == 0;

}


#endif