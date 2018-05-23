#include <iostream>
#include <vector>
#include <unordered_map>
#include <functional>
#include <algorithm>
#include <bitset>
#include <deque>

using namespace std;

class Solution {
public:
  int mySqrt(int x) {
    int low = 1, high = x;
    int64_t mid;
    while (low <= high) {
      mid = low + (high - low)/2;
      auto diff = mid*mid - x;
      if (diff > 0)
        high = mid - 1;
      else if (diff < 0)
        low = mid + 1;
      else
        return mid;
    }
    return high;
  }
};

// ref: newtown method
class Solution2 {
public:
  int mySqrt(int x) {
    long r = x;
    long a = x;
    while (r*r > a) {
      r = (r + a/r)/2;
    }
    return r;
  }
};

auto print = [](const auto &array) {
  std::for_each(std::begin(array), std::end(array), [](auto s) {
    cout << s << " ";
  });
  cout << '\n';
};

int main(int argc, char *argv[]) {
  Solution so;
  auto data = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 2147395599};
  for (auto i:data) {
    cout << so.mySqrt(i) << " ";
  }
  cout << '\n';
  return 0;
}