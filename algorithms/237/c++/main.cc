#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

/**
 * Definition for singly-linked list.
 * */
struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  // copy is the only way
  void deleteNode(ListNode* node) {
    if (node == nullptr) return;
    auto* next = node->next;
    while (next != nullptr) {
      node->val = next->val;
      if (next->next != nullptr) {
        node = next;
        next = next->next;
      } else {
        break;
      }
    }
    node->next = nullptr;
  }
};

class Solution2 {
 public:
  void deleteNode(ListNode* node) {
    if (node == nullptr || node->next == nullptr) return;
    node->val = node->next->val;
    if (node->next->next == nullptr) {
      delete node->next;
      node->next = nullptr;
    } else {
      deleteNode(node->next);
    }
  }
};

int main(int argc, char* argv[]) {
  Solution so;
  return 0;
}