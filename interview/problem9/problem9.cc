/*
 * sword to offer: problem 9
 * fibonacci: f(n) = f(n-1) + f(n-1)
 */

#include "gtest/gtest.h"

int fibonacci(unsigned int n) {
  if(n == 0 || n == 1) return n;
  int last1=1, last2=0, cur, i = 0;
  while(++i<n) {
    cur = last1 + last2;
    last2 = last1;
    last1 = cur;
  }
  return cur;
}

TEST(FIB, BASIC) {
  ASSERT_EQ(0,fibonacci(0));
  ASSERT_EQ(1,fibonacci(1));
  ASSERT_EQ(1,fibonacci(2));
  ASSERT_EQ(2,fibonacci(3));
  ASSERT_EQ(3,fibonacci(4));
  ASSERT_EQ(5,fibonacci(5));
  ASSERT_EQ(8,fibonacci(6));
  ASSERT_EQ(13,fibonacci(7));
  ASSERT_EQ(21,fibonacci(8));
  ASSERT_EQ(34,fibonacci(9));
  ASSERT_EQ(55,fibonacci(10));
  ASSERT_EQ(89,fibonacci(11));
  ASSERT_EQ(144,fibonacci(12));
  ASSERT_EQ(6765,fibonacci(20));
}
