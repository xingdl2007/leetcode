#include <iostream>
#include <vector>
#include <climits>
#include <map>
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

// pity: too slow, 1336ms
class Solution {
public:
  int robParent(TreeNode *root) {
    if (root == nullptr)
      return 0;
    return root->val + robNoParent(root->left) + robNoParent(root->right);
  }
  int robNoParent(TreeNode *root) {
    if (root == nullptr)
      return 0;
    return rob(root->left) + rob(root->right);
  }

  int rob(TreeNode *root) {
    if (root == nullptr)
      return 0;
    return max(robParent(root), robNoParent(root));
  }
};

// how to improve? eliminate redundant computation
// 18ms
class Solution2 {
public:
  int robParent(TreeNode *root, map<TreeNode *, int> &cache) {
    if (root == nullptr)
      return 0;
    return root->val + robNoParent(root->left, cache) + robNoParent(root->right, cache);
  }
  int robNoParent(TreeNode *root, map<TreeNode *, int> &cache) {
    if (root == nullptr)
      return 0;
    return robWorker(root->left, cache) + robWorker(root->right, cache);
  }

  int robWorker(TreeNode *root, map<TreeNode *, int> &cache) {
    if (root == nullptr)
      return 0;
    if (cache.count(root))
      return cache[root];
    auto ret = max(robParent(root, cache), robNoParent(root, cache));
    cache[root] = ret;
    return ret;
  }

  int rob(TreeNode *root) {
    map<TreeNode *, int> cache;
    return robWorker(root, cache);
  }
};

// ref: why so fast? 10ms, just visit each node once
class Solution3 {
public:
  int rob(TreeNode *root) {
    return robDFS(root).second;
  }
  pair<int, int> robDFS(TreeNode *node) {
    if (!node)
      return {0, 0};
    auto l = robDFS(node->left), r = robDFS(node->right);
    auto f1 = l.second + r.second;        // Do not rob node
    auto f2 = max(f1, l.first + r.first + node->val);  // rob node if necessary
    return {f1, f2};
  }
};

int main(int argc, char *argv[]) {
  Solution2 so;
  {
    TreeNode n1(3);
    TreeNode n2(2);
    TreeNode n3(3);
    TreeNode n4(3);
    TreeNode n5(1);
    n1.left = &n2;
    n1.right = &n3;
    n2.right = &n4;
    n3.right = &n5;
    cout << so.rob(&n1) << '\n';
  }
  {
    TreeNode n1(3);
    TreeNode n2(4);
    TreeNode n3(5);
    TreeNode n4(1);
    TreeNode n5(3);
    TreeNode n6(1);
    n1.left = &n2;
    n1.right = &n3;
    n2.left = &n4;
    n2.right = &n5;
    n3.right = &n6;
    cout << so.rob(&n1) << '\n';
  }
  return 0;
}