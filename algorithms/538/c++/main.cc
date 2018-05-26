#include <iostream>
#include <vector>
#include <climits>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <numeric>

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
  int convertBST(TreeNode *root, int delta) {
    if (root->right != nullptr)
      delta = convertBST(root->right, delta);
    delta = root->val += delta;
    if (root->left != nullptr)
      delta = convertBST(root->left, delta);
    return delta;
  }
  TreeNode *convertBST(TreeNode *root) {
    if (root == nullptr)
      return root;
    convertBST(root, 0);
    return root;
  }
};

// same as Solution1, but more elegant
class Solution2 {
private:
  int sum = 0;
public:
  TreeNode *convertBST(TreeNode *root) {
    if (root != nullptr) {
      convertBST(root->right);
      sum = root->val += sum;
      convertBST(root->left);
    }
    return root;
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
  TreeNode n1(2);
  TreeNode n2(0);
  TreeNode n3(3);
  TreeNode n4(-4);
  TreeNode n5(1);

  n1.left = &n2;
  n1.right = &n3;
  n2.left = &n4;
  n2.right = &n5;

  auto *head = so.convertBST(&n1);
  cout << head->val << " " << head->left->val << " "
       << head->right->val << " " << head->left->left->val << " "
       << head->left->right->val << '\n';
  return 0;
}
