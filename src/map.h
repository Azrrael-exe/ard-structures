#ifndef MAP
#define MAP

#include "map.h"
#include <string>

using namespace std;

class Map
{
    private:        
        int map_size;
        string *map_key_list;
        int* map_value_list;
        int free_slots;
        int index;
        int seeKeyIndex(const string key);
    public:
        Map(int map_size);
        bool addKey(const string key, int value);
        int seeKeyValue(const string key);
        int freeSlots();
        bool deleteKey(const string key);
};

#endif