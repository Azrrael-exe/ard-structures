#include <bufferCircular.h>
#include <unity.h>


void test_function_bufferStat(void) {
    BufferStat test_bufferStat = BufferStat(5);
    TEST_ASSERT_TRUE(test_bufferStat.add(1));
    TEST_ASSERT_TRUE(test_bufferStat.add(2));
    TEST_ASSERT_TRUE(test_bufferStat.add(2));
    TEST_ASSERT_TRUE(test_bufferStat.add(3));
    TEST_ASSERT_TRUE(test_bufferStat.add(4));

    TEST_ASSERT_EQUAL(test_bufferStat.min(),1);
    TEST_ASSERT_EQUAL(test_bufferStat.max(),4);
    TEST_ASSERT_EQUAL(test_bufferStat.avg(),2.4);
    TEST_ASSERT_EQUAL(test_bufferStat.moda(),2);
    TEST_ASSERT_EQUAL(test_bufferStat.median(),2);

    BufferStat test_bufferStat2 = BufferStat(6);
    TEST_ASSERT_TRUE(test_bufferStat2.add(2));
    TEST_ASSERT_TRUE(test_bufferStat2.add(2));
    TEST_ASSERT_TRUE(test_bufferStat2.add(1));
    TEST_ASSERT_TRUE(test_bufferStat2.add(5));
    TEST_ASSERT_TRUE(test_bufferStat2.add(4));
    TEST_ASSERT_TRUE(test_bufferStat2.add(3));

    TEST_ASSERT_EQUAL(test_bufferStat2.min(),1);
    TEST_ASSERT_EQUAL(test_bufferStat2.max(),5);
    TEST_ASSERT_EQUAL(test_bufferStat2.avg(),2.8);
    TEST_ASSERT_EQUAL(test_bufferStat2.moda(),2);
    TEST_ASSERT_EQUAL(test_bufferStat2.median(),2.5);

}