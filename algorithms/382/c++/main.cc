#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

/**
 * Definition for singly-linked list. */
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  /** @param head The linked list's head.
      Note that the head is guaranteed to be not null, so it contains at least
     one node. */
  Solution(ListNode* head) {
    while (head != nullptr) {
      data_.push_back(head->val);
      head = head->next;
    }
  }

  /** Returns a random node's value. */
  int getRandom() { return data_[random() % data_.size()]; }

  std::vector<int> data_;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */

int main(int argc, char* argv[]) { return 0; }