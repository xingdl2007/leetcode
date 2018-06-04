#include <iostream>
#include <vector>
#include <functional>

using namespace std;

class Solution {
public:
  int findMin(vector<int> &nums) {
    int low = 0, high = nums.size() - 1, mid = low;
    while (low < high && nums[low] >= nums[high]) {
      if (high == low + 1)
        return nums[high];
      mid = low + (high - low)/2;
      if (nums[mid] > nums[low])
        low = mid;
      else
        high = mid;
    }
    return nums[mid];
  }
};

int main(int argc, char *argv[]) {
  Solution so;
  vector<int> data = {3, 4, 5, 0, 1, 2};
  cout << so.findMin(data) << '\n';
  return 0;
}