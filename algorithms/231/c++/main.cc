#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
 public:
  bool isPowerOfTwo(int n) {
    if (n < 1) return false;
    return (n & (n - 1)) == 0;
  }
};

int main(int argc, char* argv[]) {
  Solution so;
  return 0;
}