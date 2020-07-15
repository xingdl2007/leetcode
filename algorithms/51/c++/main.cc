#include <algorithm>
#include <bitset>
#include <cmath>
#include <functional>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
class Solution {
 public:
  vector<vector<string>> solveNQueens(int n) {}
};

auto print = [](const auto &array) {
  std::for_each(std::begin(array), std::end(array),
                [](auto s) { cout << s << " "; });
  cout << '\n';
};

int main(int argc, char *argv[]) {
  Solution so;
  return 0;
}