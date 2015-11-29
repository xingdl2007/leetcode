/*
 * sword to offer: problem 11
 * numeric algorithm, no lib-function allowed
 */
#include <math.h>
#include <stdint.h>
#include "gtest/gtest.h"

bool global_state = false;

// check whether two double nums is equal
bool equal_double(double lhs, double rhs) {
  if(lhs > rhs) return (lhs-rhs < 0.0000001);
  else return (rhs-lhs < 0.0000001);
}

bool equal_double2(double lhs, double rhs) {
  double diff = lhs - rhs;
  return (-0.000001 < diff ) && ( diff < 0.000001);
}

// take care of the exp: "unsigned int"
// so when exp == 0x0, it will return 1.0, right
double pow_loop1(double base, uint32_t exp) {
  uint32_t i;
  double ret = 1.0;
  for(i=0; i<exp; ++i) ret *= base;
  return ret;
}

// a faster method (logn)
double pow_loop2(double base, uint32_t exp) {
  double ret;
  if(exp == 0) return 1;
  if(exp == 1) return base;
  
  ret = pow_loop2(base, exp>>1);
  ret *= ret;

  // odd or even
  if(exp & 0x1) ret *= base;
  return ret;
}

// same function with 'pow' in math.h
// exponent: positive/negtive/zero
double power(double base, int32_t exponent) {
  uint32_t exp_abs;
  double ret = 1.0;
  
  if(equal_double2(base,0.0) && exponent<0) {
    global_state = true;
    return 0.0;
  }
  
  if(exponent < 0) {
    exp_abs = -exponent;
  } else {
    exp_abs = exponent;
  }
  ret = pow_loop2(base,exp_abs);
  if(exponent<0) ret = 1/ret; // must check whether the base if 0, sensitive
  return ret;
}

// when the result is big, ASSERT can fail
TEST(POWER,BASIC) {
  ASSERT_EQ(1,power(4,0));
  ASSERT_EQ(1,power(1,8));
  ASSERT_EQ(3.3,power(3.3,1));
  ASSERT_EQ(pow(2.5,3),power(2.5,3));
  ASSERT_EQ(pow(0.5,-4),power(0.5,-4));
  ASSERT_EQ(pow(2.15,2),power(2.15,2));
  ASSERT_EQ(pow(2.15,-3),power(2.15,-3));
  // coner case
  ASSERT_EQ(0,power(0,-2));
  ASSERT_TRUE(global_state);
}
