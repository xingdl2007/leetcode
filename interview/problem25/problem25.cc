/*
 * sword to offer: problem 25
 */

#include <iostream>
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

// Right, and little elegant than the book
void findpath(BinaryTreeNode* root, int expectedsum)
{
  if(root == NULL) return;

  // must be static to record the path
  static std::deque<BinaryTreeNode*> nodes;
  std::deque<BinaryTreeNode*>::iterator it;

  nodes.push_back(root);
  
  // leaf
  if(root->m_pLeft == NULL && root->m_pRight == NULL) {
    if(root->m_nValue == expectedsum) {
      // cout
      it = nodes.begin();
      while(it != nodes.end()) {
        std::cout << (*it)->m_nValue << " ";
        ++it;
      }
      std::cout << std::endl;
    }
  }

  // check left sub-tree
  if(root->m_pLeft != NULL) {
    findpath(root->m_pLeft, expectedsum - root->m_nValue);
  }

  // check right sub-tree
  if(root->m_pRight != NULL) {
    findpath(root->m_pRight, expectedsum - root->m_nValue);
  }
  
  nodes.pop_back();
}

TEST(SUBTREE,BASIC) {
  // main tree
  BinaryTreeNode *s300 = new BinaryTreeNode(3,NULL,NULL);
  BinaryTreeNode *s400 = new BinaryTreeNode(4,s300,NULL);
  BinaryTreeNode *s700 = new BinaryTreeNode(7,NULL,NULL);
  BinaryTreeNode *s547 = new BinaryTreeNode(5,s400,s700);
  BinaryTreeNode *s1200 = new BinaryTreeNode(12,NULL,NULL);
  BinaryTreeNode *s10512 = new BinaryTreeNode(10,s547,s1200);  // the root
  BinaryTreeNode *root = s10512;

  findpath(root, 22);
}
