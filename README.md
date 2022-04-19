# TDAVector

## Initial implementation + operators overriding

Inspired in [`std::vector`](https://en.cppreference.com/w/cpp/container/vector) from the STL C++ library.

Resizes in a factor of `Vector::kGrowFactor` every time `size == capacity` and we want to add a new element to the vector

`capacity`: the size of the storage space currently allocated to the vector expressed as number of elements
`size`: the number of elements in the vector

```
==11307== HEAP SUMMARY:
==11307==     in use at exit: 0 bytes in 0 blocks
==11307==   total heap usage: 9 allocs, 9 frees, 73,916 bytes allocated
==11307== 
==11307== All heap blocks were freed -- no leaks are possible
```

```
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

int Vector::computeCapacity(int size) const {
    return (int) pow(Vector::kGrowFactor, 
                    ceil(log(size)/log(Vector::kGrowFactor)));
}
```