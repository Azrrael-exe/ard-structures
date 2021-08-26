#include <unity.h>
#include "test_queue/test_queue.h"
#include "tests_stack/test_stack.h"

int main(int argc, char **argv) {
    UNITY_BEGIN();
    RUN_TEST(test_function_stack);
    RUN_TEST(test_function_queue);
    UNITY_END();
    return 0;
}