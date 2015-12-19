/*
 * sword to offer: problem 28
 * interesting
 */

#include <iostream>
#include <string>
#include <vector>

#include <stdio.h>

#include "gtest/gtest.h"

void per(char *pstr, char* begin) {
  if(*begin == '\0') printf("%s\n",pstr);
  else {
    for(char* ch = begin; *ch != '\0'; ++ch) {
      // first exchange
      char temp = *ch;
      *ch = *begin;
      *begin = temp;
      per(pstr,begin+1);

      // then exchange back
      temp = *ch;
      *ch = *begin;
      *begin = temp;
    }
  }
}

void Permutation(char *pstr) {
  if(pstr == NULL) return;
  per(pstr,pstr);
}

//----------------------------------------------------
// related 1: box
//----------------------------------------------------
bool boxcheck(int *d, int length=8) {
  if(d[0]+d[1]+d[2]+d[3] == d[4]+d[5]+d[6]+d[7] &&
     d[0]+d[2]+d[4]+d[6] == d[1]+d[3]+d[5]+d[7] &&
     d[0]+d[1]+d[4]+d[5] == d[2]+d[3]+d[6]+d[7])
    return true;
  return false;
}

int ArrayPer(int *data, int* begin, int length) {
  static bool ret = false;
  static int count = 0;
  if(begin == data + length) {
    if(boxcheck(data, length)) {
      for(int i=0; i<length; ++i) {
        //std::cout << data[i] << " ";
        count++;
      }
      //std::cout << std::endl;
      ret = true;
    }
  }
  else {
    for(int *p=begin; p<data+length; ++p) {
      // first change
      int temp = *p;
      *p = *begin;
      *begin = temp;

      ArrayPer(data, begin+1, length);

      temp = *p;
      *p = *begin;
      *begin = temp;
    }
  }
  return count;
}

//----------------------------------------------------
// related 2: 8-queues
//----------------------------------------------------
bool queuecheck(int *data, int len) {
  int i,j;
  for(i=0; i<len; ++i) {
    for(j=i+1; j<len; ++j) {
      if(i-j == data[i]-data[j] ||
         j-i == data[i]-data[j])
        return false;
    }
  }
  return true;
}

// actually brute-force, not very elegant
int Queues(int *data, int* begin, int length) {
  static int count = 0;
  if(begin == data + length) {
    if(queuecheck(data, length)){
      count++;
    }
  } else {
    for(int *p=begin; p<data+length; ++p) {
      // first change
      int temp = *p;
      *p = *begin;
      *begin = temp;
      Queues(data, begin+1, length);
      temp = *p;
      *p = *begin;
      *begin = temp;
    }
  }
  return count;
}

// just used with position
TEST(PER,BASIC) {
  char str[] = "abc";
  Permutation(str);
  
  int box[] = {1,3,2,3,4,2,1,4};
  int count = ArrayPer(box, box, 8);
  std::cout << count << std::endl;

  // right: 92 solutions
  int queue[] = {0,1,2,3,4,5,6,7};
  int count2 = Queues(queue, queue, 8);
  std::cout << count2 << std::endl;
}
