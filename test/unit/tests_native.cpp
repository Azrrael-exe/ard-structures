#include <unity.h>
#include "test_queue/test_queue.h"
#include "tests_stack/test_stack.h"
#include "test_tree/test_tree.h"

template <typename T>
int main(int argc, char **argv) {
    UNITY_BEGIN();
    RUN_TEST(test_function_stack);
    RUN_TEST(test_function_queue);
    RUN_TEST(test_function_tree);
    UNITY_END();
    return 0;
}