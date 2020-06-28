#include <algorithm>
#include <bitset>
#include <deque>
#include <functional>
#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  bool canReach(vector<int> &arr, int start) {
    if (arr[start] == 0)
      return true;

    deque<int> pos;
    set<int> searched;
    pos.push_back(start);
    while (!pos.empty()) {
      int p = pos.front();
      pos.pop_front();
      searched.insert(p);

      // left
      if (p - arr[p] >= 0) {
        int idx = p - arr[p];
        if (arr[idx] == 0)
          return true;

        if (searched.count(idx) == 0)
          pos.push_back(idx);
      }

      // right
      if (p + arr[p] < arr.size()) {
        int idx = p + arr[p];
        if (arr[idx] == 0)
          return true;

        if (searched.count(idx) == 0)
          pos.push_back(idx);
      }
    }
    return false;
  }
};

int main(int argc, char *argv[]) {
  Solution so;

  vector<int> data{4, 2, 3, 0, 3, 1, 2};
  vector<int> data2{4, 2, 3, 0, 3, 1, 2};
  vector<int> data3{3, 0, 2, 1, 2};

  vector<int> data4{4, 4, 1, 3, 0, 3};

  std::cout << so.canReach(data, 5) << std::endl;
  std::cout << so.canReach(data2, 0) << std::endl;
  std::cout << so.canReach(data3, 2) << std::endl; // can be a loop
  std::cout << so.canReach(data4, 2) << std::endl; // can be a loop
  return 0;
}