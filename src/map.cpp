#include "map.h"
#include <string>

using namespace std;

template <typename T, typename V>
Map<T,V>::Map(unsigned int map_size) {
    this->map_size = map_size;
    this->map_key_list = new T[this->map_size];
    this->map_value_list = new V[this->map_size];
    this->occupation_list = new bool[this->map_size];
    this->free_slots = map_size;
    this->index = 0;
}

template <typename T, typename V>
int Map<T,V>::getFreeIndex() {
    //Funcion para localizar el primer index vacio, segun occupation_list
    for (int i=0; i<this->map_size; i++) {
        if(!occupation_list[i]){
            //el primer valor en false
            return i;
        }
    }
    return -1;
}

template <typename T, typename V>
bool Map<T,V>::addKey(T key, V value) {
    int key_index = this->seeKeyIndex(key);
    if (key_index == -1) {
        if (free_slots>0){
            this->index = this->getFreeIndex();
            this->map_key_list[this->index] = key;
            this->map_value_list[this->index] = value;
            this->occupation_list[this->index] = true;            
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

template <typename T, typename V>
V Map<T,V>::seeKeyValue(T key) {
    for (int i=0; i<this->map_size; i++) {
        if (occupation_list[i]){
            // Revisa que si hayan elementos para ese index
            if (key == this->map_key_list[i]) {
            // if (key.compare(this->map_key_list[i])==0) {
                return this->map_value_list[i];
            }
        }
    } 
    return -1;   
}

template <typename T, typename V>
int Map<T,V>::seeKeyIndex(T key) {
    for (int i=0; i<this->map_size; i++) {
        if (occupation_list[i]){
            // Revisa que si hayan elementos para ese index
            if (key == this->map_key_list[i]) {
            // if (key.compare(this->map_key_list[i])==0) {
                return i;
            }
        }
    } 
    return -1;   
}

template <typename T, typename V>
bool Map<T,V>::deleteKey(T key) {
    int key_index = this->seeKeyIndex(key);
    if (key_index == -1) {
        return false;
    }
    else {
        this->occupation_list[key_index] = false;
        // this->index--;
        // this->map_key_list[key_index] = this->map_key_list[index];
        // this->map_value_list[key_index] = this->map_value_list[index];
        // this->map_key_list[index] = "";
        // this->map_value_list[index] = 0;
        this->free_slots++;
        return true;
    }
}

template <typename T, typename V>
unsigned int Map<T,V>::freeSlots() {
    return free_slots;
}

template class Map<string,int>;
template class Map<char,int>;