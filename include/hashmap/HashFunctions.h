#ifndef HASH_FUNCTIONS_H
#define HASH_FUNCTIONS_H

#include <string>


template<typename K>
class HashFunction {

public:

    static unsigned long hash(const K& key) {

        const unsigned char* bytes =
        reinterpret_cast<const unsigned char*>(&key);

        unsigned long hashValue = 0;

        for(int i = 0; i < sizeof(K); i++) {

            hashValue = hashValue * 31 + bytes[i];

        }

        return hashValue;
    }

};



// int

template<>
class HashFunction<int> {

public:

    static unsigned long hash(const int& key) {

        unsigned int value = key;

        return value * 2654435761;
    }

};



// char

template<>
class HashFunction<char> {

public:
    static unsigned long hash(const char& key) {
        return key * 31;
    }
};

// float

template<>
class HashFunction<float> {

public:

    static unsigned long hash(const float& key) {

        const unsigned char* bytes =
        reinterpret_cast<const unsigned char*>(&key);

        unsigned long hashValue = 0;

        for(int i = 0; i < sizeof(float); i++) {

    hashValue = hashValue * 31 + bytes[i];

        }
        return hashValue;
    }

};




// double

template<>
class HashFunction<double> {

public:

    static unsigned long hash(const double& key) {

        const unsigned char* bytes =
        reinterpret_cast<const unsigned char*>(&key);

        unsigned long hashValue = 0;

        for(int i = 0; i < sizeof(double); i++) {

          hashValue = hashValue * 31 + bytes[i];

        }


        return hashValue;
    }

};




// string

template<>
class HashFunction<std::string> {

public:

    static unsigned long hash(const std::string& key) {


        unsigned long hashValue = 0;


        for(int i = 0; i < key.length(); i++) {

            hashValue =
            hashValue * 31 + key[i];

        }


        return hashValue;
    }

};


#endif