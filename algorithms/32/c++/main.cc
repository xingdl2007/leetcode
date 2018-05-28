#include <iostream>
#include <stack>

using namespace std;

// impressive
class Solution {
public:
  int longestValidParentheses(string s) {
    int ret = 0;
    stack<int> half;
    half.push(-1);
    for (int i = 0; i < s.length(); ++i) {
      if (s[i] == '(')
        half.push(i);
      else {
        half.pop();
        if (half.empty()) {
          half.push(i);
        } else {
          ret = max(i - half.top(), ret);
        }
      }
    }
    return ret;
  }
};

int main(int argc, char *argv[]) {
  Solution so;
  cout << so.longestValidParentheses("(()") << '\n';
  cout << so.longestValidParentheses(")()())") << '\n';
  cout << so.longestValidParentheses("()(()") << '\n';
  return 0;
}