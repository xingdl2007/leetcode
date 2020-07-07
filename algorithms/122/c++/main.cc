#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int profit = 0;
    for (int i = 0, j = 1; j < prices.size(); ++j) {
      if (prices[j] > prices[i]) {
        profit += prices[j] - prices[i];
      }
      i = j;
    }
    return profit;
  }
};

int main(int argc, char *argv[]) {
  Solution so;
  {
    vector<int> prices{7, 1, 5, 3, 6, 4};
    std::cout << so.maxProfit(prices) << std::endl;
  }

  {
    vector<int> prices{1, 2, 0, 4, 5};
    std::cout << so.maxProfit(prices) << std::endl;
  }

  {
    vector<int> prices{7, 6, 4, 3, 1};
    std::cout << so.maxProfit(prices) << std::endl;
  }
  return 0;
}