#include "map.h"
#include <string>

using namespace std;

Map::Map(int map_size) {
    this->map_size = map_size;
    this->map_key_list = new string[this->map_size];
    this->map_value_list = new int[this->map_size];
    this->free_slots = map_size;
    this->index = 0;
}

bool Map::addKey(const string key, int value) {
    int key_index = this->seeKeyIndex(key);
    if (key_index == -1) {
        if (free_slots>0){
            this->map_key_list[index] = key;
            this->map_value_list[index] = value;
            this->index++;
            this->free_slots--;
            return true;        
        }
        else {
            return false;
        }
    }
    else {
        this->map_value_list[key_index] = value;
        return true;
    }
}

int Map::seeKeyValue(const string key) {
    for (int i=0; i<this->map_size; i++) {
        if (key.compare(this->map_key_list[i])==0) {
            return this->map_value_list[i];
            break;
        }
    } 
    return -1;   
}

int Map::seeKeyIndex(const string key) {
    for (int i=0; i<this->map_size; i++) {
        if (key.compare(this->map_key_list[i])==0) {
            return i;
            break;
        }
    } 
    return -1;   
}

bool Map::deleteKey(const string key) {
    int key_index = this->seeKeyIndex(key);
    if (key_index == -1) {
        return false;
    }
    else {
        index--;
        this->map_key_list[key_index] = this->map_key_list[index];
        this->map_value_list[key_index] = this->map_value_list[index];
        this->map_key_list[index] = "";
        this->map_value_list[index] = 0;
        this->free_slots++;
        return true;
    }
}

int Map::freeSlots() {
    return free_slots;
}