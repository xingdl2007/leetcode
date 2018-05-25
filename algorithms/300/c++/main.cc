#include <iostream>
#include <vector>
#include <map>
#include <climits>
#include <algorithm>

using namespace std;

auto print = [](const auto &array) {
  std::for_each(std::begin(array), std::end(array), [](const auto &s) {
    cout << s << " ";
  });
  cout << '\n';
};

// first try: DP, time: O(n^2), space: O(n)
class Solution {
public:
  int lengthOfLIS(vector<int> &nums) {
    vector<int> lis(nums.size() + 1, 0);
    int res = 0;
    for (int i = 1; i <= nums.size(); ++i) {
      int count = 1;
      for (int j = i - 1; j > 0; --j) {
        // make sure increasing order
        if (nums[i - 1] > nums[j - 1]) {
          count = max(count, lis[j] + 1);
        }
      }
      lis[i] = count;
      res = max(res, count);
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  Solution so;
  vector<int> data{10, 9, 2, 5, 3, 7, 101, 18};
  cout << so.lengthOfLIS(data) << '\n';

  vector<int> data2{1, 3, 6, 7, 9, 4, 10, 5, 6};
  cout << so.lengthOfLIS(data2) << '\n';

  vector<int> data3 = {};
  cout << so.lengthOfLIS(data3) << '\n';
  return 0;
}