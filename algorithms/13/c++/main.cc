#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
  int romanToInt(string s) {
    std::map<char, int> table = {{'I', 1}, {'V', 5}, {'X', 10},
                                 {'L', 50}, {'C', 100}, {'D', 500},
                                 {'M', 1000}};
    int ret = 0, i = 0;
    while (i < s.length() - 1) {
      if (table[s[i + 1]] <= table[s[i]]) {
        ret += table[s[i]];
        ++i;
      } else {
        ret += table[s[i + 1]] - table[s[i]];
        i += 2;
      }
    }
    if (i != s.length()) {
      ret += table[s[i]];
    }
    return ret;
  }
};

int main(int argc, char *argv[]) {
  Solution so;
  auto data = {"III", "IV", "IX", "LVIII", "MCMXCIV"};
  for (auto d:data) {
    cout << d << " " << so.romanToInt(d) << '\n';
  }
  return 0;
}