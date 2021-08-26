#ifndef STACK
#define STACK

namespace stack_error {
    static const int FULL = 1;
    static const int EMPTY = 2;
};

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