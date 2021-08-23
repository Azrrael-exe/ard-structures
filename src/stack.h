#ifndef STACK
#define STACK

template <typename T>
class Stack
{
private:
    int index;
    T* list;
    int size;
    int free_slots;
public:
    Stack(int size);
    void put(T value);
    T get();
};

#endif