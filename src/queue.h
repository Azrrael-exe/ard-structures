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

#endif