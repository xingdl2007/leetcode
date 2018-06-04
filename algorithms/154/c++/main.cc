#include <iostream>
#include <vector>
#include <functional>

using namespace std;

// duplicate is harmful
class Solution {
public:
  int findMin(vector<int> &nums, int low, int high) {
    int min = nums[low];
    for (int i = low + 1; i < high; ++i) {
      if (nums[i] < min)
        min = nums[i];
    }
    return min;
  }

  int findMin(vector<int> &nums) {
    int low = 0, high = nums.size() - 1, mid = low;
    while (low < high && nums[low] >= nums[high]) {
      if (high == low + 1) {
        mid = high;
        break;
      }
      mid = low + (high - low)/2;
      if (nums[low] == nums[mid] && nums[mid] == nums[high])
        return findMin(nums, low, high);
      if (nums[mid] >= nums[low])
        low = mid;
      else
        high = mid;
    }
    return nums[mid];
  }
};

//Binary Search in Sorted Rotated Array
//Implemented using following idea: One half has to be sorted
class Solution2 {
public:
  int findMin(vector<int> &nums) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
      while (nums[left] == nums[right] && left != right) {
        left++;
      }
      if (nums[left] <= nums[right])
        return nums[left];
      int mid = (left + right)/2;
      if (nums[left] <= nums[mid])
        left = mid + 1;
      else
        right = mid;
    }
    return -1;
  }
};

int main(int argc, char *argv[]) {
  Solution so;
  vector<int> data = {2, 0, 1, 2, 2, 2};
  cout << so.findMin(data) << '\n';
  return 0;
}