#ifndef CTL_EXCEPTION_H
#define CTL_EXCEPTION_H


#include <exception>


namespace ctl {


class OutOfRangeException : public std::exception {

public:

    const char* what() const noexcept override {

        return "Index is out of range";

    }

};


class EmptyContainerException : public std::exception {

public:

    const char* what() const noexcept override {

        return "Container is empty";

    }

};


class InvalidArgumentException : public std::exception {

public:

    const char* what() const noexcept override {

        return "Invalid argument provided";

    }

};


}


#endif