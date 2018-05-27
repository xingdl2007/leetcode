#include <iostream>
#include <vector>
#include <climits>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <numeric>

using namespace std;

// impressive!!
class Solution {
public:
  int findUnsortedSubarray(vector<int> &nums) {
    int begin = 0, end = -1, mi = nums[nums.size() - 1], ma = nums[0];
    auto size = nums.size();
    for (int i = 0; i < size; ++i) {
      // reverse order
      if (nums[size - 1 - i] > mi)
        begin = size - 1 - i;
      else
        mi = min(mi, nums[size - 1 - i]);

      // sequential order
      if (nums[i] < ma)
        end = i;
      else
        ma = max(ma, nums[i]);
    }
    return end - begin + 1;
  }
};

int main(int argc, char *argv[]) {
  Solution so;
  vector<int> data = {2, 6, 4, 8, 10, 9, 15};
  cout << so.findUnsortedSubarray(data) << '\n';

  vector<int> data2 = {2, 6, 1, 16, 10, 9, 15};
  cout << so.findUnsortedSubarray(data2) << '\n';

  vector<int> data3 = {2};
  cout << so.findUnsortedSubarray(data3) << '\n';

  vector<int> data4 = {2, 1};
  cout << so.findUnsortedSubarray(data4) << '\n';

  vector<int> data5 = {1, 2, 3, 4};
  cout << so.findUnsortedSubarray(data5) << '\n';

  vector<int> data6 = {2, 3, 4, 1};
  cout << so.findUnsortedSubarray(data6) << '\n';

  vector<int> data7 = {4, 1, 2, 3};
  cout << so.findUnsortedSubarray(data7) << '\n';
  return 0;
}
