#ifndef MAP
#define MAP

#include "map.h"
#include <string>

using namespace std;

namespace map_error {
    static const int FULL = 1;
    static const int EMPTY = 2;
    static const int NO_KEY = 3; //Si se pasa una key que todavia no esta en el mapa
};

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
        void addKey(T key, V value);
        V seeKeyValue(T key);
        unsigned int freeSlots();
        void deleteKey(T key);
};

#endif