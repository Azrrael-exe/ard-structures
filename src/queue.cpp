#include "queue.h"
#include "exception.h"

template <typename T>
Queue<T>::Queue(int size){
    this->list = new T[size];
    this->front_index = 0;
    this->rear_index = 0;
    this->size = size;
    this->free_slots = size;
}

template <typename T>
int Queue<T>::freeSlots() {
    return this->free_slots;
}

template <typename T>
T Queue<T>::deQueue(){
    if (this->free_slots == size){
        throw Exception(queue_error::EMPTY);
    }
    T value = this->list[this->front_index];
    if(this->front_index + 1 == this->size){
        this->front_index = 0;
    } else {
        this->front_index ++;
    }
    this->free_slots ++;
    return value;
}

template <typename T>
void Queue<T>::queue(T value) {
    if(this->free_slots > 0){
        this->list[this->rear_index] = value;
        this->free_slots --;
        if((this->rear_index + 1) == this->size){
            this->rear_index = 0;
        } else {
            this->rear_index ++;
        }
    } else {
        throw Exception(queue_error::FULL);
    }
}

template class Queue<int>;
template class Queue<float>;
template class Queue<char>;