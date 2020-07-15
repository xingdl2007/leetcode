#include <string.h>
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

#include <limits.h>

using namespace std;

class Solution {
 public:
  // reverse
  vector<vector<int>> permute(vector<int>& nums) {
    if (nums.empty()) return {};
    vector<vector<int>> ans;
    doPermute(ans, nums, 0, nums.size() - 1);
    return ans;
  }

 private:
  void swap(vector<int>& nums, int i, int j) {
    int tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
  }

  void doPermute(vector<vector<int>>& ans, vector<int>& nums, int first,
                 int last) {
    if (first > last) {
      ans.push_back(nums);  // when over, we get an permutation
      return;
    }
    for (int i = first; i <= last; ++i) {
      swap(nums, first, i);
      doPermute(ans, nums, first + 1, last);
      swap(nums, first, i);
    }
  }
};

int main(int argc, char* argv[]) {
  Solution so;
  vector<int> data{1, 2, 3};
  auto ans = so.permute(data);
  for (auto& p : ans) {
    for (auto& v : p) {
      std::cout << v << " ";
    }
    std::cout << std::endl;
  }
  return 0;
}