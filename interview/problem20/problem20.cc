/*
 * sword to offer: problem 20
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

// clockwise: start is useless
// seems not the best, little code repeat
void matrixprint(int **matrix, int row, int col, int start) {
  int row_s, row_e; int i;
  int col_s, col_e;
  if(matrix == NULL) return;
  row_s = 0;  row_e = row-1;
  col_s = 0;  col_e = col-1;
  while(row_e >= row_s || col_e >= col_s) {
    // left->right
    for(i=col_s; i<=col_e; ++i) {
      std::cout << matrix[row_s][i] << " ";
    }
    if(++row_s > row_e) break;
    // top->bottom
    for(i=row_s; i<=row_e; ++i) {
      std::cout << matrix[i][col_e] << " ";
    }
    if(--col_e < col_s) break;
    // right->left
    for(i=col_e; i>=col_s; --i) {
      std::cout << matrix[row_e][i] << " ";
    }
    if(--row_e < row_s) break;
    // bottom->up
    for(i=row_e; i>=row_s; --i) {
      std::cout << matrix[i][col_s] << " ";
    }
    if(++col_s > col_e) break;
  }
  std::cout << std::endl;
}

TEST(MATRIX,BASIC) {
  // a little strange
  int row0[] = {1,2,3,4};
  int row1[] = {5,6,7,8};
  int row2[] = {9,10,11,12};
  int row3[] = {13,14,15,16};
  
  // pointer array: int**
  int* matrix[] = {row0,row1,row2,row3};
  // m : int (*)[4] to int**
  // a pointer to an array of 4 ints
  // c++ primer 4 p123(p142 english)
  // int ia[3][4]; array of size 3, each element is an array of ints of size 4
  // int (*ip)[4] = ia; ip points to an array of 4 ints
  // ip = &ia[2];
  // just for demonstration
  int m[4][4] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
  //print2(m,4,4);
  //print(matrix,4,4);
  matrixprint(matrix,4,4,0);
}

TEST(MATRIX,ROW) {
  int row[] = {1,2,3,4};
  int *matrix[] = {row};
  matrixprint(matrix,1,4,0);
}

TEST(MATRIX,COLUMN) {
  int row0[] = {1};
  int row1[] = {5};
  int row2[] = {9};
  int row3[] = {13};
  int *matrix[] = {row0,row1,row2,row3};
  matrixprint(matrix,4,1,0);
}

TEST(MATRIX,ROWANDCOLUMN) {
  int row[] = {1};
  int *matrix[] = {row};
  matrixprint(matrix,1,1,0);
}

TEST(MATRIX,ONECIRCLE) {
  int row0[] = {1,2};
  int row1[] = {5,6};
  int row2[] = {9,10};
  int row3[] = {13,14};
  int *matrix[] = {row0,row1,row2,row3};
  matrixprint(matrix,4,2,0);
}

TEST(MATRIX,TWOCIRCLE) {
  int row0[] = {1,2,3};
  int row1[] = {5,6,7};
  int row2[] = {9,10,11};
  int row3[] = {13,14,15};
  int *matrix[] = {row0,row1,row2,row3};
  matrixprint(matrix,4,3,0);
}

TEST(MATRIX,CORNERCASE) {
  int *matrix = NULL;
  matrixprint(&matrix,0,0,0);
}
