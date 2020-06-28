#include <algorithm>
#include <bitset>
#include <functional>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// greedy
class Solution {
public:
  bool canJump(vector<int> &nums) {
    if (nums.empty())
      return true;
    int step = nums[0], pos = 0;
    for (int i = 1; i < nums.size(); ++i) {
      if (step > 0) {
        ++pos;
        --step;
        step = nums[i] > step ? nums[i] : step;
      } else
        return false;
    }
    return pos == nums.size() - 1;
  }
};

// another little different
class Solution2 {
public:
  bool canJump(vector<int> &nums) {
    int lastpos = nums.size() - 1;
    for (int i = nums.size() - 1; i >= 0; --i) {
      if (i + nums[i] >= lastpos)
        lastpos = i;
    }
    return lastpos == 0;
  }
};

auto print = [](const auto &array) {
  std::for_each(std::begin(array), std::end(array),
                [](string s) { cout << s << " "; });
  cout << '\n';
};

int main(int argc, char *argv[]) {
  Solution2 so;
  Solution2 so2;
  vector<int> data{2, 3, 1, 1, 4};
  cout << so.canJump(data) << " " << so2.canJump(data) << '\n';

  vector<int> data2{3, 2, 1, 0, 4};
  cout << so.canJump(data2) << " " << so2.canJump(data2) << '\n';

  vector<int> data3{3, 2, 1, 0};
  cout << so.canJump(data3) << " " << so2.canJump(data3) << '\n';
  return 0;
}