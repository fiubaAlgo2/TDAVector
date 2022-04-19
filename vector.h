#ifndef VECTOR_H
#define VECTOR_H

#include <sstream>
typedef int Data;

class Vector {

public:
    // Constructors

    // Constructor without parameters
    // pre: -
    // post: constructs an empty vector
    Vector();

    // Constructor with parameter
    // pre: size > 0
    // pos: constructs a vector with the specified size and empty elements
    Vector(const int size);

    // Copy constructor
    // pre: `other` is a valid Vector
    // post: cronstructs a new vector based on the vector `other`
    Vector(const Vector &other);

    // Methods

    // Get the size
    // pre: -
    // post: returns the number of elements in the vector
    int size() const;

    // Get the capactity
    // pre: -
    // post: returns the size of the storage space currently 
    //       allocated to the vector expressed as number of elements.
    int capacity() const;

    // Tells if the vector is empty
    // pre: -
    // post: returns true if the vector is empty, or false otherwise
    bool empty() const;

    // Resizes the vector
    // pre: count > 0
    // post: resizes the vector so that it contains `count` elements
    void resize(const int count);

    // Push elements from the back
    // pre: `element` is a valid Data
    // post: places the element after the last element of the vector. 
    //       Makes a resize if necessary
    void push_back(const Data element);

    // Remove element from position
    // pre: 0 <= position <= size
    // pos: moves the elements right to `position` to the left 
    //      and decreases the size in a factor of 1
    void remove(const int position);

    // Destructor
    // post: If the vector is not empty, desalocates the memory used
    ~Vector();

    // Operators
    
    Data operator[](const int position) const;
    bool operator==(const Vector &other) const;
    Vector operator+(const Vector &other) const;

    
private:
    static const int kGrowFactor;
    int size_;
    int capacity_;
    Data* data_;

    int computeCapacity(const int size) const;
    void copyDataTo(Data* otherData, int sizeOfData) const;
    void deleteData();
    bool sameElementsAs(const Vector &other) const;
};

std::ostream& operator<<(std::ostream &out, const Vector &vector);

#endif // VECTOR_H