#include <iostream>

using namespace std;

/**
 Definition for singly-linked list.
 */

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *swapPairs(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
      return head;
    }

    ListNode *cur = head, *next, *ret = head->next;
    ListNode **fix = nullptr;

    // need to fix last point
    do {
      // next node
      next = cur->next;
      // swap
      cur->next = next->next;
      next->next = cur;

      if (fix != nullptr) {
        *fix = next;
      }
      fix = &cur->next; // update fix, interesting
      cur = cur->next;  // next pair
    } while (cur != nullptr && (cur->next) != nullptr);
    return ret;
  }
};

int main(int argc, char *argv[]) {
  Solution so;
  return 0;
}