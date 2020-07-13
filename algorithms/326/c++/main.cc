#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
 public:
  bool isPowerOfThree(int n) {
    if (n < 1) return false;
    while (n % 3 == 0) {
      n = n / 3;
    }
    return n == 1;
  }
};

int main(int argc, char* argv[]) {
  Solution so;
  return 0;
}