/*
 * sword to offer: problem 9
 * bit operation
 */
#include "gtest/gtest.h"

int numberof1(int n) {
  int count = 0;
  while(n) {
    count++;
    n &= n-1;
  }
  return count;
}

TEST(NUM,BASIC) {
  ASSERT_EQ(1,numberof1(2));
  ASSERT_EQ(1,numberof1(4));
  ASSERT_EQ(1,numberof1(8));
  ASSERT_EQ(4,numberof1(0xf));
  ASSERT_EQ(7,numberof1(0x324d));
  ASSERT_EQ(sizeof(int)*8,numberof1(-1));
}
