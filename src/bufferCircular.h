#ifndef BUFFER
#define BUFFER

class Buffer
{
private:
    int in_index;
    int out_index;
    int* list;
    int size;
    int free_slots;
public:
    Buffer(int size);
    bool add(int value);
    int remove();
    int inIndex();
    int outIndex();
    int freeSlots();
};

#endif