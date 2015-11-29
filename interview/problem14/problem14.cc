/*
 * sword to offer: problem 14
 * partition: odd before even data
 */

#include <iostream>
#include <algorithm>

#include "gtest/gtest.h"

void print(int v) {
  std::cout << v << " ";
} 

// not stable
void reorder(int *data, unsigned int len) {
  int *p1, *p2, temp;
  p1 = data;  p2 = data + len -1;
  while(p2 > p1) {
    while(*p1 % 2 == 1) p1++;
    while(*p2 % 2 == 0) p2--;
    // swap
    if(p2 > p1) { temp = *p2; *p2 = *p1; *p1 = temp; }
  }
}

TEST(PARTITION, BASIC) {
  int data[] = {0,1,2,3,4,5,6,7,8,9};
  std::for_each(data,data+sizeof(data)/sizeof(data[0]),print);
  std::cout<< std::endl;
  reorder(data,sizeof(data)/sizeof(data[0]));
  std::for_each(data,data+sizeof(data)/sizeof(data[0]),print);
}
