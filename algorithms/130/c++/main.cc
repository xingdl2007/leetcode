#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  void mark(vector<vector<char>>& board, int row, int column, int i, int j) {
    if (i < 0 || i >= row || j < 0 || j >= column || board[i][j] != 'O') {
      return;
    }
    board[i][j] = 'M';
    mark(board, row, column, i, j - 1);
    mark(board, row, column, i, j + 1);
    mark(board, row, column, i + 1, j);
    mark(board, row, column, i - 1, j);
  }

  void solve(vector<vector<char>>& board) {
    if (board.empty()) return;
    int row = board.size();
    int column = board[0].size();

    // first/last line
    for (int j = 0; j < column; ++j) {
      mark(board, row, column, 0, j);
      mark(board, row, column, row - 1, j);
    }

    // first/last column
    for (int i = 0; i < row; ++i) {
      mark(board, row, column, i, 0);
      mark(board, row, column, i, column - 1);
    }

    for (int i = 0; i < row; ++i) {
      for (int j = 0; j < column; ++j) {
        if (board[i][j] == 'O')
          board[i][j] = 'X';
        else if (board[i][j] == 'M')
          board[i][j] = 'O';
      }
    }
  }
};

int main() {
  Solution so;
  return 0;
}