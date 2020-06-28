#include <algorithm>
#include <bitset>
#include <deque>
#include <functional>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

/**
 * Definition for singly-linked list.
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
  ListNode *deleteDuplicates(ListNode *head) {
    ListNode *cur = head, *next;
    while (cur != nullptr && cur->next != nullptr) {
      next = cur->next;
      while (next != nullptr && cur->val == next->val) {
        next = next->next;
      }
      cur->next = next;
      cur = next;
    }
    return head;
  }
};

int main(int argc, char *argv[]) {
  Solution so;
  return 0;
}