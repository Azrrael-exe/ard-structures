#include "queue.h"
#include <unity.h>


void test_function_queue(void) {
    Queue test_queue = Queue(3);
    TEST_ASSERT_TRUE(test_queue.queue(1));
    TEST_ASSERT_TRUE(test_queue.queue(2));
    TEST_ASSERT_TRUE(test_queue.queue(3));

    TEST_ASSERT_FALSE(test_queue.queue(4));

    TEST_ASSERT_EQUAL(test_queue.deQueue(), 1);
    TEST_ASSERT_NOT_EQUAL(test_queue.deQueue(), 1);
    TEST_ASSERT_EQUAL(test_queue.deQueue(), 3);
    TEST_ASSERT_NOT_EQUAL(test_queue.freeSlots(), 0);
}

int main(int argc, char **argv) {
    UNITY_BEGIN();
    RUN_TEST(test_function_queue);
    UNITY_END();
    return 0;
}