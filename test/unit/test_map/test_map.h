#include "map.h"
#include <unity.h>

void test_function_map(void) {
    Map<string,int> test_map = Map<string,int>(3);

    TEST_ASSERT_EQUAL_INT(3,test_map.freeSlots());
    TEST_ASSERT_TRUE(test_map.addKey("key1", 1));
    TEST_ASSERT_TRUE(test_map.addKey("key2", 2));
    TEST_ASSERT_TRUE(test_map.addKey("key3", 3));
    TEST_ASSERT_FALSE(test_map.addKey("key4", 4));
    TEST_ASSERT_EQUAL_INT(0,test_map.freeSlots());

    TEST_ASSERT_EQUAL_INT(1,test_map.seeKeyValue("key1"));
    TEST_ASSERT_EQUAL_INT(2,test_map.seeKeyValue("key2"));
    TEST_ASSERT_EQUAL_INT(3,test_map.seeKeyValue("key3"));
    TEST_ASSERT_EQUAL_INT(-1,test_map.seeKeyValue("key4"));

    TEST_ASSERT_TRUE(test_map.addKey("key1", 6));
    TEST_ASSERT_EQUAL_INT(6,test_map.seeKeyValue("key1"));
    TEST_ASSERT_EQUAL_INT(0,test_map.freeSlots());

    TEST_ASSERT_TRUE(test_map.deleteKey("key2"));
    TEST_ASSERT_EQUAL_INT(1,test_map.freeSlots());

    TEST_ASSERT_EQUAL_INT(-1,test_map.seeKeyValue("key2"));
    TEST_ASSERT_FALSE(test_map.deleteKey("key2"));
    TEST_ASSERT_EQUAL_INT(1,test_map.freeSlots());
    TEST_ASSERT_TRUE(test_map.deleteKey("key1"));
    TEST_ASSERT_TRUE(test_map.deleteKey("key3"));
    TEST_ASSERT_EQUAL_INT(3,test_map.freeSlots());
}