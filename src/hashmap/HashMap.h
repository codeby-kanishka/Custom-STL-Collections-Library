#ifndef HashMap_H
#define HashMap_H

#include<DynamicArray.h>
#include<singlylinkedlist.h>
#include<stdexcept>


template<typename K, typename V>

class HashMap{
    
  private : 

      struct Data{
        K key;
        V value;


        Data(const K& k, const V& v){
          key = k;
          value = v;
        }
      };

      DynamicArray<singlylinkedlist<Data>>buckets;

    int currentSize;
    int bucketCount;

    const float maxLoad = 0.75;

    void resize(){
        
    }

    public :  

        int size() {
        return currentSize;
    }

       float loadFactor() {
        return (float)currentSize / bucketCount;
    }

    boolisEmpty(){
      return currentSize == 0;
    }
};
       

#endif