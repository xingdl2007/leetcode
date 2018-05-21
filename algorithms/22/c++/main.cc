#include <iostream>
#include <vector>
#include <stack>
#include <functional>

using namespace std;

// brute force actually
class Solution {
public:
  vector<string> generateParenthesis(int n) {
    if (n <= 0)
      return {};
    auto isValid = [](const string &s) {
      if (s.empty() || s[0] != '(' || s[s.size() - 1] != ')')
        return false;
      std::stack<char> stk;
      for (auto &c: s) {
        if (c == '(')
          stk.push(c);
        else {
          if (stk.empty())
            return false;
          stk.pop();
        }
      }
      return stk.empty();
    };
    vector<string> res;
    // 0 means '(', 1 means ')'
    vector<int> index(n*2, -1);
    auto build = [&]() {
      string s(2*n, ' ');
      for (int i = 0; i < 2*n; ++i) {
        s[i] = index[i] == 0 ? '(' : ')';
      }
      return s;
    };

    // generate all combinations
    int pos = 0;
    while (pos >= 0) {
      while (pos >= 0 && pos != 2*n) {
        ++index[pos];
        if (index[pos] == 2) {
          index[pos] = -1;
          --pos;
          continue;
        }
        ++pos;
      }
      if (pos == 2*n) {
        auto s = build();
        if (isValid(s))
          res.push_back(std::move(s));
        --pos;
      }
    }
    return res;
  }
};

// better and elegant
class Solution2 {
public:
  vector<string> generateParenthesis(int n) {
    vector<string> ret;
    std::function<void(string s, int left, int right, int n)> backtrack;
    backtrack = [&](string s, int left, int right, int n) {
      if (s.length() == n*2) {
        ret.push_back(std::move(s));
        return;
      }
      if (left < n)
        backtrack(s + "(", left + 1, right, n);
      if (right < left)
        backtrack(s + ")", left, right + 1, n);
    };
    backtrack("", 0, 0, n);
    return ret;
  }
};

int main(int argc, char *argv[]) {
  Solution so2;
  for (auto s: so2.generateParenthesis(3)) {
    cout << s << '\n';
  }
  return 0;
}