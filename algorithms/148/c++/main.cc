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

// very interesting
// 1. use fast/slow pointer idiom get two sorted list
// 2. merge
class Solution {
public:
  ListNode *sortList(ListNode *head) {
    if (head == nullptr || head->next == nullptr)
      return head;
    ListNode *fast, *slow, *end;
    fast = slow = end = head;
    while (fast != nullptr && fast->next != nullptr) {
      end = slow;
      fast = fast->next->next;
      slow = slow->next;
    }
    // 1st half's end point
    end->next = nullptr;
    return merge(sortList(head), sortList(slow));
  }

  // try with iterative version
  ListNode *merge(ListNode *lhs, ListNode *rhs) {
    ListNode dummy(-1), *ptr = &dummy;
    while (lhs && rhs) {
      if (lhs->val < rhs->val) {
        ptr->next = lhs;
        lhs = lhs->next;
      } else {
        ptr->next = rhs;
        rhs = rhs->next;
      }
      ptr = ptr->next;
    }
    ptr->next = rhs == nullptr ? lhs : rhs;
    return dummy.next;
  }

  // recursive version is not fast enough
  ListNode *merge2(ListNode *lhs, ListNode *rhs) {
    if (lhs == nullptr)
      return rhs;
    if (rhs == nullptr)
      return lhs;
    if (lhs->val <= rhs->val) {
      lhs->next = merge2(lhs->next, rhs);
      return lhs;
    } else {
      rhs->next = merge2(lhs, rhs->next);
      return rhs;
    }
  }
};

auto print = [](ListNode *head) {
  while (head) {
    cout << head->val << " ";
    head = head->next;
  }
  cout << '\n';
};

int main(int argc, char *argv[]) {
  Solution so;
  ListNode n1(4);
  ListNode n2(2);
  ListNode n3(1);
  ListNode n4(3);
  n1.next = &n2;
  n2.next = &n3;
  n3.next = &n4;
  print(&n1);
  print(so.sortList(&n1));
  return 0;
}