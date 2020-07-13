#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
 public:
  bool isPowerOfFour(int num) {
    if (num < 1) return false;

    // is power of two?
    if ((num & (num - 1)) != 0) return false;

    // find bit position, which must be even
    for (int i = 0; i < 31; ++i) {
      if ((1 << i) == num) {
        return i % 2 == 0;
      }
    }
    return false;
  }
};

// mod 3 must be zero, interesting
class Solution2 {
 public:
  bool isPowerOfFour(int num) {
    return num > 0 && !(num & (num - 1)) && (num - 1) % 3 == 0;
  }
};

int main(int argc, char* argv[]) {
  Solution so;
  std::cout << so.isPowerOfFour(5) << std::endl;
  std::cout << so.isPowerOfFour(16) << std::endl;
  std::cout << so.isPowerOfFour(256) << std::endl;
  return 0;
}