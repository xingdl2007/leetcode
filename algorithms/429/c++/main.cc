#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

/*
// Definition for a Node.
*/

class Node {
 public:
  int val;
  vector<Node *> children;

  Node() {}

  Node(int _val) { val = _val; }

  Node(int _val, vector<Node *> _children) {
    val = _val;
    children = _children;
  }
};

class Solution {
 public:
  void traverse(Node *root, vector<vector<int>> &vals, int level) {
    if (root == nullptr) return;
    if (vals.size() == level) vals.push_back({});

    vals[level].push_back(root->val);
    for (auto c : root->children) {
      traverse(c, vals, level + 1);
    }
  }

  vector<vector<int>> levelOrder(Node *root) {
    vector<vector<int>> vals;
    traverse(root, vals, 0);
    return vals;
  }
};

int main(int argc, char *argv[]) {
  Solution so;
  return 0;
}