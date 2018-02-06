#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
  string convert(string s, int numRows) {
    int mod = 2*numRows - 2;
    string *rows[numRows];
    string ret;

    if (numRows == 1)
      return s;

    for (int i = 0; i < numRows; ++i) {
      rows[i] = new string();
    }

    for (int i = 0; i < s.size(); ++i) {
      int reminder = i%mod;
      if (reminder >= numRows) {
        rows[mod - reminder]->append(s, i, 1);
      } else {
        rows[reminder]->append(s, i, 1);
      }
    }

    for (int i = 0; i < numRows; ++i) {
      //cout << *rows[i] << endl;
      ret += *rows[i];
    }
    return ret;
  }
};

/* ZigZag examples

    2 line example:
    0   2   4
    1   3   5

    3 line example:
    0       4       8
    1   3   5   7   9
    2       6       10

    4 line example:
    0           6           12
    1       5   7       11  13
    2   4       8   10      14
    3           9           15
*/

int main(int argc, char *argv[]) {
  cout << (new Solution())->convert("PAYPALISHIRING", 3) << endl;
  cout << (new Solution())->convert("ABC", 2) << endl;
  return 0;
}