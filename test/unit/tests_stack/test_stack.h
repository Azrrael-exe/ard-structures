#include "stack.h"
#include "exception.h"
#include <unity.h>


void test_function_stack(void) {
    Stack<int> tests_stack = Stack<int>(5);

    for(int i = 0; i<10; i ++){
        try {
            tests_stack.put(i);
        } 
        catch (Exception& err) {
            TEST_ASSERT_EQUAL(err.getCode(), stack_error::FULL);
            break;
        }
    }
    
    TEST_ASSERT_EQUAL(tests_stack.get(), 4);
    TEST_ASSERT_EQUAL(tests_stack.get(), 3);
    TEST_ASSERT_EQUAL(tests_stack.get(), 2);
    TEST_ASSERT_EQUAL(tests_stack.get(), 1);
    TEST_ASSERT_EQUAL(tests_stack.get(), 0);

    try {
        TEST_ASSERT_EQUAL(tests_stack.get(), 9);
    }
    catch (Exception& err){
        TEST_ASSERT_EQUAL(err.getCode(), stack_error::EMPTY);
    }

    tests_stack.put(-1);

    TEST_ASSERT_EQUAL(tests_stack.get(), -1);

}

