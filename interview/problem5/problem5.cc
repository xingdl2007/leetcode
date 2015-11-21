/*
 * sword to offer: problem 5
 * list in C
 */
#include <iostream>

#include "gtest/gtest.h"


struct ListNode{
  int m_nKey;
  ListNode* m_pNext;
  ListNode(int k, ListNode* v) {m_nKey = k; m_pNext = v;}
};

// insert

// delete

// reverse print
void reverse_print(ListNode* head) {
  if(head == NULL) return;
  if(head->m_pNext) reverse_print(head->m_pNext);
  std::cout << head->m_nKey << std::endl;
}

TEST(LISTPRINT,BASIC) {
  ListNode a9(9,NULL);
  ListNode a8(8,&a9);
  ListNode a7(7,&a8);
  ListNode a6(6,&a7);
  ListNode a5(5,&a6);
  ListNode a4(4,&a5);
  ListNode a3(3,&a4);
  ListNode a2(2,&a3);
  ListNode a1(1,&a2);
  ListNode a0(0,&a1);
  reverse_print(&a0);
}
