#include <iostream>

using namespace std;

class Solution {
public:
  int lengthOfLastWord(string s) {
    int pos = s.length() - 1;
    while (pos >= 0 && s[pos] == ' ') {
      pos--;
    }
    int b = pos;
    while (b >= 0 && s[b] != ' ') {
      b--;
    }
    return pos - b;
  }
};

int main(int argc, char *argv[]) {
  Solution so;
  std::cout << so.lengthOfLastWord("hello world  ") << std::endl;
  std::cout << so.lengthOfLastWord("") << std::endl;
  std::cout << so.lengthOfLastWord("12 ") << std::endl;
  return 0;
}