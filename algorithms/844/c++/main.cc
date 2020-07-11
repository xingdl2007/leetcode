#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
 public:
  bool backspaceCompare(string S, string T) {
    canonical(S);
    canonical(T);
    return S == T;
  }

  void canonical(string& s) {
    int i = -1, j = 0;
    while (j < s.size()) {
      if (s[j] == '#') {
        if (i != -1) --i;
      } else {
        ++i;
        if (i != j) s[i] = s[j];
      }
      j++;
    }
    s.resize(i + 1);
  }
};

int main(int argc, char* argv[]) {
  Solution so;
  std::cout << so.backspaceCompare("ab#c", "ad#c") << std::endl;
  std::cout << so.backspaceCompare("ab##", "c#d#") << std::endl;
  std::cout << so.backspaceCompare("a##c", "#a#c") << std::endl;
  std::cout << so.backspaceCompare("a#c", "b") << std::endl;
  return 0;
}