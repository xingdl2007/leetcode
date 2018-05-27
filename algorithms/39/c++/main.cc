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
  vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    vector<vector<vector<int>>> dp(target + 1);
    dp[0].push_back({});
    for (auto &c: candidates) {
      for (int j = 1; j <= target; ++j) {
        if (j < c)
          continue;
        auto copy = dp[j - c];
        for (auto &vec: copy) {
          vec.push_back(c);
          dp[j].push_back(std::move(vec));
        }
      }
    }
    return dp[target];
  }
};

auto print = [](const auto &array) {
  for_each(array.begin(), array.end(), [](const auto &item) {
    cout << item << " ";
  });
  cout << '\n';
};

auto print2D = [](const auto &array) {
  for_each(array.begin(), array.end(), print);
};

int main(int argc, char *argv[]) {
  Solution so;
  vector<int> candidates{2, 3, 6, 7};
  print2D(so.combinationSum(candidates, 7));

  vector<int> candidates2{2, 3, 5};
  print2D(so.combinationSum(candidates2, 8));
  return 0;
}
