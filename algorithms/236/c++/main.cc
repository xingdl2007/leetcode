#include <iostream>
#include <vector>
#include <stack>
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

class Solution {
public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    stack<TreeNode *> v1, v2;
    TreeNode *common = root;
    if (path(v1, root, p) && path(v2, root, q)) {
      while (!v1.empty() && !v2.empty()) {
        if (v1.top() == v2.top()) {
          common = v1.top();
          v1.pop();
          v2.pop();
          continue;
        }
        break;
      }
    }
    return common;
  }

  bool path(stack<TreeNode *> &vec, TreeNode *root, TreeNode *n) {
    if (root == nullptr)
      return false;
    if (root == n || path(vec, root->left, n) || path(vec, root->right, n)) {
      vec.push(root);
      return true;
    }
    return false;
  }
};

// ref: interesting
class Solution2 {
public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (root == nullptr || p == root || q == root)
      return root;
    TreeNode *left = lowestCommonAncestor(root->left, p, q);
    TreeNode *right = lowestCommonAncestor(root->right, p, q);
    if (left && right)
      return root;
    return left ? left : right;
  }
};

auto print = [](TreeNode *head) {
  cout << head->val << '\n';
};

int main(int argc, char *argv[]) {
  Solution so;
  TreeNode t0(0);
  TreeNode t1(1);
  TreeNode t2(2);
  TreeNode t3(3);
  TreeNode t4(4);
  TreeNode t5(5);
  TreeNode t6(6);
  TreeNode t7(7);
  TreeNode t8(8);

  t3.left = &t5;
  t3.right = &t1;
  t5.left = &t6;
  t5.right = &t2;
  t2.left = &t7;
  t2.right = &t4;
  t1.left = &t0;
  t1.right = &t8;

  print(so.lowestCommonAncestor(&t3, &t5, &t1));
  print(so.lowestCommonAncestor(&t3, &t5, &t4));
  return 0;
}