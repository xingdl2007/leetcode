#include <iostream>
#include <stack>

using namespace std;

/**
 * Definition for singly-linked list. */
struct ListNode {
  int val;
  ListNode *next;
  explicit ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    if (l1 == nullptr)
      return l2;
    if (l2 == nullptr)
      return l1;
    ListNode *head = (l1->val <= l2->val) ? l1 : l2;
    ListNode *n1 = nullptr, *n2 = nullptr;
    while (l1 && l2) {
      if (l1->val <= l2->val) {
        while (l1->next && l1->next->val <= l2->val) {
          l1 = l1->next;
        }
        n1 = l1->next;
        l1->next = l2;
        l1 = n1;
      } else {
        while (l2->next && l2->next->val <= l1->val) {
          l2 = l2->next;
        }
        n2 = l2->next;
        l2->next = l1;
        l2 = n2;
      }
    }
    return head;
  }
};

// ref: conceptual simpler
class Solution2 {
public:
  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    ListNode dummy(-1);
    auto *cur = &dummy;
    while (l1 && l2) {
      if (l1->val < l2->val) {
        cur->next = l1;
        l1 = l1->next;
      } else {
        cur->next = l2;
        l2 = l2->next;
      }
      cur = cur->next;
    }
    cur->next = l1 ? l1 : l2;
    return dummy.next;
  }
};

int main(int argc, char *argv[]) {
  Solution so;
  ListNode n1(0);
  ListNode n2(2);
  ListNode n3(10);
  n1.next = &n2;
  n2.next = &n3;
  ListNode *l1 = &n1;

  ListNode n4(1);
  ListNode n5(3);
  ListNode n6(4);
  n4.next = &n5;
  n5.next = &n6;
  ListNode *l2 = &n4;

  auto print = [](ListNode *head) {
    while (head) {
      cout << head->val << " ";
      head = head->next;
    }
    cout << '\n';
  };
  print(so.mergeTwoLists(l1, l2));
  return 0;
}