#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

auto print = [](const auto &array) {
  std::for_each(std::begin(array), std::end(array), [](const auto &s) {
    cout << s << " ";
  });
  cout << '\n';
};

// ref: DP based, interesting and clever!
class Solution {
public:
  int maxProfit(vector<int> &prices) {
    if (prices.empty())
      return 0;
    vector<int> s0(prices.size(), 0), s1(prices.size(), 0), s2(prices.size(), 0);
    s0[0] = s2[0] = 0;
    s1[0] = -prices[0];
    for (int i = 1; i < prices.size(); ++i) {
      s0[i] = max(s0[i - 1], s2[i - 1]);
      s1[i] = max(s1[i - 1], s0[i - 1] - prices[i]);
      s2[i] = s1[i - 1] + prices[i];
    }
    return max(s0[prices.size() - 1], s2[prices.size() - 1]);
  }
};

int main(int argc, char *argv[]) {
  Solution so;
  vector<int> prices = {1, 2, 3, 0, 2};
  cout << so.maxProfit(prices) << '\n';
  vector<int> prices2 = {0, 1, 2, 3, 4, 5, 6, 7};
  cout << so.maxProfit(prices2) << '\n';
  return 0;
}