#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
 public:
  int firstUniqChar(string s) {
    if (s.empty()) return -1;

    int array[26] = {0};
    for (auto c : s) {
      ++array[c - 'a'];
    }
    for (int i = 0; i < s.size(); ++i) {
      if (array[s[i] - 'a'] == 1) return i;
    }
    return -1;
  }
};

int main(int argc, char* argv[]) {
  Solution so;
  return 0;
}