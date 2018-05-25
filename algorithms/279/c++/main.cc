#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

// start from left bottom corner
class Solution {
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    if (matrix.empty())
      return false;
    int m = matrix.size(), n = matrix[0].size();
    int x = m - 1, y = 0;
    while (0 <= x && y < n) {
      if (matrix[x][y] == target)
        return true;
      else if (matrix[x][y] < target)
        ++y;
      else
        --x;
    }
    return false;
  }
};

auto print = [](const auto &array) {
  for_each(begin(array), end(array), [](const auto &item) {
    cout << item << " ";
  });
  cout << '\n';
};

auto print2D = [&](const auto &matrix) {
  std::for_each(begin(matrix), end(matrix), print);
};

int main(int argc, char *argv[]) {
  Solution so;
  vector<vector<int>> data = {
      {1, 4, 7, 11, 15},
      {2, 5, 8, 12, 19},
      {3, 6, 9, 16, 22},
      {10, 13, 14, 17, 24},
      {18, 21, 23, 26, 30}
  };

  cout << so.searchMatrix(data, 5) << '\n';
  cout << so.searchMatrix(data, 20) << '\n';
  return 0;
}