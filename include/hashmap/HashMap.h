#ifndef HASH_MAP_H
#define HASH_MAP_H


#include "../dynamic array/DynamicArray.h"
#include "../linked list/SingleLinkedList.h"
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



        Data(
            const K& k,
            const V& v
        ) {

            key = k;

            value = v;

        }

    };



    DynamicArray<
        SingleLinkedList<Data>
    > buckets;



    int currentSize;

    int bucketCount;

    const float maxLoad = 0.75f;




    int getIndex( const K& key);

    void resize();

public:
    // CONSTRUCTOR

    HashMap();
    // Copy Constructor
    HashMap(const HashMap<K,V>& other);
    // Destructor
    ~HashMap();

    // Assignment Operator
    HashMap<K,V>& operator=(
        const HashMap<K,V>& other
    );


    // INSERT / UPDATE

    void set(  const K& key, const V& value );

     V& get(const K& key);
 // SEARCH KEY

    bool exists( const K& key);

    void remove(const K& key);

    int size();

    float loadFactor();

    bool isEmpty();


};



// template implementation include
#include "../../src/HashMap/HashMap.tpp"

#endif