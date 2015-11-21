/*
 * sword to offer: problem 3
 * O(M+N): start from right-upper corner
 */

#include "gtest/gtest.h"

// Note: the pointer, not two-D, just use one-D, take care
// bese practise: just use one-D array, not use two-D !
bool find(int* matrix, int rows, int columns, int num) {
  //
  int row = 0;
  int column = columns;

  // parameter check
  if(matrix == NULL || rows <=0 || columns <=0) return false;

  // here is the thing: row++, column--
  while(column && row < rows) {
    if(matrix[row*columns + column-1] > num) {
      column--;
    } else if(matrix[row*columns + column-1] < num) {
      row++;
    } else  return true;
  }
  return false;
}


TEST(FIND,BASIC) {
  int matrix[] = {
    1, 2, 8, 9,
    2, 4, 9, 12,
    4, 7, 10,13,
    6, 8, 11,15};

  ASSERT_FALSE(find(matrix,4,4,16));
  ASSERT_TRUE(find(matrix,4,4,7));
  ASSERT_FALSE(find(matrix,4,4,0));
  ASSERT_FALSE(find(NULL,4,4,7));
  ASSERT_FALSE(find(matrix,0,4,9));
  ASSERT_TRUE(find(matrix,4,4,11));
  ASSERT_TRUE(find(matrix,4,4,8));
  ASSERT_TRUE(find(matrix,4,4,4));
  ASSERT_TRUE(find(matrix,4,4,6));
  ASSERT_FALSE(find(matrix,4,0,9));
}
