#include <string>
#include <iostream>
#include <limits>

using namespace std;

#define MAX ((unsigned)-1>>1)
#define MIN (1<<31)

class Solution {
public:
  int reverse(int x) {
    int64_t x1 = 0;
    bool sign = x < 0;
    if (sign)
      x = -x;
    while (x) {
      auto e = x%10;
      x1 = x1*10 + e;
      x = x/10;
    }
    if (sign)
      x1 *= -1;
    if (x1 > std::numeric_limits<int>::max() ||
        x1 < std::numeric_limits<int>::min()) {
      return 0;
    }
    return static_cast<int>(x1);
  }
};

int main(int argc, char *argv[]) {
  Solution so;
  auto data = {123, -123, 120,
               std::numeric_limits<int>::min(),
               std::numeric_limits<int>::max()};
  for (auto d:data) {
    cout << d << " " << so.reverse(d) << '\n';
  }
  cout << MAX << " " << MIN << '\n';
  return 0;
}