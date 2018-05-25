#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

// very awesome and easy to understand!
// two pass
// 1. calculate product before this item
// 2. product all elements after this item
class Solution {
public:
  vector<int> productExceptSelf(vector<int> &nums) {
    vector<int> res(nums.size(), 1);
    res[0] = 1;
    for (int i = 1; i < nums.size(); ++i)
      res[i] = res[i - 1]*nums[i - 1];
    int right = 1;
    for (int i = nums.size() - 1; i >= 0; --i) {
      res[i] *= right;
      right *= nums[i];
    }
    return res;
  }
};

auto print = [](const auto &array) {
  for_each(begin(array), end(array), [](const auto &item) {
    cout << item << " ";
  });
  cout << '\n';
};

int main(int argc, char *argv[]) {
  Solution so;
  vector<int> data = {1, 2, 3, 4};
  print(so.productExceptSelf(data));
  return 0;
}