#include <iostream>
#include <string>
#include "DynamicArray.h"

using namespace std;


// Custom class test
class Student {

private:
    string name;
    int age;

public:

    Student() {
        name = "";
        age = 0;
        cout << "Default Constructor\n";
    }

    Student(string n, int a) {
        name = n;
        age = a;

        cout << "Constructor called for "
             << name << endl;
    }


    Student(const Student& other) {

        name = other.name;
        age = other.age;

        cout << "Copy Constructor called for "
             << name << endl;
    }


    ~Student() {

        cout << "Destructor called for "
             << name << endl;
    }


    void display() {

        cout << name << " " << age << endl;
    }
};



int main() {


    cout << "\n===== INT TEST =====\n";

    DynamicArray<int> numbers;

    numbers.append(10);
    numbers.append(20);
    numbers.append(30);

    numbers.insert(1, 15);

    cout << "Elements: ";

    for(int i = 0; i < numbers.size(); i++) {

        cout << numbers.get(i) << " ";
    }

    cout << "\nSize: " 
         << numbers.size();

    cout << "\nCapacity: " 
         << numbers.capacity() << endl;


    numbers.remove(2);

    cout << "After remove: ";

    for(int i = 0; i < numbers.size(); i++) {

        cout << numbers.get(i) << " ";
    }


    cout << "\n\n===== STRING TEST =====\n";

    DynamicArray<string> names;

    names.append("Kanishka");
    names.append("Custom");
    names.append("STL");

    names.insert(1,"DynamicArray");


    for(int i = 0; i < names.size(); i++) {

        cout << names.get(i) << endl;
    }


    names.remove(2);


    cout << "\nAfter removing:\n";

    for(int i = 0; i < names.size(); i++) {

        cout << names.get(i) << endl;
    }



    cout << "\n===== COPY CONSTRUCTOR TEST =====\n";


    DynamicArray<string> copyNames(names);


    for(int i = 0; i < copyNames.size(); i++) {

        cout << copyNames.get(i) << endl;
    }



    cout << "\n===== CUSTOM OBJECT TEST =====\n";


    {
        DynamicArray<Student> students;


        Student s1("Kanishka",21);
        Student s2("Alex",22);


        students.append(s1);
        students.append(s2);


        cout << "\nStored Students:\n";

        for(int i = 0; i < students.size(); i++) {

            students.get(i).display();
        }


        cout << "\nLeaving scope...\n";
    }


    cout << "\nProgram End\n";


    return 0;
}