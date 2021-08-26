#ifndef QUEUE
#define QUEUE

namespace queue_error {
    static const int FULL = 1;
    static const int EMPTY = 2;
};

template <typename T>
class Queue
{
private:
    int front_index;
    int rear_index;
    T* list;
    int size;
    int free_slots;
public:
    Queue(int size);
    void queue(T value);
    T deQueue();
    int freeSlots();
};

#endif