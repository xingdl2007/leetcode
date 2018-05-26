#include <iostream>
#include <vector>
#include <climits>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

// elegant, the key part is `int &i`
// index should be remembered between iteration
class Solution {
public:
  string decodeString(const string &s, int &i) {
    string res;
    while (i < s.length() && s[i] != ']') {
      if (!isdigit(s[i]))
        res += s[i++];
      else {
        int n = 0;
        while (i < s.length() && isdigit(s[i]))
          n = n*10 + s[i++] - '0';

        i++; // skip '['
        string t = decodeString(s, i);
        i++; // skip ']'

        while (n-- > 0)
          res += t;
      }
    }
    return res;
  }

  string decodeString(string s) {
    // index should be remembered
    int i = 0;
    return decodeString(s, i);
  }
};

int main(int argc, char *argv[]) {
  Solution so;
  cout << so.decodeString("3[a]2[bc]") << '\n';
  cout << so.decodeString("3[a2[c]]") << '\n';
  cout << so.decodeString("2[abc]3[cd]ef") << '\n';
  return 0;
}