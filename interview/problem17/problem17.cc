/*
 * sword to offer: problem 17
 * merge two sorted lists: arsing
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

void print(ListNode *head) {
  while(head != NULL) {
    printf("%d ", head->m_nValue);
    head = head->m_pNext;
  }

  printf("\n");
}

ListNode *merge(ListNode *lhs, ListNode *rhs) {
  if(lhs == NULL) return rhs;
  if(rhs == NULL) return lhs;
  ListNode *head = NULL;
  if(lhs->m_nValue < rhs->m_nValue) {
    head = lhs;
    head->m_pNext = merge(lhs->m_pNext,rhs);
  }else {
    head = rhs;
    head->m_pNext = merge(lhs,rhs->m_pNext);
  }
  
  return head;
}

TEST(LISTNODE,BASIC) {
  ListNode *s9 = new ListNode(9,NULL);
  ListNode *s7 = new ListNode(7,s9);
  ListNode *s5 = new ListNode(5,s7);
  ListNode *s3 = new ListNode(3,s5);
  ListNode *s1 = new ListNode(1,s3);

  ListNode *s8 = new ListNode(8,NULL);
  ListNode *s6 = new ListNode(6,s8);
  ListNode *s4 = new ListNode(4,s6);
  ListNode *s2 = new ListNode(2,s4);
  ListNode *s0 = new ListNode(0,s2);

  print(s0);
  print(s1);

  // corner cases
  print(merge(NULL,s0));
  print(merge(s1,NULL));
  print(merge(NULL,NULL));

  // general
  print(merge(s0,s1));
}
