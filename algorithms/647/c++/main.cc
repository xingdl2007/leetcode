#include <iostream>
#include <vector>
#include <climits>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <numeric>

using namespace std;

// impressive!
class Solution {
public:
  int countSubstrings(string s) {
    int ret = 0, n = s.length();
    int palindromic[n][n];
    // b: begin; e: end
    for (int e = 0; e < n; ++e) {
      for (int b = 0; b <= e; ++b) {
        palindromic[b][e] = s[b] == s[e] && (e - b < 3 || palindromic[b + 1][e - 1]);
        if (palindromic[b][e])
          ++ret;
      }
    }
    return ret;
  }
};

int main(int argc, char *argv[]) {
  Solution so;
  cout << so.countSubstrings("abc") << '\n';
  cout << so.countSubstrings("aaa") << '\n';
  return 0;
}
