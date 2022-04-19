#include "vector.h"
#include<iostream>
#include <cmath>

// Constants
const int Vector::kGrowFactor(2);

// Constructors

Vector::Vector() {
    size_ = 0;
    capacity_ = 0;
}

Vector::Vector(const int size) {
    size_ = size;
    capacity_ = computeCapacity(size);
    data_ = new Data[capacity_];
}

Vector::Vector(const Vector &other) {
    size_ = other.size();
    capacity_ = computeCapacity(size());
    if(size() > 0) {
        data_ = new Data[capacity_];
        for (int i = 0 ; i < size() ; ++i) {
            data_[i] = other.data_[i];
        }
    }
}

// Methods

int Vector::size() const {
    return size_;
}

int Vector::capacity() const {
    return capacity_;
}

bool Vector::empty() const {
    return size_ == 0;
}

void Vector::resize(const int count) {
    if (size_ == count) {
        return;
    }
   
    capacity_ = computeCapacity(count);
    Data* aux = new Data[capacity_];
    copyDataTo(aux, count);
    deleteData();

    size_ = count;        
    data_ = aux;
}

void Vector::pushBack(const Data element) {
    if(size_ == capacity_) {
        resize(size_ + 1);
    }
    else {
        size_++;
    }
    data_[size_ - 1] = element;
}

void Vector::remove(const int position) {
    for(int i = position; i < size() - 1 ; ++i) {
        data_[i] = data_[i + 1];
    }
    data_[size_] = 0;
    size_--;
}

int Vector::computeCapacity(int size) const {
    return (int) pow(Vector::kGrowFactor, 
                    ceil(log(size)/log(Vector::kGrowFactor)));
}

void Vector::copyDataTo(Data* otherData, const int dataSize) const {
    if (size_ >= dataSize) {
        for(int i = 0; i < dataSize; ++i) {
            otherData[i] = data_[i];
        }
    } else {
        for(int i = 0; i < size_ ; ++i) {
            otherData[i] = data_[i];
        }
        for(int i = size_ ; i < dataSize ; ++i) {
            otherData[i] = 0;
        }
    }
}

void Vector::deleteData() {
    if (!empty()) {
        delete [] data_;
    }
}

bool Vector::sameElementsAs(const Vector &other) const {
    bool result = true;
    for (int i = 0; i < size(); ++i) {
        if ((*this)[i] != other[i]) {
            result = false;
        }
    }
    return result;
}

Vector::~Vector() {
    deleteData();
}

// Operators

Data Vector::operator[](const int position) const {
    return data_[position];
}

bool Vector::operator==(const Vector &other) const {
    return size() == other.size() &&
           capacity() == other.capacity() &&
           sameElementsAs(other);
}

std::ostream& operator<<(std::ostream &out, const Vector &vector) {
    out << "[";
    for (int i = 0; i < vector.size(); i++) {
        out << vector[i];
        if(i != vector.size() - 1) {
            out << ", ";
        }
    }
    out << "]";
    return out;
}