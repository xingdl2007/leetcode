#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
/**
 * Definition for a binary tree node.
 */

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
 public:
  vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
    if (root == nullptr) return {};
    int level = 0;
    vector<vector<int>> ret;
    std::deque<TreeNode *> q1, q2;
    std::deque<TreeNode *> *cur = &q1, *nxt = &q2;
    cur->push_back(root);

    while (!q1.empty() || !q2.empty()) {
      if (level % 2 == 0) {
        cur = &q1;
        nxt = &q2;
      } else {
        cur = &q2;
        nxt = &q1;
      }

      std::vector<int> seqs;
      while (!cur->empty()) {
        auto node = *cur->begin();
        cur->pop_front();
        seqs.push_back(node->val);
        if (node->left != nullptr) nxt->push_back(node->left);
        if (node->right != nullptr) nxt->push_back(node->right);
      }

      if (level % 2 == 0) {
        ret.push_back(seqs);
      } else {
        std::reverse(seqs.begin(), seqs.end());
        ret.push_back(seqs);
      }
      ++level;
    }
    return ret;
  }
};

class Solution2 {
 public:
  void build(TreeNode *n, vector<vector<int>> &R, int d) {
    if (!n) return;
    if (d == R.size()) R.push_back(vector<int>());
    R[d].push_back(n->val);
    build(n->left, R, d + 1);
    build(n->right, R, d + 1);
  }

  vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
    vector<vector<int>> R;
    build(root, R, 0);
    for (int i = 1; i < R.size(); i += 2) reverse(R[i].begin(), R[i].end());
    return R;
  }
};

int main(int argc, char *argv[]) {
  Solution so;

  TreeNode n3(3);
  TreeNode n9(9);
  TreeNode n20(20);
  TreeNode n15(15);
  TreeNode n7(7);

  n3.left = &n9;
  n3.right = &n20;
  n20.left = &n15;
  n20.right = &n7;

  so.zigzagLevelOrder(&n3);
  return 0;
}