/*
 * sword to offer: problem 27
 * another interesting problem
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
  
  std::cout << std::endl;
}

void printl2r(BinaryTreeNode* root) {
  while(root != NULL) {
    std::cout << root->m_nValue << " ";
    root = root->m_pRight;
  }
  std::cout << std::endl;
}

void printr2l(BinaryTreeNode* root) {
  while(root != NULL && root->m_pRight != NULL) {
    root = root->m_pRight;
  }
  
  while(root != NULL) {
    std::cout << root->m_nValue << " ";
    root = root->m_pLeft;
  }
  std::cout << std::endl;
}

// the root point to the most biggest node in the left-subtree
// and point to the most smallest node in the right-subtree
// this Convert() function just return the smallest node in the tree
// and not NULL node
BinaryTreeNode* Convert(BinaryTreeNode* root) {
  BinaryTreeNode* left, *right, *lbiggest;
  if(root == NULL) return NULL;
  else {
    // if it was a leaf, just return the node
    // which is a special case
    if(root->m_pLeft == NULL && root->m_pRight == NULL) return root;

    // left sub-tree, need find the biggest node
    left = Convert(root->m_pLeft);
    lbiggest = left;
    while(lbiggest != NULL && lbiggest->m_pRight != NULL) {
      lbiggest = lbiggest->m_pRight;
    }
    lbiggest->m_pRight = root;
    root->m_pLeft = lbiggest;

    // right sub-tree, find the smallest node, which is just the
    // result of 'Convert()'
    right = Convert(root->m_pRight);
    right->m_pLeft = root;
    root->m_pRight = right;
  }
  return left;
}

TEST(SUBTREE,BASIC) {
  // main tree
  BinaryTreeNode *s1 = new BinaryTreeNode(4,NULL,NULL);
  BinaryTreeNode *s2 = new BinaryTreeNode(8,NULL,NULL);
  BinaryTreeNode *s3 = new BinaryTreeNode(12,NULL,NULL);
  BinaryTreeNode *s4 = new BinaryTreeNode(16,NULL,NULL);
  BinaryTreeNode *s5 = new BinaryTreeNode(6,s1,s2);
  BinaryTreeNode *s6 = new BinaryTreeNode(14,s3,s4);
  BinaryTreeNode *s7 = new BinaryTreeNode(10,s5,s6);  // the root
  BinaryTreeNode *root = s7;
  printTop2Bottom(root);

  // a good exercise of doubly-linked list
  BinaryTreeNode* list = Convert(root);
  printl2r(list);
  printr2l(list);
}
