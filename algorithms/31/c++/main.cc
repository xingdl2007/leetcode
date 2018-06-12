#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

class Solution {
public:
  void nextPermutation(vector<int> &nums) {
    next_permutation(nums.begin(), nums.end());
  }
};

class Solution2 {
public:
  void nextPermutation(vector<int> &nums) {
    auto it = is_sorted_until(nums.rbegin(), nums.rend());
    if (it != nums.rend()) {
      swap(*it, *upper_bound(nums.rbegin(), it, *it));
    }
    reverse(nums.rbegin(), it);
  }
};

int main(int argc, char *argv[]) {
  Solution2 so;
  int a[] = {1, 2, 3};
  vector<int> nums(begin(a), end(a));
  so.nextPermutation(nums);
  copy(begin(nums), end(nums), ostream_iterator<int>(cout, " "));
  cout << '\n';
  return 0;
}