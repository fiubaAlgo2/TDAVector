#include "vector.h"
#include<iostream>

using namespace std;

int main() {

    Vector vectorA;

    for (int i = 0; i < 10 ; ++i) {
        vectorA.push_back(i);
        cout << vectorA << endl;
        cout << "size: " << vectorA.size() 
            << ", capacity: " << vectorA.capacity() << endl << endl;
    }

    cout << "vectorA after resizing of 5: ";
    vectorA.resize(5);
    cout << vectorA << endl;
    cout << "size: " << vectorA.size() 
            << ", capacity: " << vectorA.capacity() << endl << endl;

    Vector vectorB(vectorA);

    cout << "vectorB is equal to vectorA? " << (vectorA == vectorB) << endl;

    cout << "vectorB after removing element in 3rd position: ";
    vectorB.remove(3);
    cout << vectorB << endl;

    cout << "vectorB is equal to vectorA? " << (vectorA == vectorB) << endl;

    cout << "vectorB third element: " << vectorB[3] << endl;

}