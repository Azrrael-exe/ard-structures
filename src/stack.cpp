#include "stack.h"

template <typename T>
Stack<T>::Stack(int size) {
    this->index = 0;
    this->size = size;
    this->list = new T[size];
    this->free_slots = this->size;
}

template <typename T>
void Stack<T>::put(T value) {
    if (this->index == (this->size - 1)){
        this->index = 0;
    }
    else {
        this->index++;
    }
    this->list[this->index] = value;
    this->free_slots --;
}

template <typename T>
T Stack<T>::get() {
    T value = this->list[this->index];
    if(this->index == 0){
        this->index = (this->size - 1);
    } else {
        this->index --;
    }
    this->free_slots ++;
    return value;
}

template class Stack<int>;
template class Stack<float>;
template class Stack<char>;