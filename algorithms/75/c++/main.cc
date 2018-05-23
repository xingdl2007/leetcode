#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

class Solution {
public:
  void sortColors(vector<int> &nums) {
    int red = 0, white = 0, blue = 0;
    for (auto i: nums) {
      i == 0 ? red++ : (i == 1 ? white++ : blue++);
    }
    for (auto &i:nums) {
      if (red) {
        i = 0;
        --red;
      } else if (white) {
        i = 1;
        --white;
      } else if (blue) {
        i = 2;
        --blue;
      }
    }
  }
};

// ref: interesting
class Solution2 {
public:
  void sortColors(vector<int> &nums) {
    int l = 0, r = (int) nums.size() - 1;
    for (int i = 0; i <= r; ++i) {
      if (nums[i] == 0)
        std::swap(nums[l++], nums[i]);
      else if (nums[i] == 2) {
        std::swap(nums[r--], nums[i--]);
      }
    }
  }
};

auto print = [](const auto &array) {
  std::for_each(std::begin(array), std::end(array), [](auto s) {
    cout << s << " ";
  });
  cout << '\n';
};

int main(int argc, char *argv[]) {
  Solution so;
  vector<int> nums = {0, 1, 2, 2, 1, 0};
  so.sortColors(nums);
  print(nums);
  return 0;
}