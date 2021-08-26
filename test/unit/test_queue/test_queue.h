#include "queue.h"
#include "exception.h"
#include <unity.h>

void test_function_queue(void) {
    static const int size = 5;
    Queue<int> test_queue = Queue<int>(size);
    
    for(int i=0; i<(size + 1); i++){
        try {
            TEST_ASSERT_EQUAL(test_queue.freeSlots(), (size - i));
            test_queue.queue(i);
        }
        catch (Exception& err) {
            TEST_ASSERT_EQUAL(err.getCode(), queue_error::FULL);
            break;
        }
    }  

    for(int i=0; i<(size + 1); i++) {
        try {
            TEST_ASSERT_EQUAL(test_queue.freeSlots(), i);
            TEST_ASSERT_EQUAL(test_queue.deQueue(), i);
        }
        catch (Exception& err) {
            TEST_ASSERT_EQUAL(err.getCode(), queue_error::EMPTY);
            break;
        }
    }
}
