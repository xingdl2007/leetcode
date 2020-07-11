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
  void traverse(TreeNode *root, vector<vector<int>> &vals, int level) {
    if (root == nullptr) return;
    if (vals.size() == level) vals.push_back({});

    vals[level].push_back(root->val);
    traverse(root->left, vals, level + 1);
    traverse(root->right, vals, level + 1);
  }

  vector<vector<int>> levelOrder(TreeNode *root) {
    vector<vector<int>> vals;
    traverse(root, vals, 0);
    return vals;
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

  so.levelOrder(&n3);
  return 0;
}