#include <iostream>
#include <vector>
#include <map>
#include <climits>
#include <algorithm>

using namespace std;

// key: filter out impossible check
class Solution {
public:
  int numSquares(int n) {
    vector<int> nums(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
      int step = n;
      for (int j = 1; j*j <= i; ++j) {
        step = min(step, nums[i - j*j] + 1);
      }
      nums[i] = step;
    }
    return nums[n];
  }
};

// ref
class Solution2 {
public:
  int numSquares(int n) {
    static vector<int> dp{0};
    while (dp.size() <= n) {
      int squares = INT_MAX;
      for (int i = 1; i*i <= dp.size(); i++)
        squares = min(squares, dp[dp.size() - i*i] + 1);
      dp.push_back(squares);
    }
    return dp[n];
  }
};

int main(int argc, char *argv[]) {
  Solution so;
  cout << so.numSquares(1) << '\n';
  cout << so.numSquares(2) << '\n';
  cout << so.numSquares(3) << '\n';
  cout << so.numSquares(4) << '\n';
  cout << so.numSquares(12) << '\n';
  cout << so.numSquares(13) << '\n';
  cout << so.numSquares(6616) << '\n';
  return 0;
}