#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  vector<int> searchRange(vector<int> &nums, int target) {
    int low = 0, high = nums.size() - 1, left = -1, right = -1;
    while (low <= high) {
      int mid = low + (high - low)/2;
      if (target < nums[mid])
        high = mid - 1;
      else if (target > nums[mid])
        low = mid + 1;
      else {
        // target == nums[mid]
        // always find left first
        if (left == -1) {
          if (mid == 0 || nums[mid - 1] != target) {
            left = mid;
            right = left;
            low = left + 1;
            high = nums.size() - 1;
          } else
            high = mid - 1;
        } else {
          if (mid == nums.size() || nums[mid + 1] != target) {
            right = mid;
            break;
          } else
            low = mid + 1;
        }
      }
    }
    return {left, right};
  }
};

int main(int argc, char *argv[]) {
  Solution so;
  vector<int> data{5, 7, 7, 8, 8, 10};
  auto print = [](const vector<int> &array) {
    std::for_each(std::begin(array), std::end(array), [](int n) {
      cout << n << " ";
    });
    cout << '\n';
  };
  print(so.searchRange(data, 8));
  print(so.searchRange(data, 6));
  print(so.searchRange(data, 5));

  // bug fix
  vector<int> data2{1};
  print(so.searchRange(data2, 1));
  return 0;
}