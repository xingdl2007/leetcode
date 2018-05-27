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
  // path length single direction
  int path(TreeNode *root) {
    if (root == nullptr)
      return 0;
    return max(path(root->left), path(root->right)) + 1;
  }
  int diameterOfBinaryTree(TreeNode *root) {
    if (root == nullptr)
      return 0;
    return max(max(diameterOfBinaryTree(root->left),
                   diameterOfBinaryTree(root->right)),
               path(root->left) + path(root->right));
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
  TreeNode n1(1);
  TreeNode n2(2);
  TreeNode n3(3);
  TreeNode n4(4);
  TreeNode n5(5);

  n1.left = &n2;
  n1.right = &n3;
  n2.left = &n4;
  n2.right = &n5;
  cout << so.diameterOfBinaryTree(&n1) << '\n';
  return 0;
}
