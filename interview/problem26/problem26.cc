/*
 * sword to offer: problem 26
 * an interesting problem and intelligent solution
 */

#include <iostream>
#include <deque>

#include "gtest/gtest.h"

struct ComplexListNode {
  int m_nValue;
  ComplexListNode* m_pNext;
  ComplexListNode* m_pSibling;
};

// the first step
void CloneNodes(ComplexListNode* pHead) {
  ComplexListNode* pnode = pHead;
  while(pnode != NULL) {
    ComplexListNode* ptemp = new ComplexListNode();
    ptemp->m_nValue = pnode->m_nValue;
    ptemp->m_pNext = pnode->m_pNext;
    ptemp->m_pSibling = NULL;
    
    pnode->m_pNext = ptemp;
    pnode = ptemp->m_pNext;
  }
}

// the second step
void ConnectSiblingNodes(ComplexListNode* pHead) {
  ComplexListNode* pnode = pHead;
  while(pnode != NULL) {
    ComplexListNode* pcloned = pnode->m_pNext;
    if(pnode->m_pSibling != NULL) {
      pcloned->m_pSibling = pnode->m_pSibling->m_pNext;
    }
    pnode = pcloned->m_pNext;
  }
}

// the third step
// think carefully
ComplexListNode* ReconnectNodes(ComplexListNode* pHead) {
  ComplexListNode* pcloned, *ret;
  if(pHead == NULL) return pHead;
  ret = pcloned = pHead->m_pNext;
  pHead = pcloned->m_pNext;
  
  while(pHead != NULL) {
    pcloned->m_pNext = pHead->m_pNext;
    pcloned = pcloned->m_pNext;
    
    pHead->m_pNext = pcloned->m_pNext;
    pHead = pHead->m_pNext;
  }
  return ret;
}

ComplexListNode *Clone(ComplexListNode* pHead) {
  CloneNodes(pHead);
  ConnectSiblingNodes(pHead);
  return ReconnectNodes(pHead);
}

// not very easy to test, but 
TEST(COMPLEX,BASIC) {
  ComplexListNode* A = new ComplexListNode();
  ComplexListNode* B = new ComplexListNode();
  ComplexListNode* C = new ComplexListNode();
  ComplexListNode* D = new ComplexListNode();
  ComplexListNode* E = new ComplexListNode();
  ComplexListNode* list = A, *cloned;

  A->m_nValue = 'A';
  A->m_pNext = B;
  A->m_pSibling = C;

  B->m_nValue = 'B';
  B->m_pNext = C;
  B->m_pSibling = E;

  C->m_nValue = 'C';
  C->m_pNext = D;
  C->m_pSibling = C;

  D->m_nValue = 'D';
  D->m_pNext = E;
  D->m_pSibling = B;

  E->m_nValue = 'E';
  E->m_pNext = NULL;
  E->m_pSibling = E;

  cloned = Clone(list);
}
