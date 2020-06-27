#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
  int searchInsert(vector<int> &nums, int target) {
    int low = 0, high = nums.size() - 1, mid;
    while (low <= high) {
      mid = (low + high) / 2;
      if (nums[mid] < target) {
        low = mid + 1;
      } else if (nums[mid] > target) {
        high = mid - 1;
      } else
        return mid;
    }

    // caution, side effect
    return low;
  }
};

int main(int argc, char *argv[]) {
  Solution so;

  vector<int> a{1, 3, 5, 6};
  std::cout << so.searchInsert(a, 5) << std::endl;
  std::cout << so.searchInsert(a, 2) << std::endl;
  std::cout << so.searchInsert(a, 7) << std::endl;
  std::cout << so.searchInsert(a, 0) << std::endl;

  vector<int> b{1};
  std::cout << so.searchInsert(b, 0) << std::endl;
  std::cout << so.searchInsert(b, 2) << std::endl;

  return 0;
}