#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list. */
struct ListNode {
  int val;
  ListNode *next;
  explicit ListNode(int x) : val(x), next(nullptr) {}
};

// assumption: n is always valid
class Solution {
public:
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    if (head == nullptr)
      return head;
    auto p = head, t = head;
    while (n && p->next) {
      p = p->next;
      --n;
    }
    while (p && p->next) {
      p = p->next;
      t = t->next;
    }
    if (n == 0)
      t->next = t->next->next;
    else
      head = head->next;
    return head;
  }
};

int main(int argc, char *argv[]) {
  Solution so;
  ListNode n1(1);
  ListNode n2(2);
  ListNode n3(3);
  ListNode n4(4);
  ListNode n5(5);
  ListNode *head;

  auto link = [&]() {
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
  };
  auto print = [](ListNode *head) {
    while (head) {
      cout << head->val << " ";
      head = head->next;
    }
    cout << '\n';
  };

  // single node
  link();
  head = &n5;
  print(so.removeNthFromEnd(head, 1));

  // double nodes
  link();
  head = &n4;
  print(so.removeNthFromEnd(head, 1));

  link();
  head = &n4;
  print(so.removeNthFromEnd(head, 2));

  // five nodes
  link();
  head = &n1;
  print(so.removeNthFromEnd(head, 1));

  link();
  head = &n1;
  print(so.removeNthFromEnd(head, 2));

  link();
  head = &n1;
  print(so.removeNthFromEnd(head, 3));

  link();
  head = &n1;
  print(so.removeNthFromEnd(head, 4));

  link();
  head = &n1;
  print(so.removeNthFromEnd(head, 5));

  return 0;
}