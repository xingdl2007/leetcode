/*
 * sword to offer: problem 13
 * O(1): delete list-node (average time)
 */

#include <stdio.h>
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

// interesting: just consider three cases
void DeleteNode(ListNode** pListHead, ListNode* pToBeDeleted) {
  // parameter check
  if(pListHead == NULL || pToBeDeleted == NULL) return;
  
  // case 1: pToBedeleted has next node
  if(pToBeDeleted->m_pNext != NULL) {
    ListNode *next = pToBeDeleted->m_pNext;
    pToBeDeleted->m_nValue = next->m_nValue;
    pToBeDeleted->m_pNext = next->m_pNext;
    delete next;
  }
  // case 2: not, and only have one node
  else if(*pListHead == pToBeDeleted) {
    delete pToBeDeleted;
    pToBeDeleted = NULL;
    *pListHead = NULL;
  }
  // case 3: not, delete the tail node
  else {
    ListNode *pre = *pListHead;
    while(pre != NULL && pre->m_pNext != pToBeDeleted) {
      pre = pre->m_pNext;
    }
    pre->m_pNext = NULL;
    delete pToBeDeleted;
    pToBeDeleted = NULL;
  }
  
  return;
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
  
  ListNode *head = new ListNode();
  print(s0);

  // three cases
  DeleteNode(&s0, s2); print(s0);
  DeleteNode(&s0, s0); print(s0);
  DeleteNode(&s0, s9); print(s0);

  // space case
  DeleteNode(&head, head);print(head);
}
