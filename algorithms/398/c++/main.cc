#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
 public:
  Solution(vector<int>& nums) { nums_ = nums; }

  int pick(int target) {
    int ans;

    for (int i = 0, cnt = 1; i < nums_.size(); i++) {
      if (nums_[i] == target && ((rand() % cnt++) == 0)) {
        ans = i;
      }
    }

    return ans;
  }

  vector<int> nums_;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
int main(int argc, char* argv[]) { return 0; }