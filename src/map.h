#ifndef MAP
#define MAP

#include "map.h"
#include <string>

using namespace std;

class Map
{
    private:        
        unsigned int map_size;
        string* map_key_list;
        int* map_value_list;
        bool* occupation_list;
        int free_slots;
        int index;
        int seeKeyIndex(const string key);
        int getFreeIndex();
    public:
        Map(unsigned int map_size);
        bool addKey(const string key, int value);
        int seeKeyValue(const string key);
        int freeSlots();
        bool deleteKey(const string key);
};

#endif