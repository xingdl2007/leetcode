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

// need reverse second half
// interesting
class Solution {
public:
  bool isPalindrome(ListNode *head) {
    ListNode *fast = head, *slow = head;
    while (fast && fast->next) {
      fast = fast->next->next;
      slow = slow->next;
    }
    // make sure 2nd half is the small one
    if (fast)
      slow = slow->next;

    slow = reverseList(slow);
    fast = head;
    while (slow) {
      if (slow->val != fast->val)
        return false;
      slow = slow->next;
      fast = fast->next;
    }
    return true;
  }

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

auto print = [](const auto &array) {
  std::for_each(std::begin(array), std::end(array), [](const auto &s) {
    cout << s << " ";
  });
  cout << '\n';
};

int main(int argc, char *argv[]) {
  Solution so;
  ListNode n1{1};
  ListNode n2{2};
  ListNode n3{2};
  ListNode n4{1};
  n1.next = &n2;
  n2.next = &n3;
  n3.next = &n4;
  cout << so.isPalindrome(nullptr) << '\n';
  cout << so.isPalindrome(&n4) << '\n';
  cout << so.isPalindrome(&n1) << '\n';
  return 0;
}