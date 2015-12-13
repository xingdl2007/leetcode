/*
 * sword to offer: problem 22
 */

#include <iostream>
#include <algorithm>
#include <stack>

#include "gtest/gtest.h"

// not very elegant
bool PopOrderCheck(int *push, int *pop, int size) {
  int i_idx = 0, o_idx = 0;
  std::stack<int> stack;
  if(push == NULL || pop == NULL || size <= 0) return false;
  
  while(o_idx < size && i_idx < size) {
    while(i_idx < size && push[i_idx] != pop[o_idx]) {
      stack.push(push[i_idx]);
      i_idx++;
    }
    if(i_idx < size && push[i_idx] == pop[o_idx]) {
      i_idx++;      o_idx++;
    }
    while(o_idx < size && stack.top() == pop[o_idx]) {
      o_idx++;
      stack.pop();
    }
  }

  return stack.empty();
}

TEST(POP,BASIC) {
  int push[] = {1};
  int pop[] = {1};
  
  ASSERT_TRUE(PopOrderCheck(push, pop, sizeof(push)/sizeof(push[0])));
}

TEST(POP,TRUE) {
  int push[] = {1,2,3,4,5};
  int pop[] = {4,5,3,2,1};
  
  ASSERT_TRUE(PopOrderCheck(push, pop, sizeof(push)/sizeof(push[0])));
}

TEST(POP,FALSE) {
  int push[] = {1,2,3,4,5};
  int pop[] = {4,3,5,1,2};
  
  ASSERT_FALSE(PopOrderCheck(push, pop, sizeof(push)/sizeof(push[0])));
}

TEST(POP,CORNERCASE) {
  int push[] = {1,2};
  int pop[] = {2,5};

  ASSERT_FALSE(PopOrderCheck(NULL, pop, sizeof(push)/sizeof(push[0])));
  ASSERT_FALSE(PopOrderCheck(push, NULL, sizeof(push)/sizeof(push[0])));
  ASSERT_FALSE(PopOrderCheck(push, pop, 0));
  ASSERT_FALSE(PopOrderCheck(push, pop, -2));
  ASSERT_FALSE(PopOrderCheck(push, pop, sizeof(push)/sizeof(push[0])));
}
