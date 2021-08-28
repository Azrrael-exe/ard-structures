#include "tree.h"
#include <unity.h>

void test_function_tree(void){
    Tree test_tree = Tree(2,0);
    TEST_ASSERT_EQUAL(test_tree.addChild(2,3));
}