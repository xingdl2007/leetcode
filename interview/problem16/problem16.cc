/*
 * sword to offer: problem 16
 * reverse a list
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

// very clear
ListNode* reverse(ListNode *head) {
  if(head == NULL ) return NULL;
  ListNode *pre,*cur,*next;
  pre = next = NULL;  cur = head;
  while(cur) {
    next = cur->m_pNext;
    cur->m_pNext = pre;
    pre = cur;
    cur = next;
  }
  return pre;
}


TEST(LISTNODE,BASIC) {
  ListNode *s9 = new ListNode(9,NULL);
  ListNode *s8 = new ListNode(8,s9);
  ListNode *s7 = new ListNode(7,s8);
  ListNode *s6 = new ListNode(6,s7);
  ListNode *s5 = new ListNode(5,s6);
  ListNode *s4 = new ListNode(4,s5);
  ListNode *s3 = new ListNode(3,s4);
  ListNode *s2 = new ListNode(2,s3);
  ListNode *s1 = new ListNode(1,s2);
  ListNode *s0 = new ListNode(0,s1);

  print(s0);
  ListNode *head = reverse(s0);
  print(head);
  
  head = new ListNode();
  head = reverse(head);
  print(head);

  head = reverse(NULL);
  print(head);
}
