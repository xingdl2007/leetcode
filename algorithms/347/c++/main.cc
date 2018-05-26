#include <iostream>
#include <vector>
#include <climits>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

// sort by frequency, and build a heap
class Solution {
public:
  vector<int> topKFrequent(vector<int> &nums, int k) {
    unordered_map<int, int> frequent;
    for (const auto &n:nums) {
      frequent[n]++;
    }
    auto cmp = [&](int left, int right) { return frequent[left] <= frequent[right]; };
    priority_queue<int, vector<int>, decltype(cmp)> heap(cmp);
    for (auto &p:frequent) {
      heap.push(p.first);
    }
    vector<int> ret;
    while (k--) {
      ret.push_back(heap.top());
      heap.pop();
    }
    return ret;
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
  vector<int> data{1, 1, 1, 2, 2, 3};
  print(so.topKFrequent(data, 1));  // 1
  print(so.topKFrequent(data, 2));  // 1, 2
  print(so.topKFrequent(data, 3));  // 1, 2, 3

  vector<int> data2{4, 1, -1, 2, -1, 2, 3};
  print(so.topKFrequent(data2, 1)); // -1 or 2
  print(so.topKFrequent(data2, 2)); // -1, 2
  print(so.topKFrequent(data2, 3)); // -1, 2, 3
  print(so.topKFrequent(data2, 4)); // -1, 2, 3, 4
  print(so.topKFrequent(data2, 5)); // -1, 2, 3, 4, 1
  return 0;
}