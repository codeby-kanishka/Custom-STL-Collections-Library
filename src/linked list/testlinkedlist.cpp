#include <iostream>
#include <string>
#include "singlylinkedlist.h"

using namespace std;
int main() {

    cout << "========== INTEGER LINKED LIST TEST ==========\n";

    SingleLinkedList<int> list;

    // isEmpty test
    cout << "Initially empty: ";

    if(list.isEmpty())
        cout << "Yes\n";
    else
        cout << "No\n";

    // insertBack test

    list.insertBack(10);
    list.insertBack(20);
    list.insertBack(30);

    cout << "\nAfter insertBack: ";
    list.print();

    // insertFront test

    list.insertFront(5);

    cout << "After insertFront: ";
    list.print();

    // insert(index,value)

    list.insertAt(2,15);

    cout << "After insert at index 2: ";
    list.print();

    cout << "Size: " 
         << list.size()
         << endl;

    // search test

    cout << "\nSearching 20: ";

    if(list.search(20))
        cout << "Found\n";
    else
        cout << "Not Found\n";

    cout << "Searching 100: ";

    if(list.search(100))
        cout << "Found\n";
    else
        cout << "Not Found\n";

    // deleteFront

    list.deleteFront();
    cout << "\nAfter deleteFront: ";
    list.print();

    // deleteAt

    list.deleteAt(2);


    cout << "After deleteAt index 2: ";
    list.print();





    cout << "Current Size: "
         << list.size()
         << endl;



    cout << "Empty now: ";

    if(list.isEmpty())
        cout << "Yes\n";
    else
        cout << "No\n";

    cout << "\n========== COPY CONSTRUCTOR TEST ==========\n";
    SingleLinkedList<int> copyList(list);

    cout << "Original List: ";
    list.print();

    cout << "Copied List: ";
    copyList.print();

    copyList.insertBack(1000);

    cout << "\nAfter changing copied list\n";

    cout << "Original: ";
    list.print();

    cout << "Copy: ";
    copyList.print();

    cout << "\n========== ASSIGNMENT OPERATOR TEST ==========\n";

    SingleLinkedList<int> assignList;

    assignList = list;

    cout << "Assigned List: ";
    assignList.print();

    assignList.insertBack(5000);

    cout << "\nAfter changing assigned list\n";

    cout << "Original: ";
    list.print();

    cout << "Assigned: ";
    assignList.print();

cout << "\n========== STRING LINKED LIST TEST ==========\n";

    SingleLinkedList<string> names;

    names.insertBack("Kanishka");
    names.insertBack("LinkedList");
    names.insertFront("Custom STL");

    cout << "String List: ";
    names.print();
    names.deleteAt(1);

    cout << "After deleting index 1: ";

    names.print();

    cout << "\n========== EXCEPTION TEST ==========\n";

    try {
        names.deleteAt(50);
    }
    catch(exception& e) {
        cout << "Exception caught: "
             << e.what()
             << endl;

    }
    cout << "\nAll LinkedList tests completed successfully\n";

    return 0;
}