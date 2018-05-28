#include <iostream>
#include <vector>
#include <climits>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <numeric>

using namespace std;

// priority queue based
class Solution {
public:
  int leastInterval(vector<char> &tasks, int n) {
    int idle = 0;
    int completed = 0;
    if (!tasks.empty()) {
      unordered_map<char, int> counts;
      for (auto c: tasks) {
        counts[c]++;
      }
      auto cmp = [&](char lhs, char rhs) {
        return counts[lhs] < counts[rhs];
      };
      priority_queue<char, vector<char>, decltype(cmp)> sorted(cmp);
      for (auto c: counts) {
        sorted.push(c.first);
      }
      while (!sorted.empty()) {
        // first interval
        vector<char> tmp;
        for (int i = 0; i <= n && completed != tasks.size(); ++i) {
          if (sorted.empty()) {
            idle++;
          } else {
            auto task = sorted.top();
            sorted.pop();
            counts[task]--;
            completed++;
            tmp.push_back(task);
          }
        }
        for (auto t: tmp) {
          if (counts[t] != 0)
            sorted.push(t);
        }
      }
    }
    return completed + idle;
  }
};

// ref: kind of simplicity
class Solution2 {
public:
  int leastInterval(vector<char> &tasks, int n) {
    vector<int> map(26);
    for (char c : tasks)
      map[c - 'A']++;
    sort(map.begin(), map.end());
    int time = 0;
    while (map[25] != 0) {
      int i = 0;
      while (i <= n) {
        if (map[25] == 0)
          break;
        if (i < 26 && map[25 - i] > 0)
          map[25 - i]--;
        time++;
        i++;
      }
      sort(map.begin(), map.end());
    }
    return time;
  }
};

auto print = [](const auto &array) {
  std::for_each(std::begin(array), std::end(array), [](const auto &s) {
    cout << s << " ";
  });
  cout << '\n';
};

int main(int argc, char *argv[]) {
  Solution so;

  vector<char> tasks1 = {'A', 'A', 'A', 'B', 'B', 'B'};
  cout << so.leastInterval(tasks1, 2) << '\n';

  vector<char> tasks2 = {'A', 'A', 'A', 'B', 'B', 'B', 'C', 'C'};
  cout << so.leastInterval(tasks2, 3) << '\n';

  vector<char> tasks3 = {'A'};
  cout << so.leastInterval(tasks3, 3) << '\n';

  vector<char> tasks4 = {};
  cout << so.leastInterval(tasks4, 3) << '\n';

  vector<char> tasks5 = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'A'};
  cout << so.leastInterval(tasks5, 3) << '\n';
  return 0;
}
