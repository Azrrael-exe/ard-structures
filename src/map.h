#ifndef MAP
#define MAP

#include "map.h"
#include <string>

using namespace std;

template <typename T, typename V>
class Map
{
    private:        
        unsigned int map_size;
        T* map_key_list;
        V* map_value_list;
        bool* occupation_list;
        unsigned int free_slots;
        int index;
        int seeKeyIndex(T key);
        int getFreeIndex();
    public:
        Map(unsigned int map_size);
        bool addKey(T key, V value);
        V seeKeyValue(T key);
        unsigned int freeSlots();
        bool deleteKey(T key);
};

#endif