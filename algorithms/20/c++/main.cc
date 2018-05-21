#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
  // matched '()', '[]', '{}'
  bool isMatch(char l, char r) {
    return (l == '(' && r == ')') ||
        (l == '[' && r == ']') ||
        (l == '{' && r == '}');
  }
  bool isValid(string s) {
    stack<char> stk;
    for (auto c:s) {
      if (c == '(' || c == '[' || c == '{')
        stk.push(c);
      else if (!stk.empty() && isMatch(stk.top(), c)) {
        stk.pop();
      } else
        return false;
    }
    return stk.empty();
  }
};

int main(int argc, char *argv[]) {
  Solution so;
  auto data = {string("]"), string("()"), string("()[]{}"), string("(]"), string("([)]"), string("{[]}")};
  for (const auto &s:data) {
    cout << s << " " << so.isValid(s) << '\n';
  }
  return 0;
}