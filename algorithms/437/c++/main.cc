#include <iostream>
#include <vector>
#include <climits>
#include <unordered_map>
#include <queue>
#include <algorithm>

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

// not quite easy
class Solution {
public:
  // adjacent nodes from root
  int count(TreeNode *root, int sum) {
    int cnt = 0;
    if (root == nullptr)
      return 0;
    if (root->val == sum)
      cnt++;
    return cnt + count(root->left, sum - root->val) +
        count(root->right, sum - root->val);
  }
  int pathSum(TreeNode *root, int sum) {
    if (root == nullptr)
      return 0;
    return pathSum(root->left, sum) + pathSum(root->right, sum) +
        count(root, sum);
  };
};

int main(int argc, char *argv[]) {
  Solution so;
  TreeNode n1(10);
  TreeNode n2(5);
  TreeNode n3(-3);
  TreeNode n4(3);
  TreeNode n5(2);
  TreeNode n6(11);
  TreeNode n7(3);
  TreeNode n8(-2);
  TreeNode n9(1);

  n1.left = &n2;
  n1.right = &n3;
  n2.left = &n4;
  n2.right = &n5;
  n3.right = &n6;
  n4.left = &n7;
  n4.right = &n8;
  n5.right = &n9;
  cout << so.pathSum(&n1, 8) << '\n';
  return 0;
}
