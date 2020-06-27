#include <iostream>

using namespace std;
class Solution {
public:
  string countAndSay(int n) {
    string last("1"), result = last;
    while (--n) {
      result.clear();
      for (int i = 0; i < last.size();) {
        char item = last[i];
        int cnt = 0;
        while (i < last.size() && last[i] == item) {
          ++i;
          ++cnt;
        }
        result += std::to_string(cnt) + item;
      }
      last = result;
    }
    return result;
  }
};

int main(int argc, char *argv[]) {
  Solution so;
  std::cout << so.countAndSay(1) << std::endl;
  std::cout << so.countAndSay(2) << std::endl;
  std::cout << so.countAndSay(3) << std::endl;
  std::cout << so.countAndSay(4) << std::endl;
  std::cout << so.countAndSay(5) << std::endl;
  std::cout << so.countAndSay(6) << std::endl;
  std::cout << so.countAndSay(7) << std::endl;
  std::cout << so.countAndSay(8) << std::endl;
  std::cout << so.countAndSay(9) << std::endl;
  std::cout << so.countAndSay(10) << std::endl;
  return 0;
}
