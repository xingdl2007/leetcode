/*
 * sword to offer: problem 6
 * rebuild a binary tree: an interesting problem
 * with *order/top-down traverse
 */

#include <deque>
#include <iostream>
#include "gtest/gtest.h"

struct BinaryTreeNode {
  int m_nValue;
  BinaryTreeNode *m_pLeft;
  BinaryTreeNode *m_pRight;

  // C'tors
  BinaryTreeNode() {m_nValue = 0x0, m_pLeft = m_pRight = NULL;}
  BinaryTreeNode(int k, BinaryTreeNode* l, BinaryTreeNode*r)
  { m_nValue = k; m_pLeft = l; m_pRight = r;}
};

// preorder: [1,2,4,7,3,5,6,8]
// inorder:  [4,7,2,1,5,3,8,6]
// just the cargo: rebuild the whole tree
BinaryTreeNode *Construct(int *preorder, int*inorder, int length) {
  if(preorder == NULL || inorder == NULL || length <= 0)
    return NULL;
  
  BinaryTreeNode *head = new BinaryTreeNode();
  int *lpre, *rpre, *lin, *rin;
  int llen=0,rlen=0,i=0;

  // preorder[0] is the head
  head->m_nValue = preorder[0];

  /*std::cout << "head->value: " << head->m_nValue
    << " length: " << length
    << std::endl;*/
  // if just head left, return imediatelly
  if(length > 1) {
    for(i=0;i<length;++i) {
      if(inorder[i] == preorder[0]) break;
    }
    
    // split with two binary trees
    lpre = preorder + 1;
    lin = inorder;
    llen = i;
    
    rpre = preorder + llen + 1;
    rin = inorder + llen + 1;
    rlen = length - 1 - llen;

    // left
    head->m_pLeft  = Construct(lpre, lin, llen);

    // right
    head->m_pRight = Construct(rpre, rin, rlen);
  }

  return head;
}

void preorder(BinaryTreeNode* head) {
  if(head == NULL) return;
  std::cout << head->m_nValue << " ";
  preorder(head->m_pLeft);
  preorder(head->m_pRight);
}

void inorder(BinaryTreeNode* head) {
  if(head == NULL) return;
  inorder(head->m_pLeft);
  std::cout << head->m_nValue << " ";
  inorder(head->m_pRight);
}

void postorder(BinaryTreeNode* head) {
  if(head == NULL) return;
  postorder(head->m_pLeft);
  postorder(head->m_pRight);
  std::cout << head->m_nValue << " ";
}

// print binary tree at top-down fasion
// what if the 'bottom up' fashion
void level(BinaryTreeNode* head) {
  if(head == NULL) return;
  std::deque<BinaryTreeNode*> nodes;
  nodes.push_back(head);
  
  while(!nodes.empty()) {
    BinaryTreeNode *nd = nodes.front();
    nodes.pop_front();
    std::cout << nd->m_nValue << " ";
    if(nd->m_pLeft)  nodes.push_back(nd->m_pLeft);
    if(nd->m_pRight) nodes.push_back(nd->m_pRight);
  }
  std::cout << std::endl;
}

TEST(BINARYTREE, BASIC) {
  BinaryTreeNode *head;
  int pre[] = {1,2,4,7,3,5,6,8};
  int in[]  = {4,7,2,1,5,3,8,6};
  head = Construct(pre, in, sizeof(pre)/sizeof(pre[0]));
  
  std::cout << "level: " << std::endl;
  level(head);
  
  std::cout << "preorder: " << std::endl;
  preorder(head);
  std::cout << std::endl;
  
  std::cout << "inorder: " << std::endl;
  inorder(head);
  std::cout << std::endl;
  
  std::cout << "postorder: " << std::endl;
  postorder(head);
  std::cout << std::endl;
}
