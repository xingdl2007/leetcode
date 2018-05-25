#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

auto print = [](const auto &array) {
  std::for_each(std::begin(array), std::end(array), [](const auto &s) {
    cout << s << " ";
  });
  cout << '\n';
};

class Solution {
public:
  int coinChange(vector<int> &coins, int amount) {
    vector<int> count(amount + 1, amount + 1);
    count[0] = 0;
    for (int i = 1; i <= amount; ++i) {
      for (const auto &coin: coins) {
        if (coin <= i) {
          count[i] = min(count[i], count[i - coin] + 1);
        }
      }
    }
    return count[amount] > amount ? -1 : count[amount];
  }
};

int main(int argc, char *argv[]) {
  Solution so;
  vector<int> coins = {1, 3, 10, 25};
  cout << so.coinChange(coins, 30) << '\n';

  vector<int> coins2 = {1, 2, 5};
  cout << so.coinChange(coins2, 11) << '\n';

  vector<int> coins3 = {2};
  cout << so.coinChange(coins3, 3) << '\n';
  return 0;
}