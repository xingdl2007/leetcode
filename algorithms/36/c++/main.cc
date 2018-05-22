#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

// assumption: 9x9
class Solution {
public:
  bool isValidSudoku(vector<vector<char>> &board) {
    std::bitset<9> row[9], column[9], block[9];
    for (int r = 0; r < 9; ++r) {
      for (int l = 0; l < 9; ++l) {
        auto c = board[r][l];
        if (c != '.') {
          size_t n = c - '0' - 1;
          int b = (r/3)*3 + l/3;
          // check row, column, block
          if (row[r].test(n) || column[l].test(n) || block[b].test(n))
            return false;
          row[r].set(n);
          column[l].set(n);
          block[b].set(n);
        }
      }
    }
    return true;
  }
};

int main(int argc, char *argv[]) {
  Solution so;
  vector<vector<char>> data = {
      {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
      {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
      {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
      {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
      {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
      {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
      {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
      {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
      {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
  };
  cout << so.isValidSudoku(data) << '\n';

  vector<vector<char>> data2 = {
      {'8', '3', '.', '.', '7', '.', '.', '.', '.'},
      {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
      {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
      {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
      {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
      {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
      {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
      {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
      {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
  };
  cout << so.isValidSudoku(data2) << '\n';
  return 0;
}