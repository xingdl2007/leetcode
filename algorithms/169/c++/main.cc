#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  int majorityElement(vector<int> &nums) {
    std::sort(nums.begin(), nums.end());
    return nums[nums.size()/2];
  }
};

// a better method
class Solution2 {
public:
  int majorityElement(vector<int> &nums) {
    int count = 1, maj = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] == maj)
        ++count;
      else if (--count == 0) {
        count = 1;
        maj = nums[i];
      }
    }
    return maj;
  }
};

auto print = [](const auto &array) {
  std::for_each(std::begin(array), std::end(array), [](const auto &s) {
    cout << s << " ";
  });
  cout << '\n';
};

int main(int argc, char *argv[]) {
  Solution2 so;
  vector<int> data = {2, 2, 1, 1, 1, 2, 2};
  cout << so.majorityElement(data) << '\n';
  return 0;
}