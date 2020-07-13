#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// seems not the best, but very similar with 125
class Solution {
 public:
  bool validPalindrome(string s) { return valid(s, true); }
  // allow deleted
  bool valid(string s, bool allow) {
    if (s.empty()) return true;
    int i = 0, j = s.size() - 1;
    while (i < j) {
      if (s[i] != s[j]) {
        if (!allow) return false;
        // how to choose which one to delete? try each
        return valid(s.substr(i, j - i), false) ||
               valid(s.substr(i + 1, j - i), false);
      }
      ++i;
      --j;
    }
    return true;
  }
};

int main(int argc, char* argv[]) {
  Solution so;
  std::cout << so.validPalindrome("aba") << std::endl;
  std::cout << so.validPalindrome("abca") << std::endl;
  std::cout << so.validPalindrome("abbca") << std::endl;
  std::cout << so.validPalindrome("abdcba") << std::endl;
  std::cout << so.validPalindrome("ebcbbececabbacecbbcbe") << std::endl;
  return 0;
}