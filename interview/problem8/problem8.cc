/*
 * sword to offer: problem 8
 * quick sort and binary search
 */

#include <iostream>
#include <assert.h>
#include "gtest/gtest.h"

void swap(int *l, int *r) {
  int temp;
  temp = *l;
  *l = *r;
  *r = temp;
}

void print(int *data, int len) {
  int i=0;
  while(len--) std::cout << data[i++] << " ";
  std::cout<<std::endl;
}

// a very useful function and tricky and a neat implementation
int partition(int *data, int start, int end) {
  int index = start + (end - start) / 2;
  int small = start-1;
  // puth the mid to the end
  swap(&data[index],&data[end]);
  for(index=start; index<end; ++index) {
    if(data[index] < data[end]) {
      small++;
      if(small != index) swap(&data[small],&data[index]);
    }
  }
  ++small;
  swap(&data[small],&data[end]);
  return small;
}

void quicksort(int *data, int start, int end) {
  if(start == end) return;
  assert(start < end);
  int index = partition(data, start, end);
  
  if(index > start) quicksort(data, start, index);
  if(index < end) quicksort(data, index+1, end);
}

// done
TEST(QUiCKSORT, BASIC) {
  int data[] = {9,8,7,6,5,4,3,2,1,0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9};
  quicksort(data,0,sizeof(data)/sizeof(data[0])-1);
  print(data,sizeof(data)/sizeof(data[0]));
}

int minest(int* data, int start, int end) {
  int ret = data[start];
  for(int i=start+1; i<end; ++i) {
    if(data[i] < ret) ret = data[i];
  }
  return ret;
}

// twisted array: binary search
// input: {3,4,5,1,2}, find the smallest number
int min(int *data, int len) {
  int head = 0, tail = len-1;
  int mid = head;
  while(data[head] >= data[tail]) {
    // the terminate condition is interesting
    if(tail - head == 1) { mid = tail;  break;}
    mid = (head+tail)/2;

    if(data[head] == data[tail] &&
       data[head] == data[mid]) {
      return minest(data,head,tail);
    }
    
    if(data[mid] >= data[head]) head = mid;
    else if(data[mid] < data[tail]) tail = mid;
  }

  return data[mid];
}

TEST(MIN,BASIC) {
  int data[] = {3,4,5,1,2};
  int data1[] = {1,0,1,1,1};
  int data2[] = {1,1,1,0,1};
  int data3[] = {1,2,3,4,5};

  // the corner cases is annoying
  ASSERT_EQ(1,min(data, sizeof(data)/sizeof(data[0])));
  ASSERT_EQ(0,min(data1, sizeof(data1)/sizeof(data1[0])));
  ASSERT_EQ(0,min(data2, sizeof(data2)/sizeof(data2[0])));
  ASSERT_EQ(1,min(data3, sizeof(data3)/sizeof(data3[0])));
}
