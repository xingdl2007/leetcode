#include <iostream>
#include <vector>
#include <functional>

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
  int val;
  ListNode *next;
  explicit ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if (headA == nullptr || headB == nullptr)
      return nullptr;
    ListNode *a = headA, *b = headB;
    while (a != b) {
      a = a == nullptr ? headB : a->next;
      b = b == nullptr ? headA : b->next;
    }
    return a;
  }
};

int main(int argc, char *argv[]) {
  Solution so;
  return 0;
}