/*
 * sword to offer: problem 29
 */

#include <iostream>
#include <string>
#include <algorithm>

#include <stdio.h>
#include <assert.h>

#include "gtest/gtest.h"

void print(int i) {
  std::cout << i << " ";
}

static void inline swap(int *l, int *r) {
  int t = *l;
  *l = *r;
  *r = t;
}

static inline int Random(int start, int end) {
  srand(time(NULL));
  return (start+rand()%(end-start+1));

  // just return the middle-value
  //return (start+(end-start+1)/2);
}

// elegant
int partition(int*data, int len, int start, int end) {
  int index;
  int small = start-1;
  assert(data != NULL);
  index = Random(start,end);
  
  swap(&data[index],&data[end]);
  for(index=start; index<end; ++index) {
    if(data[index]<data[end]) {
      ++small;
      if(small != index) swap(&data[small],&data[index]);
    }
  }
  ++small;
  swap(&data[small],&data[end]);
  return small;
}

// find the kth value
// k : 1/2/3/4...len
int searchkth(int *data, int len, int k) {
  assert(data != NULL);
  int index = partition(data, len, 0, len-1);
  int start = 0, end = len-1;
  while(index != len-k) {
    if(index < len-k) {
      start = index + 1;
    }else {
      end = index - 1;
    }
    index = partition(data, len, start, end);
  }
  return data[index];
}

// need consider all the situation
// for example: len == 2 or len == 3
int findmorethanhalf(int *data, int len) {
  assert(data != NULL);
  int middle = len>>1;
  int start = 0, end = len-1;
  int index = partition(data, len, start, end);
  while(index != middle) {
    if(index < middle) {
      start = index + 1;
    }else {
      end = index - 1;
    }
    index = partition(data, len, start, end);
  }
  
  // wired: need consider corner cases
  if(len&1) return data[middle];      // odd
  else {                              // even
    if(data[middle-1] == data[middle]) return data[middle];
    else {
      if(data[0] == data[middle-1]) return data[middle-1];
      else return data[middle];
    }
  }
  return data[middle];
}

TEST(PART,BASIC) {
  int index;
  int data[] = {3,4,1,8,5,7,9,0,2,6};
  int len = sizeof(data)/sizeof(data[0]);

  std::cout << "Search Kth: " << std::endl;
  index = searchkth(data, len, 1);
  std::cout << index << std::endl;
  index = searchkth(data, len, 6);
  std::cout << index << std::endl;
  
  std::cout << "Search MoreThan Half: " << std::endl;
  int data2[] = {1,2,1,3,1,4,1,5,1,6};
  index = findmorethanhalf(data2, len);
  std::cout << index << std::endl;

  int data3[] = {3,2,3,2,3,2,4,2,1,2};
  index = findmorethanhalf(data3, len);
  std::cout << index << std::endl;

  int data4[] = {3};
  index = findmorethanhalf(data4, 1);
  std::cout << index << std::endl;

  int data5[] = {9,8};
  index = findmorethanhalf(data5, 2);
  std::cout << index << std::endl;

  int data6[] = {6,2,2};
  index = findmorethanhalf(data6,3);
  std::cout << index << std::endl;
}
