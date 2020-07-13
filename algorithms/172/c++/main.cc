#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// the following version is not right: 25 * 4 = 100, will add two zeros not one!
// 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
// 11,12,13,14,15,16,17,18,19,20
// 21,22,23,24,25,26,27,28,29,30

// simple thought: every 10 numbers will add 2 zeros, not right!
// wrong version, see 2/3
class Solution {
 public:
  int trailingZeroes(int n) {
    int ans = 0, lsd = n % 10, base = 2;
    n = n / 10;
    while (n) {
      ans += (n % 10) * base;
      n = n / 10;
      base *= 10;
    }
    ans += lsd >= 5 ? 1 : 0;
    return ans;
  }
};

// total number of zeros will be created by 2's and 5's and 2's count will
// always be greater than 5's count...total zeros will be equal to total 5's
// count.
class Solution2 {
 public:
  // we will increment it by multiples of 5 like 5,25,125....
  // and add 1,2,3.... correspondingly to count if number is
  // divisible by 5 multiple
  int trailingZeroes(int n) {
    int count = 0;
    long int i = 5;
    while (n / i > 0) {
      count += n / i;
      i *= 5;
    }
    return count;
  }
};

// clever
class Solution3 {
 public:
  int trailingZeroes(int n) {
    int count = 0;
    while (n) {
      n /= 5;
      count += n;
    }
    return count;
  }
};

int main(int argc, char* argv[]) {
  Solution3 so;
  std::cout << so.trailingZeroes(30) << std::endl;
  std::cout << so.trailingZeroes(123) << std::endl;
  return 0;
}