#include "tree.h"
#include <unity.h>

template <typename T>
void test_function_tree(void){
    Tree test_tree = Tree(2,'root');
    TEST_ASSERT_TRUE(test_tree.Addchild(3,3));
    TEST_ASSERT_FALSE(test_tree.Addchild(2,2));
    TEST_ASSERT_EQUAL(test_tree.ReadValue(),2)
    TEST_ASSERT_NOT_EQUAL(test_tree.ReadValue(),1)
}