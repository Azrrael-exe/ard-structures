#include <bufferCircular.h>

Buffer::Buffer(int size){
    this->list = new int[size];
    this->in_index = 0;
    this->out_index = 0;
    this->size = size;
    this->free_slots = size;
}
bool Buffer::add(int value) {
  this->list[this->in_index] = value;
  if (this->free_slots > 0){
      this->free_slots --;
  }else {
      this->free_slots = 0;
  }
  // Aumentar el indice de entrada
  if((this->in_index + 1) == this->size){
      this->in_index = 0;
  } else {
      this->in_index ++;
  }
  // Contar espacios libres
  if(this->free_slots == 0){
      this->out_index = this->in_index;
  }
  return true;
}


int Buffer::remove(){
    if(this->free_slots < this->size){
        int value = this->list[this->out_index];
        if(this->out_index + 1 == this->size){
            this->out_index = 0;
        } else {
            this->out_index ++;
        }

        this->free_slots ++;
        return value;
    }
    else {
        return -1;
    }
}

int Buffer::inIndex() {
    return this->in_index;
}

int Buffer::outIndex() {
    return this->out_index;
}

int Buffer::freeSlots() {
    return this->free_slots;
}