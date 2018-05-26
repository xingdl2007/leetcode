#include <iostream>
#include <vector>
#include <climits>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

// time limit exceeded
class Solution2 {
public:
  vector<int> findAnagrams(string s, string p) {
    if (s.size() < p.size())
      return {};
    vector<int> ret;
    sort(p.begin(), p.end());
    for (int i = 0; i <= s.size() - p.size(); ++i) {
      auto sub = s.substr(i, p.size());
      sort(sub.begin(), sub.end());
      if (sub == p) {
        ret.push_back(i);
      }
    }
    return ret;
  }
};

// ref: sliding window
class Solution {
public:
  vector<int> findAnagrams(string s, string p) {
    if (s.size() < p.size())
      return {};
    vector<int> golden(26, 0), window(26, 0), ret;
    for (int i = 0; i < p.size(); ++i) {
      ++golden[p[i] - 'a'];
      ++window[s[i] - 'a'];
    }
    if (window == golden)
      ret.push_back(0);
    for (auto i = 1; i <= s.size() - p.size(); ++i) {
      --window[s[i - 1] - 'a'];
      ++window[s[i + p.size() - 1] - 'a'];
      if (window == golden)
        ret.push_back(i);
    }
    return ret;
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
  print(so.findAnagrams("cbaebabacd", "abc"));
  print(so.findAnagrams("aaaaaaaaaaaaaaaaaaaaaaaa", "aa"));
  return 0;
}
