#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

class Solution {
 public:
  int fold(std::stack<std::pair<char, int>>& op) {
    int sum = 0;
    while (!op.empty() && op.top().first == '#') {
      sum += op.top().second;
      op.pop();
    }
    return sum;
  }

  // more general
  int scoreOfParentheses(string S) {
    std::stack<std::pair<char, int>> op;
    for (auto c : S) {
      if (c == '(') {
        op.push({c, 0});
      } else {
        if (op.top().first == '(') {
          op.pop();  // pop "("
          op.push({'#', 1});
        } else {
          // must be '#'
          int sum = fold(op);
          op.pop();  // pop "("
          op.push({'#', sum * 2});
        }
      }
    }
    return fold(op);
  }
};

// same thought
class Solution2 {
 public:
  int scoreOfParentheses(string S) {
    stack<int> stk;
    for (char c : S) {
      if (c == '(') {
        stk.push(-1);
      } else {
        int cur = 0;
        while (stk.top() != -1) {
          cur += stk.top();
          stk.pop();
        }
        stk.pop();
        stk.push(cur == 0 ? 1 : cur * 2);
      }
    }
    int sum = 0;
    while (stk.size()) {
      sum += stk.top();
      stk.pop();
    }
    return sum;
  }
};

int main(int argc, char* argv[]) {
  Solution so;
  std::cout << so.scoreOfParentheses("()") << std::endl;
  std::cout << so.scoreOfParentheses("(())") << std::endl;
  std::cout << so.scoreOfParentheses("()()") << std::endl;
  std::cout << so.scoreOfParentheses("(()(()))") << std::endl;
  std::cout << so.scoreOfParentheses("()(())") << std::endl;
  return 0;
}