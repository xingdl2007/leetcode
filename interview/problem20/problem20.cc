/*
 * sword to offer: problem 19
 * matrix print
 */

#include <iostream>
#include <algorithm>

#include "gtest/gtest.h"


// normal print
void print(int **matrix, int row, int col) {
  int i,j;
  for(i=0; i<row; ++i) {
    for(j=0; j<col; ++j) {
      std::cout << matrix[i][j] << "  ";
    }
    std::cout << std::endl;
  }
}

// have unacceptable constrains
void print2(int (*matrix)[4], int row, int col) {
  int i,j;
  for(i=0; i<row; ++i) {
    for(j=0; j<col; ++j) {
      std::cout << matrix[i][j] << "  ";
    }
    std::cout << std::endl;
  }
}

// clockwise
void matrixprint(int **matrix, int row, int col, int start) {
  
}

TEST(MATRIX,BASIC) {
  // a little strange
  int row0[] = {1,2,3,4};
  int row1[] = {5,6,7,8};
  int row2[] = {9,10,11,12};
  int row3[] = {13,14,15,16};
  
  // pointer array: int **
  int* matrix[] = {row0,row1,row2,row3};

  // m : int (*)[4] to int**
  // a pointer to an array of 4 ints

  // c++ primer 4 p123(p142 english)
  // int ia[3][4]; array of size 3, each element is an array of ints of size 4
  // int (*ip)[4] = ia; ip points to an array of 4 ints
  // ip = &ia[2];
  // just for demonstration
  int m[4][4] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
  print2(m,4,4);
  
  print(matrix,4,4);
  matrixprint(matrix,4,4,0);
}
