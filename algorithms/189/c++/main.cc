#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
 public:
  void rotate(vector<int>& nums, int k) {
    std::vector<int> ans;
    // caution: k must less than size!
    const int size = nums.size(), idx = size - (k % size);
    for (int i = 0; i < size; ++i) {
      ans.push_back(nums[(idx + i) % size]);
    }
    nums = ans;
  }
};

int main(int argc, char* argv[]) {
  Solution so;
  return 0;
}