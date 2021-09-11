#include <bufferCircular.h>
#include <unity.h>


void test_function_bufferCircular(void) {
    Buffer test_add = Buffer(4);
    // A add
    TEST_ASSERT_TRUE(test_add.add(1));
    TEST_ASSERT_EQUAL(test_add.freeSlots(),3);
    TEST_ASSERT_EQUAL(test_add.inIndex(),1);
    TEST_ASSERT_EQUAL(test_add.outIndex(),0);

    // B add
    TEST_ASSERT_TRUE(test_add.add(2));
    TEST_ASSERT_EQUAL(test_add.freeSlots(),2);
    TEST_ASSERT_EQUAL(test_add.inIndex(),2);
    TEST_ASSERT_EQUAL(test_add.outIndex(),0);

    // C add
    TEST_ASSERT_TRUE(test_add.add(3));
    TEST_ASSERT_EQUAL(test_add.freeSlots(),1);
    TEST_ASSERT_EQUAL(test_add.inIndex(),3);
    TEST_ASSERT_EQUAL(test_add.outIndex(),0);

    // D add
    TEST_ASSERT_EQUAL(test_add.remove(),1);
    TEST_ASSERT_EQUAL(test_add.freeSlots(),2);
    TEST_ASSERT_EQUAL(test_add.inIndex(),3);
    TEST_ASSERT_EQUAL(test_add.outIndex(),1);

    // E remove
    TEST_ASSERT_EQUAL(test_add.remove(),2);
    TEST_ASSERT_EQUAL(test_add.freeSlots(),3);
    TEST_ASSERT_EQUAL(test_add.inIndex(),3);
    TEST_ASSERT_EQUAL(test_add.outIndex(),2);

    // F remove
    TEST_ASSERT_TRUE(test_add.add(4));
    TEST_ASSERT_EQUAL(test_add.freeSlots(),2);
    TEST_ASSERT_EQUAL(test_add.inIndex(),0);
    TEST_ASSERT_EQUAL(test_add.outIndex(),2);

    // G add
    TEST_ASSERT_TRUE(test_add.add(5));
    TEST_ASSERT_EQUAL(test_add.freeSlots(),1);
    TEST_ASSERT_EQUAL(test_add.inIndex(),1);
    TEST_ASSERT_EQUAL(test_add.outIndex(),2);

    // H remove
    TEST_ASSERT_EQUAL(test_add.remove(),3);
    TEST_ASSERT_EQUAL(test_add.freeSlots(),2);
    TEST_ASSERT_EQUAL(test_add.inIndex(),1);
    TEST_ASSERT_EQUAL(test_add.outIndex(),3);

    // I remove
    TEST_ASSERT_EQUAL(test_add.remove(),4);
    TEST_ASSERT_EQUAL(test_add.freeSlots(),3);
    TEST_ASSERT_EQUAL(test_add.inIndex(),1);
    TEST_ASSERT_EQUAL(test_add.outIndex(),0);

    // J remove
    TEST_ASSERT_EQUAL(test_add.remove(),5);
    TEST_ASSERT_EQUAL(test_add.freeSlots(),4);
    TEST_ASSERT_EQUAL(test_add.inIndex(),1);
    TEST_ASSERT_EQUAL(test_add.outIndex(),1);


    // K remove
    TEST_ASSERT_EQUAL(test_add.remove(),-1);
    TEST_ASSERT_EQUAL(test_add.freeSlots(),4);
    TEST_ASSERT_EQUAL(test_add.inIndex(),1);
    TEST_ASSERT_EQUAL(test_add.outIndex(),1);

    TEST_ASSERT_TRUE(test_add.add(1));
    TEST_ASSERT_TRUE(test_add.add(2));
    TEST_ASSERT_TRUE(test_add.add(3));
    TEST_ASSERT_TRUE(test_add.add(4));
    TEST_ASSERT_EQUAL(test_add.freeSlots(),0);
    TEST_ASSERT_EQUAL(test_add.inIndex(),1);
    TEST_ASSERT_EQUAL(test_add.outIndex(),1);

    // sobre escribir
    TEST_ASSERT_TRUE(test_add.add(5));
    TEST_ASSERT_EQUAL(test_add.freeSlots(),0);
    TEST_ASSERT_EQUAL(test_add.inIndex(),2);
    TEST_ASSERT_EQUAL(test_add.outIndex(),2);

    TEST_ASSERT_TRUE(test_add.add(6));
    TEST_ASSERT_EQUAL(test_add.freeSlots(),0);
    TEST_ASSERT_EQUAL(test_add.inIndex(),3);
    TEST_ASSERT_EQUAL(test_add.outIndex(),3);

    TEST_ASSERT_EQUAL(test_add.remove(),3);
    TEST_ASSERT_EQUAL(test_add.freeSlots(),1);
    TEST_ASSERT_EQUAL(test_add.inIndex(),3);
    TEST_ASSERT_EQUAL(test_add.outIndex(),0);

    TEST_ASSERT_EQUAL(test_add.remove(),4);
    TEST_ASSERT_EQUAL(test_add.freeSlots(),2);
    TEST_ASSERT_EQUAL(test_add.inIndex(),3);
    TEST_ASSERT_EQUAL(test_add.outIndex(),1);

}
