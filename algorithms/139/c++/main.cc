#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// what a pity: time limit exceeded
class Solution {
public:
  bool wordBreak(string s, vector<string> &wordDict) {
    if (s.empty())
      return true;
    for (auto &w: wordDict) {
      if (w.size() <= s.size() && w == s.substr(s.size() - w.size(), w.size())) {
        if (wordBreak(s.substr(0, s.size() - w.size()), wordDict))
          return true;
      }
    }
    return false;
  }
};

// classic DP
class Solution2 {
public:
  bool wordBreak(string s, vector<string> &wordDict) {
    vector<bool> table(s.size() + 1);
    table[0] = true;
    int MAX = -1;
    for (auto &s: wordDict)
      MAX = std::max(MAX, static_cast<int>(s.size()));
    auto contains = [&](const string &s) {
      for (auto const &w: wordDict)
        if (w == s) {
          return true;
        }
      return false;
    };
    for (int i = 1; i <= s.size(); ++i) {
      for (int j = i - 1; i - j <= MAX && j >= 0; --j) {
        if (table[j] && contains(s.substr(j, i - j))) {
          table[i] = true;
          break;
        }
      }
    }
    return table[s.size()];
  }
};

auto print = [](const auto &array) {
  std::for_each(std::begin(array), std::end(array), [](const auto &s) {
    cout << s << " ";
  });
  cout << '\n';
};

int main(int argc, char *argv[]) {
  Solution2 so;

  vector<string> dict = {"leet", "code"};
  cout << so.wordBreak("leetcode", dict) << '\n';

  vector<string> dict1 = {"apple", "pen"};
  cout << so.wordBreak("applepenapple", dict1) << '\n';

  vector<string> dict2 = {"cats", "dog", "sand", "and", "cat"};
  cout << so.wordBreak("catsandog", dict2) << '\n';

  // bug fix
  vector<string> dict3 = {"a", "abc", "b", "cd"};
  cout << so.wordBreak("abcd", dict3) << '\n';
  return 0;
}