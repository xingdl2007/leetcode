#include <iostream>
#include <vector>
#include <unordered_map>
#include <functional>
#include <algorithm>
#include <bitset>
#include <deque>

using namespace std;

// may be big int, can't hold in int
class Solution {
public:
  vector<int> plusOne(vector<int> &digits) {
    deque<int> ret;
    int carry = 0;
    for (int i = digits.size() - 1; i >= 0; --i) {
      int sum = (i == digits.size() - 1) ? digits[i] + 1 : digits[i] + carry;
      ret.push_front(sum%10);
      carry = sum/10;
    }
    if (carry)
      ret.push_front(carry);
    return vector<int>(ret.begin(), ret.end());
  }
};

auto print = [](const auto &array) {
  std::for_each(std::begin(array), std::end(array), [](auto s) {
    cout << s << " ";
  });
  cout << '\n';
};

int main(int argc, char *argv[]) {
  Solution so;
  vector<int> data = {9, 9, 9, 9, 9, 9, 9};
  print(data);
  print(so.plusOne(data));
  return 0;
}