#include <iostream>
#include <vector>
#include <climits>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <numeric>

using namespace std;

// first with backtrack, basically brute force
// pity: time limit exceeded
class Solution {
public:
  int Sum(vector<int> &nums, vector<int> &symbol) {
    int sum = 0;
    for (int i = 0; i < symbol.size(); ++i) {
      if (symbol[i] == 1)
        sum += nums[i];
      else if (symbol[i] == 2)
        sum -= nums[i];
    }
    return sum;
  }

  int findTargetSumWays(vector<int> &nums, int S) {
    int count = 0, k = 0, N = nums.size(), M = 3; // 1: '+', 2: '-'
    vector<int> symbol(N);
    while (k >= 0 && k != N) {
      symbol[k]++;
      if (symbol[k] == M) {
        symbol[k] = 0;
        --k;
        continue;
      }
      ++k;
      if (k == N) {
        if (Sum(nums, symbol) == S) {
          ++count;
        }
        --k;
      }
    }
    return count;
  }
};

// impressive
class Solution1 {
public:
  int findTargetSumWays(vector<int> &nums, int S) {
    auto n = nums.size();
    vector<unordered_map<int, int>> dp(n + 1);
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
      for (auto &a : dp[i - 1]) {
        int sum = a.first, cnt = a.second;
        dp[i][sum + nums[i - 1]] += cnt;
        dp[i][sum - nums[i - 1]] += cnt;
      }
    }
    return dp[n][S];
  }
};

// based DP: Good idea to convert this problem to the classic 0-1 knapsack problem. :)
class Solution2 {
public:
  int findTargetSumWays(vector<int> &nums, int s) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum < s || (s + sum & 1))
      return 0;
    int target = (s + sum) >> 1;

    vector<int> dp(target + 1, 0);
    dp[0] = 1;

    for (int i = 0; i < nums.size(); i++) {
      for (int t = target; t >= nums[i]; t--) {
        dp[t] += dp[t - nums[i]];
      }
    }
    return dp[target];
  }
};

// subset sum problem
class Solution3 {
public:
  int findTargetSumWays(vector<int> &nums, int s) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    return sum < s || (s + sum) & 1 ? 0 : subsetSum(nums, (s + sum) >> 1);
  }

  int subsetSum(vector<int> &nums, int s) {
    int dp[s + 1] = {0};
    dp[0] = 1;
    for (int n : nums)
      for (int i = s; i >= n; i--)
        dp[i] += dp[i - n];
    return dp[s];
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
  vector<int> data = {1, 1, 1, 1, 1};
  cout << so.findTargetSumWays(data, 3) << '\n';

  vector<int> data2 = {7, 46, 36, 49, 5, 34, 25, 39, 41, 38, 49, 47, 17, 11, 1, 41, 7, 16, 23, 13};
  cout << so.findTargetSumWays(data2, 3) << '\n';
  return 0;
}
