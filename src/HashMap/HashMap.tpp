#ifndef HASH_MAP_TPP
#define HASH_MAP_TPP


#ifndef HASH_MAP_H
#include "../include/hashmap/HashMap.h"
#endif


template<typename K, typename V>
HashMap<K,V>::HashMap() {


    bucketCount = 8;


    currentSize = 0;



    buckets =
    DynamicArray<SingleLinkedList<Data>>(bucketCount);

}

template<typename K, typename V>
HashMap<K,V>::HashMap(
    const HashMap<K,V>& other
)
{

    bucketCount = other.bucketCount;

    currentSize = other.currentSize;

    buckets = other.buckets;

}

template<typename K, typename V>
HashMap<K,V>::~HashMap() {

}

template<typename K, typename V>
HashMap<K,V>& HashMap<K,V>::operator=(
    const HashMap<K,V>& other
)
{
    if(this != &other) {
        bucketCount = other.bucketCount;
        currentSize = other.currentSize;
       buckets = other.buckets;

    }
    return *this;

}

// GET INDEX

template<typename K, typename V>
int HashMap<K,V>::getIndex(const K& key) {


    unsigned long hashValue =
    HashFunction<K>::hash(key);


    return hashValue % bucketCount;

}





// RESIZE

template<typename K, typename V>
void HashMap<K,V>::resize() {



    DynamicArray<SingleLinkedList<Data>> oldBuckets =
    buckets;



    int oldBucketCount =
    bucketCount;



    bucketCount *= 2;



    buckets =
    DynamicArray<SingleLinkedList<Data>>(bucketCount);



    currentSize = 0;



    for(int i = 0; i < oldBucketCount; i++) {


        SingleLinkedList<Data>& list =
        oldBuckets.get(i);



        for(int j = 0; j < list.size(); j++) {


            Data data =
            list.get(j);



            set(
                data.key,
                data.value
            );

        }

    }

}





// CONSTRUCTOR







// SET

template<typename K, typename V>
void HashMap<K,V>::set(
    const K& key,
    const V& value
) {


    if(loadFactor() >= maxLoad)

        resize();



    int index =
    getIndex(key);



    SingleLinkedList<Data>& list =
    buckets.get(index);




    for(int i = 0; i < list.size(); i++) {


        if(list.get(i).key == key) {


            list.get(i).value = value;


            return;

        }

    }



    Data newData(
        key,
        value
    );



    list.insertBack(newData);



    currentSize++;

}






// GET

template<typename K, typename V>
V& HashMap<K,V>::get(
    const K& key
) {


    int index =
    getIndex(key);



    SingleLinkedList<Data>& list =
    buckets.get(index);



    for(int i = 0; i < list.size(); i++) {


        if(list.get(i).key == key)


            return list.get(i).value;

    }



    throw std::runtime_error(
        "Key not found"
    );

}






// EXISTS

template<typename K, typename V>
bool HashMap<K,V>::exists(
    const K& key
) {


    int index =
    getIndex(key);



    SingleLinkedList<Data>& list =
    buckets.get(index);




    for(int i = 0; i < list.size(); i++) {


        if(list.get(i).key == key)

            return true;

    }
    return false;

}

// REMOVE

template<typename K, typename V>
void HashMap<K,V>::remove(
    const K& key
) {


    int index = getIndex(key);

    SingleLinkedList<Data>& list =
    buckets.get(index);

    for(int i = 0; i < list.size(); i++) {
        if(list.get(i).key == key) {
            list.deleteAt(i);
            currentSize--;

            return;

        }

    }



    throw std::runtime_error(
        "Key not found"
    );

}

// SIZE

template<typename K, typename V>
int HashMap<K,V>::size() {
    return currentSize;

}

// LOAD FACTOR

template<typename K, typename V>
float HashMap<K,V>::loadFactor() {


    return 
    (float)currentSize / bucketCount;

}






// EMPTY

template<typename K, typename V>
bool HashMap<K,V>::isEmpty() {


    return currentSize == 0;

}

#endif