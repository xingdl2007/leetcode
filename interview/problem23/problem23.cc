/*
 * sword to offer: problem 23
 */

#include <iostream>
#include <algorithm>
#include <deque>

#include "gtest/gtest.h"

struct BinaryTreeNode {
  int m_nValue;
  BinaryTreeNode* m_pLeft;
  BinaryTreeNode* m_pRight;

  // C'or
  BinaryTreeNode():m_nValue(0),m_pLeft(NULL),m_pRight(NULL) { }
  BinaryTreeNode(int k, BinaryTreeNode *l, BinaryTreeNode *r)
      :m_nValue(k),m_pLeft(l),m_pRight(r) { }
};

void printTop2Bottom(BinaryTreeNode* root) {
  if(root == NULL) return;

  std::deque<BinaryTreeNode*> treenode;
  treenode.push_back(root);

  while(treenode.size()) {
    BinaryTreeNode* node = treenode.front();
    treenode.pop_front();

    std::cout << node->m_nValue << " ";
    if(node->m_pLeft) treenode.push_back(node->m_pLeft);
    if(node->m_pRight) treenode.push_back(node->m_pRight);
  }
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

  printTop2Bottom(root);
}


