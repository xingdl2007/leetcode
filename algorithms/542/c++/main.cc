#include <string.h>
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

#include <limits.h>

using namespace std;

// wrong !!!
// dfs is not right, should use bfs
// should use BFS and DP
class Solution {
 public:
  int dfs(vector<vector<int>>& m, int row, int column, int i, int j) {
    if (i < 0 || i >= row || j < 0 || j >= column || m[i][j] == -2)
      return INT_MAX;

    if (m[i][j] >= 0) return m[i][j];
    m[i][j] = -2;  // flag not to search again

    int d = INT_MAX;
    d = std::min(d, dfs(m, row, column, i - 1, j));
    d = std::min(d, dfs(m, row, column, i + 1, j));
    d = std::min(d, dfs(m, row, column, i, j - 1));
    d = std::min(d, dfs(m, row, column, i, j + 1));
    m[i][j] = d + 1;
    return m[i][j];
  }

  vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
    if (matrix.empty()) return {};
    int row = matrix.size();
    int column = matrix[0].size();

    for (int i = 0; i < row; ++i) {
      for (int j = 0; j < column; ++j) {
        if (matrix[i][j] == 1) {
          matrix[i][j] = -1;
        }
      }
    }

    for (int i = 0; i < row; ++i) {
      for (int j = 0; j < column; ++j) {
        if (matrix[i][j] == -1) {
          matrix[i][j] = dfs(matrix, row, column, i, j);
        }
      }
    }
    return matrix;
  }
};

// [[1,0,1,1,0,0,1,0,0,1],
//  [0,1,1,0,1,0,1,0,1,1],
//  [0,0,1,0,1,0,0,1,0,0],
//  [1,0,1,0,1,1,1,1,1,1],
//  [0,1,0,1,1,0,0,0,0,1],
//  [0,0,1,0,1,1,1,0,1,0],
//  [0,1,0,1,0,1,0,0,1,1],
//  [1,0,0,0,1,1,1,1,0,1],
//  [1,1,1,1,1,1,1,0,1,0],
//  [1,1,1,1,0,1,0,0,1,1]]

// [[1,0,1,1,0,0,1,0,0,1],
//  [0,1,1,0,1,0,1,0,1,1],
//  [0,0,1,0,1,0,0,1,0,0],
//  [1,0,1,0,1,1,1,1,1,1],
//  [0,1,0,1,1,0,0,0,0,1],
//  [0,0,1,0,1,1,1,0,1,0],
//  [0,1,0,1,0,1,0,0,1,1],
//  [1,0,0,0,1,2,1,1,0,1],
//  [2,1,1,1,1,2,1,0,1,0],
//  [3,4,2,1,0,1,0,0,1,1]]

// [[1,0,1,1,0,0,1,0,0,1],
//  [0,1,1,0,1,0,1,0,1,1],
//  [0,0,1,0,1,0,0,1,0,0],
//  [1,0,1,0,1,1,1,1,1,1],
//  [0,1,0,1,1,0,0,0,0,1],
//  [0,0,1,0,1,1,1,0,1,0],
//  [0,1,0,1,0,1,0,0,1,1],
//  [1,0,0,0,1,2,1,1,0,1],
//  [2,1,1,1,1,2,1,0,1,0],
//  [3,2,2,1,0,1,0,0,1,1]]

int main(int argc, char* argv[]) {
  Solution so;

  vector<vector<int>> data{{0, 0, 0}, {1, 1, 1}, {1, 1, 1}};
  auto ret = so.updateMatrix(data);
  for (auto& v : ret) {
    for (auto i : v) {
      std::cout << i << " ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
  return 0;
}