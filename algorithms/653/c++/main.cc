#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;

  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right){};
};

class Solution {
 public:
  bool findTarget(TreeNode* root, int k) {
    std::unordered_set<int> table;
    return traverse(root, k, table);
  }

  bool traverse(TreeNode* root, int k, std::unordered_set<int>& table) {
    if (root == nullptr) return false;
    if (table.count(root->val) == 1) return true;
    table.insert(k - root->val);
    return traverse(root->left, k, table) || traverse(root->right, k, table);
  }
};

int main(int argc, char* argv[]) {
  Solution so;
  return 0;
}