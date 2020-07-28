#include <algorithm>
#include <iostream>
#include <map>
#include <stack>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

// DP: holy shit, very clever !!
// https://leetcode.com/problems/unique-binary-search-trees/discuss/31706/Dp-problem.-10%2B-lines-with-comments

/**
 * Taking 1~n as root respectively:
 *      1 as root: # of trees = F(0) * F(n-1)  // F(0) == 1
 *      2 as root: # of trees = F(1) * F(n-2)
 *      3 as root: # of trees = F(2) * F(n-3)
 *      ...
 *      n-1 as root: # of trees = F(n-2) * F(1)
 *      n as root:   # of trees = F(n-1) * F(0)
 *
 * So, the formulation is:
 *      F(n) = F(0) * F(n-1) + F(1) * F(n-2) + F(2) * F(n-3) + ... + F(n-2) *
 * F(1) + F(n-1) * F(0)
 */
class Solution {
 public:
  int numTrees(int n) {
    vector<int> nums(n + 1, 0);
    nums[0] = 1;
    nums[1] = 1;
    for (int i = 2; i <= n; ++i) {
      for (int j = 1; j <= i; ++j) {
        nums[i] += nums[j - 1] * nums[i - j];
      }
    }
    return nums[n];
  }
};

// recusive: time limit exceed
// easy to understand
class Solution2 {
 public:
  int numTrees(int n) { return trees(1, n); }
  int trees(int lo, int hi) {
    if (lo >= hi) return 1;
    int total = 0;
    for (int i = lo; i <= hi; ++i) {
      total += trees(lo, i - 1) * trees(i + 1, hi);
    }
    return total;
  }
};

auto print = [](const auto &array) {
  std::for_each(std::begin(array), std::end(array),
                [](const auto &s) { cout << s << " "; });
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