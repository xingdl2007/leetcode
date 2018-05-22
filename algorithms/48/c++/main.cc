#include <iostream>
#include <vector>
#include <tuple>
#include <functional>
#include <algorithm>

using namespace std;

// in-place
class Solution {
public:
  // layer by layer
  void rotate(vector<vector<int>> &matrix, int layer, int size) {
    if (size == 1)
      return;

    // coordination counterclockwise
    auto coordination = [x = layer, y = layer, N = matrix.size(), layer = layer]() mutable
        -> std::tuple<int, int> {
      int size = N - layer*2;
      std::tuple<int, int> res = {x, y};
      if (y == layer && (layer <= x && x < layer + size - 1)) {
        ++x;
      } else if ((y >= layer && y < layer + size - 1) && x == layer + size - 1) {
        ++y;
      } else if (y == layer + size - 1 && (x <= layer + size - 1) && x > layer) {
        --x;
      } else if (y > layer && y <= layer + size - 1 && x == layer) {
        --y;
      }
      return res;
    };

    for (int i = 0; i < size - 1; ++i) {
      auto start = coordination();
      auto pre = start, next = start;
      int tmp = matrix[get<0>(pre)][get<1>(pre)];
      while ((next = coordination()) != start) {
        matrix[get<0>(pre)][get<1>(pre)] = matrix[get<0>(next)][get<1>(next)];
        pre = next;
      }
      matrix[get<0>(pre)][get<1>(pre)] = tmp;
    }
  }

  void rotate(vector<vector<int>> &matrix) {
    int N = matrix.size();
    for (int i = 0; i < N; ++i) {
      rotate(matrix, i, N - i*2);
    }
  }
};

// ref: also layer by layer
class Solution2 {
public:
  void rotate(vector<vector<int>> &matrix) {
    int m = matrix.size() - 1, c = 0;
    int tmp = 0;
    while (c < matrix.size()/2) {
      for (int j = c; j < m - c; j++) {
        tmp = matrix[c][j];
        matrix[c][j] = matrix[m - j][c];
        matrix[m - j][c] = matrix[m - c][m - j];
        matrix[m - c][m - j] = matrix[j][m - c];
        matrix[j][m - c] = tmp;
      }
      c++;
    }
  }
};

int main(int argc, char *argv[]) {
  Solution so;
  auto print = [](const vector<int> &array) {
    std::for_each(std::begin(array), std::end(array), [](int n) {
      cout << n << " ";
    });
    cout << '\n';
  };
  auto print2D = [&](const vector<vector<int>> &matrix) {
    std::for_each(begin(matrix), end(matrix), print);
  };

  // 1
  vector<vector<int>> data = {
      {1, 2, 3},
      {4, 5, 6},
      {7, 8, 9}
  };
  so.rotate(data);
  print2D(data);
  cout << '\n';
  // 2
  vector<vector<int>> data2 = {
      {5, 1, 9, 11},
      {2, 4, 8, 10},
      {13, 3, 6, 7},
      {15, 14, 12, 16}
  };
  so.rotate(data2);
  print2D(data2);
  return 0;
}