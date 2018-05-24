#include <iostream>
#include <vector>
#include <stack>
#include <utility>
#include <algorithm>
#include <tuple>
#include <map>

using namespace std;

// stack based backtracking: trick to get it right
class Solution {
public:
  bool exist(vector<vector<char>> &board, string word) {
    using Coord = std::tuple<int, int>;

    // upper
    auto upper = [](const Coord &cur) {
      return Coord{std::get<0>(cur) - 1, std::get<1>(cur)};
    };
    // bottom
    auto bottom = [](const Coord &cur) {
      return Coord{std::get<0>(cur) + 1, std::get<1>(cur)};
    };
    // left
    auto left = [](const Coord &cur) {
      return Coord{std::get<0>(cur), std::get<1>(cur) - 1};
    };
    // right
    auto right = [](const Coord &cur) {
      return Coord{std::get<0>(cur), std::get<1>(cur) + 1};
    };
    auto getChar = [&](const Coord &cur) -> char {
      int x = std::get<0>(cur);
      int y = std::get<1>(cur);
      if (0 <= x && x < board.size() && 0 <= y && y < board[x].size())
        return board[x][y];
      return -1;
    };

    std::stack<Coord> track;
    std::map<Coord, bool> used;
    if (word.empty())
      true;

    int pos = 0;
    // find the Coord of first char
    for (int i = 0; i < board.size(); ++i) {
      for (int j = 0; j < board[i].size(); ++j)
        if (board[i][j] == word[pos]) {
          track.push({i, j});
        }
    }
    while (!track.empty()) {
      if (used[track.top()]) {
        used[track.top()] = false;
        track.pop();
        --pos;
        continue;
      }
      auto cur = track.top();
      used[cur] = true;
      while (getChar(cur) != word[pos])
        pos--;
      if (++pos == word.size())
        break;

      // check next char
      bool found = false;
      auto neighbor = {upper(cur), left(cur), bottom(cur), right(cur)};
      for (auto &n:neighbor) {
        if (!used[n] && getChar(n) == word[pos]) {
          track.push(n);
          found = true;
        }
      }
      // if not found, backtrack to last position
      if (!found) {
        --pos;
        used[cur] = false;
        track.pop();
      }
    }
    return pos == word.size();
  }
};

// DFS search
class Solution2 {
public:
  bool exist(vector<vector<char>> &board, string word) {
    for (int i = 0; i < board.size(); i++)
      for (int j = 0; j < board[0].size(); j++)
        if (dfs(board, i, j, word, 0))
          return true;
    return false;
  }
  bool dfs(vector<vector<char>> &board, int i, int j, const string &word, int k) {
    if (i < 0 || i >= (board.size()) || j < 0 || j >= (board[0].size()) || k >= word.size())
      return false;
    else if (board[i][j] == word[k]) {
      if (k == (word.size() - 1)) {
        return true;
      }
      char temp = board[i][j];
      board[i][j] = '#';
      if (dfs(board, i + 1, j, word, k + 1) ||
          dfs(board, i - 1, j, word, k + 1) ||
          dfs(board, i, j - 1, word, k + 1) ||
          dfs(board, i, j + 1, word, k + 1))
        return true;
      board[i][j] = temp;
    }
    return false;
  }
};

auto print = [](const auto &array) {
  std::for_each(std::begin(array), std::end(array), [](auto s) {
    cout << s << " ";
  });
  cout << '\n';
};

int main(int argc, char *argv[]) {
  Solution so;
  vector<vector<char>> board = {
      {'A', 'B', 'C', 'E'},
      {'S', 'F', 'C', 'S'},
      {'A', 'D', 'E', 'E'}
  };
  cout << so.exist(board, "ABCCED") << '\n';
  cout << so.exist(board, "SEE") << '\n';
  cout << so.exist(board, "ABCB") << '\n';

  // bug fix (backtracking)
  vector<vector<char>> board2 = {
      {'a', 'a'},
  };
  cout << so.exist(board2, "aaa") << '\n';
  cout << so.exist(board2, "aa") << '\n';

  // bug fix (backtracking)
  vector<vector<char>> board3 = {
      {'A', 'B', 'C', 'E'},
      {'S', 'F', 'E', 'S'},
      {'A', 'D', 'E', 'E'}
  };
  cout << so.exist(board3, "ABCEFSADEESE") << '\n';
  return 0;
}