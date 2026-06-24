
#ifndef HASH_MAP_H
#define HASH_MAP_H


#include "DynamicArray.h"
#include "singlylinkedlist.h"
#include "HashFunctions.h"

#include <stdexcept>


template<typename K, typename V>

class HashMap {


private:


    struct Data {
        K key;
        V value;

        Data() {
        }

        Data(const K& k, const V& v) {
            key = k;
            value = v;
        }

    };



    DynamicArray<SingleLinkedList<Data>> buckets;


    int currentSize;
    int bucketCount;

    const float maxLoad = 0.75;

    int getIndex(const K& key) {

        unsigned long hashValue =
            HashFunction<K>::hash(key);

        return hashValue % bucketCount;

    }

    void resize() {

        DynamicArray<SingleLinkedList<Data>> oldBuckets =
            buckets;

        int oldBucketCount = bucketCount;
        bucketCount *= 2;


  buckets = DynamicArray<SingleLinkedList<Data>>(bucketCount);
       currentSize = 0;

        for(int i = 0; i < oldBucketCount; i++) {
    SingleLinkedList<Data>& list =oldBuckets.get(i);
            for(int j = 0; j < list.size(); j++) {
                Data data = list.get(j);
                set(data.key, data.value);

            }
        }
    }

public:

    HashMap() {

        bucketCount = 8;
        currentSize = 0;
        buckets =
            DynamicArray<SingleLinkedList<Data>>(bucketCount);

    }

    // INSERT / UPDATE
    // Average O(1), Worst O(n)

    void set(const K& key, const V& value) {
        if(loadFactor() >= maxLoad) {
            resize();
        }
int index = getIndex(key);
SingleLinkedList<Data>& list = buckets.get(index);

        for(int i = 0; i < list.size(); i++) {
            if(list.get(i).key == key) {
                list.get(i).value = value;
                return;
            }
        }

        Data newData(key, value);
        list.insertBack(newData);
        currentSize++;

    }

    // GET VALUE
    // Average O(1), Worst O(n)

    V& get(const K& key) {

        int index = getIndex(key);
        SingleLinkedList<Data>& list =
            buckets.get(index);
        for(int i = 0; i < list.size(); i++) {
            if(list.get(i).key == key) {
                return list.get(i).value;

            }
        }

        throw std::runtime_error("Key not found");
    }

    // CHECK KEY EXISTS

    bool exists(const K& key) {
        int index = getIndex(key);
        SingleLinkedList<Data>& list = buckets.get(index);

        for(int i = 0; i < list.size(); i++) {
            if(list.get(i).key == key) {
                return true;

            }
        }
        return false;

    }

   void remove(const K& key) {
        int index = getIndex(key);
 SingleLinkedList<Data>& list = buckets.get(index);
        for(int i = 0; i < list.size(); i++) {
            if(list.get(i).key == key) {
                list.deleteAt(i);
                currentSize--;
                return;
            }
        }
        throw std::runtime_error("Key not found");

    }
    // NUMBER OF ELEMENTS

    int size() {
        return currentSize;
    }

    float loadFactor() {
        return (float)currentSize / bucketCount;

    }


    bool isEmpty() {
        return currentSize == 0;
    }

};

#endif