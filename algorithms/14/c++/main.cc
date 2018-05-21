#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  string longestCommonPrefix(vector<string> &strs) {
    if (strs.empty())
      return "";
    if (strs.size() == 1)
      return strs[0];

    int i = 0;
    while (i != strs[0].length()) {
      auto c = strs[0][i];
      for (auto &s:strs) {
        if (s[i] != c) {
          return strs[0].substr(0, i);
        }
      }
      ++i;
    }
    return strs[0];
  }
};

int main(int argc, char *argv[]) {
  Solution so;
  vector<string> data = {"flower", "flow", "flight"};
  cout << so.longestCommonPrefix(data) << '\n';

  vector<string> data2 = {"dog", "racecar", "car"};
  cout << so.longestCommonPrefix(data2) << '\n';

  vector<string> data3 = {"dog"};
  cout << so.longestCommonPrefix(data3) << '\n';

  vector<string> data4 = {};
  cout << so.longestCommonPrefix(data4) << '\n';
  return 0;
}