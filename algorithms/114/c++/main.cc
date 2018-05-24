#include <iostream>
#include <vector>
#include <stack>
#include <utility>
#include <algorithm>
#include <tuple>
#include <map>

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
  void flatten(TreeNode *root) {
    if (root == nullptr)
      return;
    flatten(root->left);
    flatten(root->right);

    if (root->left) {
      auto last = root->left;
      while (last->right)
        last = last->right;
      last->right = root->right;
      root->right = root->left;
      root->left = nullptr;
    }
  }
};

auto print = [](TreeNode *root) {
  while (root) {
    cout << root->val << " ";
    root = root->right;
  }
  cout << '\n';
};

int main(int argc, char *argv[]) {
  Solution so;
  TreeNode n1{1};
  TreeNode n2{2};
  TreeNode n3{3};
  TreeNode n4{4};
  TreeNode n5{5};
  TreeNode n6{6};

  // 1
  so.flatten(&n1);
  print(&n1);

  // 1 2
  n1.left = &n2;
  so.flatten(&n1);
  print(&n1);

  // 1 2 3
  n1.left = &n2;
  n1.right = &n3;
  so.flatten(&n1);
  print(&n1);

  // 1 2 3 4 5 6
  n1.left = &n2;
  n1.right = &n5;
  n2.left = &n3;
  n2.right = &n4;
  n5.right = &n6;
  so.flatten(&n1);
  print(&n1);
  return 0;
}