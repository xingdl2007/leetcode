#include <iostream>

using namespace std;

class Solution {
public:
  int myAtoi(string str) {
    int ret = 0;
    int i = 0;
    bool sign = false;
    bool overflow = false;
    while (i < str.length() && str[i] == ' ')
      ++i;
    if (i == str.length())
      return 0;

    // sign detection
    if (str[i] == '+' || str[i] == '-') {
      if (str[i] == '-')
        sign = true;
      ++i;
    }
    while (i < str.length() && std::isdigit(str[i])) {
      int64_t tmp = ret;
      tmp = 10*tmp + str[i] - '0';
      // overflow detection
      if (tmp > INT32_MAX) {
        overflow = true;
        break;
      }
      ret = static_cast<int>(tmp);
      ++i;
    }
    if (overflow) {
      return sign ? INT32_MIN : INT32_MAX;
    }
    return sign ? -ret : ret;
  }
};

int main(int argc, char *argv[]) {
  Solution so;
  auto data = {"42", "   -42", "4193 with words", "words and 987",
               "-91283472332", "123456789012124124", "-123456789012124124",
               "-6147483648"};
  for (auto d: data) {
    cout << d << " " << so.myAtoi(d) << '\n';
  }
  return 0;
}