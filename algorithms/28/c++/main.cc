#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
  int strStr(string haystack, string needle) {
    return static_cast<int>(haystack.find(needle));
  }
};

// ref
class Solution2 {
public:
  int strStr(string haystack, string needle) {
    int i = 0, j = 0, n = haystack.size(), m = needle.size();
    while (i < n && j < m) {
      if (haystack[i] == needle[j])
        i++, j++;
      else
        i -= j - 1, j = 0; // Text String come back to the next index, and pattern string reset
    }
    return (j != m) ? -1 : i - j; // if j == m, find
  }
};

int main(int argc, char *argv[]) {
  Solution so;
  cout << "hello " << so.strStr("hello", "ll") << '\n';
  cout << "hello " << so.strStr("hello", "") << '\n';
  cout << "aaaaa " << so.strStr("aaaaa", "bba") << '\n';
  return 0;
}