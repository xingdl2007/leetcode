/*
 * sword to offer: problem 24
 */

#include "gtest/gtest.h"

bool treeCheck(int *array, int length)
{
  if(array == NULL || length <= 0) return true;
  
  int root = array[length-1];
  int *left = array, left_len = 0;
  int *right = array, right_len = 0;
  int i,j;

  // not very elegant
  for(i=0; i<length-1; ++i) {
    if(array[i] > root) break;
  }

  for(j=i; j<length-1; ++j) {
    if(array[j] < root) return false;
  }

  left = array;
  left_len = i;

  right = array+i;
  right_len = length-i-1;
  
  return treeCheck(left, left_len) && treeCheck(right, right_len);
}

TEST(TREE,BASIC) {
  int array[] = {5,7,6,9,11,10,8};
  ASSERT_TRUE(treeCheck(array, sizeof(array)/sizeof(array[0])));

  int array2[] = {7,4,6,5};
  ASSERT_FALSE(treeCheck(array2, sizeof(array2)/sizeof(array2[0])));
}
