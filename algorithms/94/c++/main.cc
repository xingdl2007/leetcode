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

// recursive
class Solution {
public:
  void traversal(vector<int> &vec, TreeNode *n) {
    if (n == nullptr)
      return;
    traversal(vec, n->left);
    vec.push_back(n->val);
    traversal(vec, n->right);
  }
  vector<int> inorderTraversal(TreeNode *root) {
    vector<int> vec;
    traversal(vec, root);
    return vec;
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
  TreeNode t1{1};
  TreeNode t2{2};
  TreeNode t3{3};
  t1.right = &t2;
  t2.left = &t3;
  print(so.inorderTraversal(&t1));
  return 0;
}