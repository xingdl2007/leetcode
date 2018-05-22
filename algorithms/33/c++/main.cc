#include <iostream>
#include <vector>
#include <functional>

using namespace std;

class Solution {
public:
  int worker(vector<int> &nums, int low, int high, int target) {
    if (low > high)
      return -1;
    int mid = low + (high - low)/2;
    if (target == nums[mid])
      return mid;

    if (nums[low] <= nums[mid]) {
      if (nums[low] <= target && target < nums[mid])
        return worker(nums, low, mid - 1, target);
      else
        return worker(nums, mid + 1, high, target);
    } else {
      if (nums[mid] < target && target <= nums[high]) {
        return worker(nums, mid + 1, high, target);
      } else
        return worker(nums, low, mid - 1, target);
    }
  }

  // basic method: tail recursive actually
  // efficiency: same as iterative
  int search(vector<int> &nums, int target) {
    return worker(nums, 0, nums.size() - 1, target);
  }
};

// ref
class Solution2 {
public:
  int search(vector<int> &nums, int target) {
    int n = nums.size();
    int l = 0, r = n - 1, mid;
    while (l <= r) {
      mid = (l + r)/2;
      if (nums[mid] == target)
        return mid;
      if (nums[l] <= nums[mid]) {
        if (target < nums[mid] && target >= nums[l])
          r = mid - 1;
        else
          l = mid + 1;
      } else if (nums[mid] <= nums[r]) {
        if (target > nums[mid] && target <= nums[r])
          l = mid + 1;
        else
          r = mid - 1;
      }
    }
    return -1;
  }
};

int main(int argc, char *argv[]) {
  Solution so;
  vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
  for (auto i: nums)
    cout << i << " -> " << so.search(nums, i) << '\n';
  cout << 3 << " -> " << so.search(nums, 3) << '\n';
  cout << 8 << " -> " << so.search(nums, 8) << '\n';
  return 0;
}