#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
/**
 * Definition for a binary tree node. */
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
  vector<int> postorderTraversal(TreeNode *root) {}
};

int main(int argc, char *argv[]) {
  Solution so;
  return 0;
}