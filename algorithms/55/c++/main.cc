#include <iostream>
#include <vector>
#include <unordered_map>
#include <functional>
#include <algorithm>
#include <bitset>

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
  std::for_each(std::begin(array), std::end(array), [](string s) {
    cout << s << " ";
  });
  cout << '\n';
};

int main(int argc, char *argv[]) {
  Solution2 so;
  vector<int> data{2, 3, 1, 1, 4};
  cout << so.canJump(data) << '\n';

  vector<int> data2{3, 2, 1, 0, 4};
  cout << so.canJump(data2) << '\n';
  return 0;
}