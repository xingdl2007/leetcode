#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int maxProfit(vector<int> &prices) { return 0; }
};

int main(int argc, char *argv[]) {
  Solution so;
  {
    vector<int> prices{3, 3, 5, 0, 0, 3, 1, 4};
    std::cout << so.maxProfit(prices) << std::endl;
  }

  {
    vector<int> prices{1, 2, 3, 4, 5};
    std::cout << so.maxProfit(prices) << std::endl;
  }

  {
    vector<int> prices{7, 6, 4, 3, 1};
    std::cout << so.maxProfit(prices) << std::endl;
  }
  return 0;
}