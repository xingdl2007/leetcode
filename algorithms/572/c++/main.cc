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

// pity: wrong answer
// implicitly assumption: no duplicate values
class Solution {
public:
  bool isIdentical(TreeNode *s, TreeNode *t) {
    if (s == nullptr && t == nullptr)
      return true;
    if (s == nullptr || t == nullptr)
      return false;
    return s->val == t->val && isIdentical(s->left, t->left)
        && isIdentical(s->right, t->right);
  }
  bool isSubtree(TreeNode *s, TreeNode *t) {
    if (s == nullptr && t == nullptr)
      return true;
    if (s == nullptr || t == nullptr)
      return false;
    return isIdentical(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t);
  }
};

int main(int argc, char *argv[]) {
  Solution so;
  TreeNode n1(3);
  TreeNode n2(4);
  TreeNode n3(5);
  TreeNode n4(1);
  TreeNode n5(2);

  n1.left = &n2;
  n1.right = &n3;
  n2.left = &n4;
  n2.right = &n5;

  TreeNode m1(4);
  TreeNode m2(1);
  TreeNode m3(2);
  TreeNode m4(0);
  m1.left = &m2;
  m1.right = &m3;

  cout << so.isSubtree(&n1, &m1) << '\n';
  m3.left = &m4;
  cout << so.isSubtree(&n1, &m1) << '\n';

  // duplicate
  TreeNode p1(1);
  TreeNode p2(1);
  TreeNode q1(1);
  p1.left = &p2;
  cout << so.isSubtree(&p1, &q1) << '\n';
  return 0;
}
