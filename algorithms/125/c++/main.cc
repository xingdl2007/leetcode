#include <algorithm>
#include <cctype>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// just use `i<j` in every if condition
class Solution {
 public:
  bool isPalindrome(string s) {
    if (s.empty()) return true;
    int i = 0, j = s.size() - 1;
    while (i < j) {
      while (i < j && !std::isalnum(s[i])) {
        ++i;
      }
      while (i < j && !std::isalnum(s[j])) {
        --j;
      }
      if (std::tolower(s[i]) != std::tolower(s[j])) return false;
      ++i;
      --j;
    }
    return true;
  }
};

int main(int argc, char* argv[]) {
  Solution so;
  std::cout << so.isPalindrome("A man, a plan, a canal: Panama") << std::endl;
  std::cout << so.isPalindrome("race a car") << std::endl;
  std::cout << so.isPalindrome("   aba") << std::endl;
  std::cout << so.isPalindrome("   ") << std::endl;
  std::cout << so.isPalindrome(".,") << std::endl;
  return 0;
}