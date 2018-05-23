#include <iostream>
#include <vector>
#include <unordered_map>
#include <functional>
#include <algorithm>
#include <bitset>
#include <cmath>

using namespace std;

class Solution {
public:
  double myPow(double x, int n) {
    return std::pow(x, n);
  }
};

class Solution2 {
public:
  double myPow(double x, int n) {
    double res = 1;
    long absn = labs(n);
    while (absn > 0) {
      if ((absn & 1) != 0)
        res *= x;
      absn = absn >> 1;
      x *= x;
    }
    return n > 0 ? res : 1/res;
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
  return 0;
}