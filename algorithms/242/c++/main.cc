#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
 public:
  bool isAnagram(string s, string t) {
    std::sort(s.begin(), s.end());
    std::sort(t.begin(), t.end());
    return s == t;
  }
};

class Solution2 {
 public:
  bool isAnagram(string s, string t) {
    if (s.size() != t.size()) return false;
    int array[26] = {0};
    for (auto c : s) {
      ++array[c - 'a'];
    }
    for (auto c : t) {
      --array[c - 'a'];
      if (array[c - 'a'] < 0) return false;
    }
    return true;
  }
};

int main(int argc, char* argv[]) {
  Solution so;
  int array[26] = {0};

  for (int i = 0; i < 26; ++i) std::cout << array[i] << " ";
  std::cout << std::endl;
  return 0;
}