#include "map.h"
#include <unity.h>
#include "exception.h"

void test_function_map(void) {
    Map<string,int> test_map = Map<string,int>(3);

    TEST_ASSERT_EQUAL_INT(3,test_map.freeSlots());
    for (int i=0;i<10;i++){
        try {
            string s = "key" + std::to_string(i+1);
            test_map.addKey(s, i);
        }
        catch(Exception& err) {
            TEST_ASSERT_EQUAL(err.getCode(), map_error::FULL);
        }
    }
    
    // TEST_ASSERT_EQUAL_INT(0,test_map.freeSlots());

    // TEST_ASSERT_EQUAL_INT(1,test_map.seeKeyValue("key1"));
    // TEST_ASSERT_EQUAL_INT(2,test_map.seeKeyValue("key2"));
    // TEST_ASSERT_EQUAL_INT(3,test_map.seeKeyValue("key3"));

    // TEST_ASSERT_EQUAL_INT(-1,test_map.seeKeyValue("key4"));

    // TEST_ASSERT_TRUE(test_map.addKey("key1", 6));
    // TEST_ASSERT_EQUAL_INT(6,test_map.seeKeyValue("key1"));
    // TEST_ASSERT_EQUAL_INT(0,test_map.freeSlots());

    // TEST_ASSERT_TRUE(test_map.deleteKey("key2"));
    // TEST_ASSERT_EQUAL_INT(1,test_map.freeSlots());

    // TEST_ASSERT_EQUAL_INT(-1,test_map.seeKeyValue("key2"));
    // TEST_ASSERT_FALSE(test_map.deleteKey("key2"));
    // TEST_ASSERT_EQUAL_INT(1,test_map.freeSlots());
    // TEST_ASSERT_TRUE(test_map.deleteKey("key1"));
    // TEST_ASSERT_TRUE(test_map.deleteKey("key3"));
    // TEST_ASSERT_EQUAL_INT(3,test_map.freeSlots());
}