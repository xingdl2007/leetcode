#include <iostream>

class Solution {
public:
  // x is positive only
  int64_t reverse(int x) {
    int64_t ret = 0;
    while (x) {
      ret = 10 * ret + x % 10;
      x = x / 10;
    }
    return ret;
  }

  bool isPalindrome(int x) {
    if (x < 0)
      return false;
    else
      return x == reverse(x);
  }
};

//  optimized solution
class Solution2 {
public:
  bool isPalindrome(int x) {
    if (x < 0 || (x % 10 == 0 && x != 0))
      return false;

    int half_reverse = 0;
    while (x > half_reverse) {
      half_reverse = 10 * half_reverse + x % 10;
      x = x / 10;
    }
    return x == half_reverse || x == half_reverse / 10;
  }
};

int main() {
  Solution s;

  std::cout << s.reverse(10) << std::endl;
}