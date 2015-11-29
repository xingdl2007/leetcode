/*
 * sword to offer: problem 15
 * find the last Kth Node of a list: one pass search
 */

#include <iostream>
#include <algorithm>

#include "gtest/gtest.h"

struct ListNode
{
  int m_nValue;
  ListNode * m_pNext;

  ListNode():m_nValue(0),m_pNext(NULL) { }
  ListNode(int k, ListNode* v) { m_nValue = k; m_pNext = v;}
};

void print(ListNode *n) {
  std::cout << n->m_nValue << std::endl;
}

// an interesting problem
ListNode *findkth2tail(ListNode *head, unsigned int k) {
  if(head == NULL || k == 0) return NULL;
  
  ListNode *ret = head;
  for(int i=1; i<k; i++) {
    if(head->m_pNext != NULL) head = head->m_pNext;
    else return NULL;
  }

  // the last node
  while(head->m_pNext != NULL) {
    head = head->m_pNext;
    ret = ret->m_pNext;
  }

  return ret;
}

TEST(LASTKTHNODE,BASIC) {
  // last kth node has the value of k
  ListNode *s9 = new ListNode(1,NULL);
  ListNode *s8 = new ListNode(2,s9);
  ListNode *s7 = new ListNode(3,s8);
  ListNode *s6 = new ListNode(4,s7);
  ListNode *s5 = new ListNode(5,s6);
  ListNode *s4 = new ListNode(6,s5);
  ListNode *s3 = new ListNode(7,s4);
  ListNode *s2 = new ListNode(8,s3);
  ListNode *s1 = new ListNode(9,s2);
  ListNode *s0 = new ListNode(10,s1);

  // normal test
  print(findkth2tail(s0, 1));
  print(findkth2tail(s0, 2));
  print(findkth2tail(s0, 3));
  print(findkth2tail(s0, 4));
  print(findkth2tail(s0, 5));
  print(findkth2tail(s0, 6));
  print(findkth2tail(s0, 7));
  print(findkth2tail(s0, 8));
  print(findkth2tail(s0, 9));
  print(findkth2tail(s0, 10));

  // edge case
  ASSERT_EQ(NULL,findkth2tail(NULL, 12));
  ASSERT_EQ(NULL,findkth2tail(s0, 12));
  ASSERT_EQ(NULL,findkth2tail(s0, 0));
}
