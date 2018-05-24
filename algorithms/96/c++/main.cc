#include <iostream>
#include <vector>
#include <stack>
#include <utility>
#include <algorithm>
#include <tuple>
#include <map>

using namespace std;

class Solution {
public:
  int numTrees(int n) {
    vector<int> nums(n + 1, 0);
    nums[0] = 1;
    nums[1] = 1;
    for (int i = 2; i <= n; ++i) {
      for (int j = 1; j <= i; ++j) {
        nums[i] += nums[j - 1]*nums[i - j];
      }
    }
    return nums[n];
  }
};

// recusive: time limit exceed
// easy to understand
class Solution2 {
public:
  int numTrees(int n) {
    return trees(1, n);
  }
  int trees(int lo, int hi) {
    if (lo >= hi)
      return 1;
    int total = 0;
    for (int i = lo; i <= hi; ++i) {
      total += trees(lo, i - 1)*trees(i + 1, hi);
    }
    return total;
  }
};

auto print = [](const auto &array) {
  std::for_each(std::begin(array), std::end(array), [](const auto &s) {
    cout << s << " ";
  });
  cout << '\n';
};

int main(int argc, char *argv[]) {
  Solution so;
  cout << so.numTrees(0) << '\n';
  cout << so.numTrees(1) << '\n';
  cout << so.numTrees(2) << '\n';
  cout << so.numTrees(3) << '\n';
  cout << so.numTrees(4) << '\n';
  cout << so.numTrees(5) << '\n';
  return 0;
}