#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// very clever !
class Solution {
 public:
  void dfs(vector<vector<char>>& grid, int row, int column, int i, int j) {
    if (i < 0 || i >= row || j < 0 || j >= column || grid[i][j] == '0') {
      return;
    }
    grid[i][j] = '0';
    dfs(grid, row, column, i - 1, j);
    dfs(grid, row, column, i + 1, j);
    dfs(grid, row, column, i, j - 1);
    dfs(grid, row, column, i, j + 1);
  }

  int numIslands(vector<vector<char>>& grid) {
    if (grid.empty()) return 0;
    int row = grid.size();
    int column = grid[0].size();

    int ans = 0;
    for (int i = 0; i < row; ++i) {
      for (int j = 0; j < column; ++j) {
        if (grid[i][j] == '1') {
          dfs(grid, row, column, i, j);
          ++ans;
        }
      }
    }
    return ans;
  }
};

int main(int argc, char* argv[]) {
  Solution so;
  return 0;
}