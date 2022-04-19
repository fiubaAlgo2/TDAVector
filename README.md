# TDAVector

## Simpler implementation

Resizes every time a new element is added to the vector, allocates space for a maximum of `size` elements

```
HEAP SUMMARY:
==10152==     in use at exit: 0 bytes in 0 blocks
==10152==   total heap usage: 14 allocs, 14 frees, 73,968 bytes allocated
==10152== 
==10152== All heap blocks were freed -- no leaks are possible
```

```
void Vector::resize(const int count) {
    if (size_ == count) {
        return;
    }
   
    Data* aux = new Data[count];
    copyDataTo(aux, count);
    deleteData();

    size_ = count;        
    data_ = aux;
}

void Vector::pushBack(const Data element) {
    resize(size_ + 1);
    data_[size_ - 1] = element;
}
```