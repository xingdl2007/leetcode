#include <string.h>
#include <algorithm>
#include <climits>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>

using namespace std;

// how to optimise?
class Solution {
 public:
  int index(int i, int j, int column) { return i * column + j; }

  int dfs(std::unordered_map<int, int>& searched, vector<vector<int>>& matrix,
          int row, int column, int ref, int i, int j) {
    if (i < 0 || i >= row || j < 0 || j >= column || matrix[i][j] <= ref) {
      return 0;
    }

    auto it = searched.find(index(i, j, column));
    if (it != searched.end()) {
      return it->second;
    }

    // quite waste if cannot keep the search result
    int up = dfs(searched, matrix, row, column, matrix[i][j], i - 1, j);
    int down = dfs(searched, matrix, row, column, matrix[i][j], i + 1, j);
    int left = dfs(searched, matrix, row, column, matrix[i][j], i, j - 1);
    int right = dfs(searched, matrix, row, column, matrix[i][j], i, j + 1);

    int ret = 1 + std::max(std::max(up, down), std::max(left, right));
    searched[index(i, j, column)] = ret;
    return ret;
  }

  int longestIncreasingPath(vector<vector<int>>& matrix) {
    if (matrix.empty()) return 0;
    int longest = 0;
    int row = matrix.size();
    int column = matrix[0].size();
    std::unordered_map<int, int> searched;

    for (int i = 0; i < row; ++i) {
      for (int j = 0; j < column; ++j) {
        auto it = searched.find(index(i, j, column));
        int length;
        if (it == searched.end()) {
          length = dfs(searched, matrix, row, column, INT_MIN, i, j);
        } else {
          length = searched[index(i, j, column)];
        }
        if (longest < length) {
          longest = length;
        }
      }
    }
    return longest;
  }
};

// this is the right solution
// memory function is very important, DP + DFS, clever !!
class Solution2 {
 public:
  int** m;
  int dfs(int i, int j, vector<vector<int>>& matrix) {
    if (m[i][j] > 0) return m[i][j];
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    m[i][j] = 1;
    for (int k = 0; k < 4; ++k) {
      if (i + dx[k] < 0 || i + dx[k] >= matrix.size()) continue;
      if (j + dy[k] < 0 || j + dy[k] >= matrix[0].size()) continue;
      if (matrix[i + dx[k]][j + dy[k]] > matrix[i][j]) {
        m[i][j] = max(m[i][j], dfs(i + dx[k], j + dy[k], matrix) + 1);
      }
    }
    return m[i][j];
  }

  int longestIncreasingPath(vector<vector<int>>& matrix) {
    // malloc a two-deminsion array to record intermidate search result
    m = new int*[matrix.size()];
    for (int i = 0; i < matrix.size(); ++i) {
      m[i] = new int[matrix[0].size()];
      memset(m[i], 0, sizeof(int) * matrix[0].size());
    }

    int ret = 0;
    for (int i = 0; i < matrix.size(); ++i) {
      for (int j = 0; j < matrix[0].size(); ++j) {
        ret = max(ret, dfs(i, j, matrix));
      }
    }
    return ret;
  }
};

int main(int argc, char* argv[]) {
  Solution so;
  return 0;
}