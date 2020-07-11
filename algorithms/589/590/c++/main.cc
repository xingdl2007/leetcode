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
  vector<Node*> children;

  Node() {}

  Node(int _val) { val = _val; }

  Node(int _val, vector<Node*> _children) {
    val = _val;
    children = _children;
  }
};

class Solution {
 public:
  void traverse(Node* root, vector<int>& vals) {
    if (root == nullptr) return;
    for (auto c : root->children) {
      traverse(c, vals);
    }

    vals.push_back(root->val);
  }

  vector<int> postorder(Node* root) {
    vector<int> ret;
    traverse(root, ret);
    return ret;
  }
};

int main(int argc, char* argv[]) {
  Solution so;

  return 0;
}