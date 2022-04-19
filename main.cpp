#include "vector.h"
#include<iostream>

using namespace std;

int main() {

    Vector vectorA;

    for (int i = 0; i < 10 ; ++i) {
        vectorA.push_back(i);
        vectorA.print();
        cout << "size: " << vectorA.size() 
            << ", capacity: " << vectorA.capacity() << endl << endl;
    }

    cout << "vectorA after resizing of 5: ";
    vectorA.resize(5);
    vectorA.print();
    cout << "size: " << vectorA.size() 
            << ", capacity: " << vectorA.capacity() << endl << endl;

    cout << "vectorA after removing element in 3rd position: ";
    vectorA.remove(3);
    vectorA.print();
}