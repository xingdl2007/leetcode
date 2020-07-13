#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> generate(int numRows) {
    if (numRows == 0) return {};

    vector<vector<int>> ret{{1}};
    for (int i = 1; i < numRows; ++i) {
      ret.push_back(row(&ret[i - 1], i));
    }
    return ret;
  }

  vector<int> row(vector<int>* last, int row) {
    vector<int> ret;
    ret.push_back(1);
    for (int i = 1; i < last->size(); ++i) {
      ret.push_back((*last)[i - 1] + (*last)[i]);
    }
    ret.push_back(1);
    return ret;
  }
};

int main(int argc, char* argv[]) {
  Solution so;
  return 0;
}