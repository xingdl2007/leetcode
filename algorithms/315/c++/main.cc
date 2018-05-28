#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

// O(N^2)
class Solution {
public:
  vector<int> countSmaller(vector<int> &nums) {
    vector<int> ret(nums.size(), 0);
    for (int i = 0; i < nums.size(); ++i) {
      int cnt = 0;
      for (int j = i + 1; j < nums.size(); ++j) {
        if (nums[j] < nums[i])
          ++cnt;
      }
      ret[i] = cnt;
    }
    return ret;
  }
};

auto print = [](const auto &array) {
  for_each(array.begin(), array.end(), [](const auto &item) {
    cout << item << " ";
  });
  cout << '\n';
};

// interesting: insert sort, O(n * log(n))
class Solution2 {
public:
  vector<int> countSmaller(vector<int> &nums) {
    auto n = nums.size();
    vector<int> res(n, 0);
    vector<int> sorted;
    for (int i = n - 1; i >= 0; i--) {
      auto it = lower_bound(sorted.begin(), sorted.end(), nums[i]);
      res[i] = it - sorted.begin();
      sorted.insert(it, nums[i]);
    }
    return res;
  }
};

int main(int argc, char *argv[]) {
  Solution2 so;
  vector<int> data = {5, 2, 6, 1};
  print(so.countSmaller(data));
  return 0;
}