#ifndef BUFFER
#define BUFFER

class Buffer
{
protected:
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

class BufferStat: public Buffer
{
private:
    void intercambiar(int *a, int *b);
    int* burbuja();
public:
    BufferStat(int size):Buffer(size){}
    float avg();
    int min();
    int max();
    int moda();
    int median();
};

#endif

