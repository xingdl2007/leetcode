#include <iostream>
#include <vector>
#include <algorithm>

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
  ListNode *reverseList(ListNode *head) {
    if (head == nullptr)
      return nullptr;
    ListNode *next = head->next, *nhead = head;
    if (next != nullptr) {
      nhead = reverseList(next);
      head->next = nullptr;
      next->next = head;
    }
    return nhead;
  }
};

int main(int argc, char *argv[]) {
  Solution so;
  ListNode n1{1};
  ListNode n2{2};
  n1.next = &n2;
  so.reverseList(&n1);
  return 0;
}