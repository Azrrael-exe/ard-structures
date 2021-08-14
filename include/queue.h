#ifndef QUEUE
#define QUEUE

class Queue
{
private:
    int front_index;
    int rear_index;
    int* list;
    int size;
    int free_slots;
public:
    Queue(int size);
    bool queue(int value);
    int deQueue();
    int freeSlots();
};

// Queue::Queue(int size){
//     this->list = new int[size];
//     this->front_index = 0;
//     this->rear_index = 0;
//     this->size = size;
//     this->free_slots = size;
// }

// int Queue::freeSlots() {
//     return this->free_slots;
// }

// int Queue::deQueue(){
//     if(this->free_slots <= size){
//         int value = this->list[this->front_index];
//         if(this->front_index + 1 == this->size){
//             this->front_index = 0;
//         } else {
//             this->front_index ++;
//         }
//         this->free_slots ++;
//         return value;
//     }
//     else {
//         return -1;
//     }
// }

// bool Queue::queue(int value) {
//     if(this->free_slots >= 1){
//         this->list[this->rear_index] = value;
//         this->free_slots --;
//         if((this->rear_index + 1) == this->size){
//             this->rear_index = 0;
//         } else {
//             this->rear_index ++;
//         }
//         return true;
//     } else {
//         return false;
//     }
// }

#endif