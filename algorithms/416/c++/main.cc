#include <iostream>
#include <vector>
#include <climits>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
  bool canPartition(vector<int> &nums) {
    int sum = 0;
    for (auto &n: nums)
      sum += n;
    if (sum & 1)
      return false;

    int target = sum >> 1;
    int dp[target + 1] = {0};
    for (auto &n: nums) {
      for (int w = target; w >= n; --w) {
        dp[w] = max(dp[w], dp[w - n] + n);
      }
    }
    return dp[target] == target;
  }
};

class Solution2 {
public:
  bool canPartition(vector<int> &nums) {
    int sum = 0, n = nums.size();
    for (auto n : nums) {
      sum += n;
    }
    if (sum & 1)
      return false;
    int target = sum/2;
    vector<int> dp(target + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < n; ++i) {
      for (int j = target; j >= nums[i]; --j) {
        dp[j] += dp[j - nums[i]];
      }
    }
    return dp[target] != 0;
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
  vector<int> nums{1, 5, 11, 5};
  cout << so.canPartition(nums) << '\n';
  vector<int> nums2{1, 2, 3, 5};
  cout << so.canPartition(nums2) << '\n';
  return 0;
}
