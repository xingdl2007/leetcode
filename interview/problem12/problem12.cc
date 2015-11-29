/*
 * sword to offer: problem 12
 * print 1~ [n biggest], use C-style char array
 * a Big-Data problem
 */

#include <stdio.h>
#include <stdint.h>

#include "gtest/gtest.h"

bool increment(char *num, int len) {
  int carry = 0, sum;
  // take care of the carry
  for(int i=len-1; i>=0; --i) {
    sum = num[i] - '0';
    sum += carry;
    if(i == len-1)  sum++; // the source power
    
    if(sum >= 10) {
      if(i == 0) return true;
      num[i] = sum%10 + '0';
      carry = sum/10; 
    }else {
      num[i] = sum + '0';
      carry = 0;
      // reduce the loop if no carry at all
      break;
    }
  }
  return false;
}

void print(char *num, int len) {
  bool preceding = true;
  for(int i=0; i<len; ++i) {
    if(num[i] != '0') preceding = false;
    if(!preceding) printf("%c", num[i]);
  }
  printf(" ");
}

// method 1: straight-forward
void print1toN(int n) {
  if(n <= 0) return;
  char* number = new char[n+1];
  memset(number,'0',n); // this is important
  number[n] = '\0';
  // not overflow
  while(!increment(number,n)) {
    print(number,n);
  }
  delete[] number;
}

void print_rec(char *num, int length, int index) {
  if(index == length-1) {
    print(num,length);
    return;
  }
  for(int i=0; i<10; ++i) {
    num[index+1] = '0' + i;
    print_rec(num,length,index+1);
  }
}

// method 2: recursive, may overflow stack
void print1toN2(int n) {
  if(n <= 0) return;
  char* number = new char[n+1];
  memset(number,'0',n); // this is important
  number[n] = '\0';

  for(int i=0; i<10;++i) {
    number[0] = '0' + i;
    print_rec(number,n,0);
  }

  delete[] number;
}


TEST(BIGDATA,BASIC) {
  char num[] = {"000102030405"};
  print(num,strlen(num));  
  increment(num,strlen(num));
  print(num,strlen(num));
  
  // test print1toN()
  print1toN(0);
  print1toN(1);
  print1toN(2);
  print1toN(3);

  print1toN2(0);
  print1toN2(1);
  print1toN2(2);
  print1toN2(3);
}
