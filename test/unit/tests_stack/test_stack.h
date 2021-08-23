#include "stack.h"
#include <unity.h>


void test_function_stack(void) {
    Stack<int> tests_stack = Stack<int>(5);
    for(int i = 0; i<10; i ++){
        (tests_stack.put(i));
    }
    
    TEST_ASSERT_EQUAL(tests_stack.get(), 9);
    TEST_ASSERT_EQUAL(tests_stack.get(), 8);
    TEST_ASSERT_EQUAL(tests_stack.get(), 7);
    TEST_ASSERT_EQUAL(tests_stack.get(), 6);
    TEST_ASSERT_EQUAL(tests_stack.get(), 5);
    TEST_ASSERT_EQUAL(tests_stack.get(), 9);

    tests_stack.put(-1);

    TEST_ASSERT_EQUAL(tests_stack.get(), -1);

}

