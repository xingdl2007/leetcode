#include <algorithm>
#include <bitset>
#include <functional>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// holy shit: time limit exceed
// can not tolerate worst case : [25000, 24999, ... , 10, 9, 8, 7, 6, 5, 4, 3,
// 2, 1, 0]
class Solution {
public:
  int jump(vector<int> &nums) {
    vector<int> jumps(nums.size(), std::numeric_limits<int>::max());
    for (int i = nums.size() - 1; i >= 0; --i) {
      if (i == nums.size() - 1) {
        jumps[i] = 0;
        continue;
      }

      int j = i, count = nums[i], min = jumps[i + 1];
      if (count > 0) {
        // direct jump
        if (count >= nums.size() - 1 - i) {
          jumps[i] = 1;
          continue;
        }

        while (count-- > 0 && j < nums.size() - 1) {
          min = std::min(jumps[++j], min);
          // indirect jump, but only need once
          if (min == 1) {
            break;
          }
        }

        // may need jump more than once
        if (min != std::numeric_limits<int>::max())
          jumps[i] = min + 1;
        else
          jumps[i] = min;
      }
    }
    return jumps[0];
  }
};

// Basically, we visualize this as a greedy approach to get the best possible
// jump at every index. For this, we have a curtarget which is the number we can
// reach from prev iterations and the nexttarget which is the number we can
// reach from the current iteration. Whenever, our index == curtarget or if we
// reach the end, we update the jumps. And, also, we update the curtarget to the
// nexttarget which we computed in the current iteration.

// greedy
class Solution2 {
public:
  int jump(vector<int> &nums) {
    int cnt = 0;
    int curtarget = 0;
    int nexttarget = 0;

    if (nums.size() == 1)
      return 0;

    for (int i = 0; i < nums.size(); i++) {
      nexttarget = max(nexttarget, i + nums[i]);
      if (i == curtarget || nexttarget >= nums.size() - 1) {
        cnt++;
        curtarget = nexttarget;
      }
      if (nexttarget >= nums.size() - 1)
        return cnt;
    }
    return cnt;
  }
};

int main(int argc, char *argv[]) {
  Solution so;
  {
    vector<int> data{2, 3, 1, 1, 4};
    std::cout << so.jump(data) << std::endl;
  }

  {
    vector<int> data{10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    std::cout << so.jump(data) << std::endl;
  }

  return 0;
}