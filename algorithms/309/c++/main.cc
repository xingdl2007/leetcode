#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;

auto print = [](const auto &array) {
  std::for_each(std::begin(array), std::end(array),
                [](const auto &s) { cout << s << " "; });
  cout << '\n';
};

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/discuss/75928/Share-my-DP-solution-(By-State-Machine-Thinking)
class Solution {
public:
  int maxProfit(vector<int> &prices) {
    if (prices.empty())
      return 0;
    vector<int> s0(prices.size(), 0), s1(prices.size(), 0),
        s2(prices.size(), 0);
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

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/discuss/75927/Share-my-thinking-process

// See the comment:
// This is a great thinking process.
// Actually, I was also initially confused by the buy[i] and sell[i] definitions
// as many posted here. Actually, I think it is clear to just look at the
// simplified equations without rest state (which does not impact profit anyway)

// buy[i] = max(sell[i-2]-price, buy[i-1])
// sell[i] = max(buy[i-1]+price, sell[i-1])
// Now the definitions are clear.

// buy[i] is the max profit up to day i with buy as last action;
// sell[i] is the max profit up to day i with sell as last action.
// Note that rest is not considered as an action, and the last action could
// happen in any day up to day i. Therefore, it is natural to say for buy[i], if
// the last buy didn't happen on day i, max profit is simply buy[i-1];
// otherwise, a sell must happen at least 2 days ago (and no actions in
// between), so sell[i-2]-price.

// And if we generalize the problem to have k cool down days:
// buy[i] = max(sell[i-k-1]-price, buy[i-1])
// sell[i] = max(buy[i-1]+price, sell[i-1])

// naive version
class Solution2 {
public:
  int maxProfit(vector<int> &prices) {
    if (prices.empty())
      return 0;
    vector<int> buy(prices.size(), 0), sell(prices.size(), 0);
    buy[0] = -prices[0];
    for (int i = 1; i < prices.size(); ++i) {
      sell[i] = max(buy[i - 1] + prices[i], sell[i - 1]);
      if (i > 2) {
        buy[i] = max(buy[i - 1], sell[i - 2] - prices[i]);
      } else {
        buy[i] = max(buy[i - 1], -prices[i]);
      }
    }
    return sell[prices.size() - 1];
  }
};

// optimiazed version
class Solution3 {
public:
  int maxProfit(vector<int> &prices) {
    int buy(INT_MIN), sell(0), prev_sell(0), prev_buy;
    for (int price : prices) {
      prev_buy = buy;
      buy = max(prev_sell - price, buy);
      prev_sell = sell;
      sell = max(prev_buy + price, sell);
    }
    return sell;
  }
};

int main(int argc, char *argv[]) {
  Solution so;
  Solution2 so2;
  vector<int> prices = {1, 2, 3, 0, 2};
  cout << so.maxProfit(prices) << " " << so2.maxProfit(prices) << std::endl;

  vector<int> prices2 = {0, 1, 2, 3, 4, 5, 6, 7};
  cout << so.maxProfit(prices2) << " " << so2.maxProfit(prices2) << std::endl;

  vector<int> prices3 = {2, 1, 4};
  cout << so.maxProfit(prices3) << " " << so2.maxProfit(prices3) << std::endl;

  return 0;
}