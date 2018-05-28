#include <iostream>

using namespace std;

// impressive, recursive version is elegant
class Solution {
public:
  bool isMatch(string s, string p) {
    if (p.empty())
      return s.empty();
    bool first_match = (!s.empty() && (s[0] == p[0] || p[0] == '.'));

    if (p.size() >= 2 && p[1] == '*') {
      return (isMatch(s, p.substr(2)) ||
          first_match && isMatch(s.substr(1), p));
    } else {
      return first_match && isMatch(s.substr(1), p.substr(1));
    }
  }
};

int main(int argc, char *argv[]) {
  Solution so;
  cout << so.isMatch("aa", "a") << '\n';
  cout << so.isMatch("aa", "a*") << '\n';
  cout << so.isMatch("ab", ".*") << '\n';
  cout << so.isMatch("aab", "c*a*b") << '\n';
  cout << so.isMatch("mississippi", "mis*is*p*.") << '\n';
  return 0;
}