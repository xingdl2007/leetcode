#include <algorithm>
#include <bitset>
#include <deque>
#include <functional>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
class Solution {

public:
  char add(char left, char right, bool &carry) {
    char ret = '0';
    if (carry) {
      if (left == right) {
        ret = '1';
      } else {
        ret = '0';
        carry = true;
      }
    } else {
      if (left == right) {
        ret = '0';
      } else {
        ret = '1';
        carry = false;
      }
    }

    // common
    if (left == right) {
      if (left == '0') {
        carry = false;
      } else {
        carry = true;
      }
    }
    return ret;
  }

  string addBinary(string a, string b) {
    size_t len = std::max(b.size(), a.size());
    string ret(len, '0');
    bool carry = false;

    for (int idx = 0; idx < len; ++idx) {

      // all have
      if (a.size() > idx && b.size() > idx) {
        char left = a[a.size() - idx - 1];
        char right = b[b.size() - idx - 1];
        ret[len - 1 - idx] = add(left, right, carry);
        continue;
      }

      // a has
      if (a.size() > idx) {
        char left = a[a.size() - idx - 1];
        ret[len - 1 - idx] = add(left, '0', carry);
        continue;
      }

      // b has
      if (b.size() > idx) {
        char right = b[b.size() - idx - 1];
        ret[len - 1 - idx] = add('0', right, carry);
        continue;
      }
    }

    if (carry) {
      ret = '1' + ret;
    }
    return ret;
  }
};

//   10
//   11
//  101
int main(int argc, char *argv[]) {
  Solution so;
  // std::cout << so.addBinary("11", "1") << std::endl;
  std::cout << so.addBinary("10", "11") << std::endl;
  std::cout << so.addBinary("1010", "1011") << std::endl;

  return 0;
}