/*
 * sword to offer: problem 19
 * mirror of a binary tree
 */
#include <iostream>
#include <deque>
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

// need a prety print function to check the result
// not pretty and can't know the level
void print(BinaryTreeNode * const root) {
  if(root == NULL) return;
  std::deque<BinaryTreeNode*> q;
  BinaryTreeNode *temp;
  q.push_back(root);
  while(q.size()) {
    temp = q.front();
    q.pop_front();
    std::cout << temp->m_nValue << " ";
    if(temp->m_pLeft)  q.push_back(temp->m_pLeft);
    if(temp->m_pRight) q.push_back(temp->m_pRight);
  }
  std::cout << std::endl;
}

// no need check all the pointer
void mirror(BinaryTreeNode * const root) {
  if(root == NULL) return;

  BinaryTreeNode *temp;
  temp = root->m_pLeft;
  root->m_pLeft = root->m_pRight;
  root->m_pRight = temp;

  mirror(root->m_pLeft);
  mirror(root->m_pRight);
}

TEST(SUBTREE,BASIC) {
  // main tree
  BinaryTreeNode *s400 = new BinaryTreeNode(4,NULL,NULL);
  BinaryTreeNode *s700 = new BinaryTreeNode(7,NULL,NULL);
  BinaryTreeNode *s247 = new BinaryTreeNode(2,s400,s700);
  BinaryTreeNode *s900 = new BinaryTreeNode(9,NULL,NULL);
  BinaryTreeNode *s892 = new BinaryTreeNode(8,s900,s247);
  BinaryTreeNode *s7002 = new BinaryTreeNode(7,NULL,NULL);
  BinaryTreeNode *s887 = new BinaryTreeNode(8,s892,s7002);  // the root
  BinaryTreeNode *root = s887;
  print(root);
  mirror(root);
  print(root);
}
