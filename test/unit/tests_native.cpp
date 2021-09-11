#include <unity.h>
#include "test_queue/test_queue.h"
#include "tests_stack/test_stack.h"
#include "test_BufferCircular/test_bufferCircular.h"
#include "test_bufferCircular/test_bufferStat.h"

int main(int argc, char **argv) {
    UNITY_BEGIN();
    RUN_TEST(test_function_stack);
    RUN_TEST(test_function_queue);
    RUN_TEST(test_function_bufferCircular);
    RUN_TEST(test_function_bufferStat);
    UNITY_END();
    return 0;
}