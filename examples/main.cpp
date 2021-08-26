#include <Arduino.h>
#include "queue.h"
#include "stack.h"

Queue<int> queue = Queue<int>(10);

void setup(){
    Serial.begin(115200);
}

void loop(){
    for(int i=0; i<10; i++){
        Serial.println("Hello World");
        delay(500);
    }
}
