/*
 * sword to offer: problem 18
 * subtree matching
 */

#include <iostream>
#include <algorithm>

#include "gtest/gtest.h"

struct BinaryTreeNode {
  int m_nValue;
  BinaryTreeNode *m_pLeft;
  BinaryTreeNode *m_pRight;
  
  // C'or
  BinaryTreeNode():m_nValue(0),m_pLeft(NULL),m_pRight(NULL) { }
  BinaryTreeNode(int k, BinaryTreeNode *l, BinaryTreeNode *r)
      :m_nValue(k),m_pLeft(l),m_pRight(r) { }
};

// elegant
bool checksubtree(BinaryTreeNode *lhs, BinaryTreeNode *rhs) {
  if(lhs == NULL && rhs == NULL) return true;
  
  if(lhs->m_nValue != rhs->m_nValue) return false;
  return (checksubtree(lhs->m_pLeft, lhs->m_pLeft)) &&
      (checksubtree(rhs->m_pRight, rhs->m_pRight));
}

// elegant
bool isSubtree(BinaryTreeNode *lhs, BinaryTreeNode *rhs) {
  bool ret = false;

  if(lhs != NULL && rhs != NULL) {
    if(lhs->m_nValue == rhs->m_nValue) {
      ret = checksubtree(lhs,rhs);
    }
    if(!ret) ret = isSubtree(lhs->m_pLeft, rhs);
    if(!ret) ret = isSubtree(lhs->m_pRight, rhs);
  }
  return ret;
}


TEST(SUBTREE,BASIC) {
  // main tree
  BinaryTreeNode *s400 = new BinaryTreeNode(4,NULL,NULL);
  BinaryTreeNode *s700 = new BinaryTreeNode(7,NULL,NULL);
  BinaryTreeNode *s247 = new BinaryTreeNode(2,s400,s700);
  BinaryTreeNode *s900 = new BinaryTreeNode(9,NULL,NULL);
  BinaryTreeNode *s892 = new BinaryTreeNode(8,s900,s247);
  BinaryTreeNode *s7002 = new BinaryTreeNode(7,NULL,NULL);
  BinaryTreeNode *s887 = new BinaryTreeNode(8,s892,s7002);

  // sub tree
  BinaryTreeNode *b900 = new BinaryTreeNode(9,NULL,NULL);
  BinaryTreeNode *b200 = new BinaryTreeNode(2,NULL,NULL);
  BinaryTreeNode *b892 = new BinaryTreeNode(8,b900,b200);

  ASSERT_TRUE(isSubtree(s887, b892));
  ASSERT_FALSE(isSubtree(s887, NULL));
  ASSERT_FALSE(isSubtree(NULL, b892));
  ASSERT_TRUE(isSubtree(b892, s887));
}
