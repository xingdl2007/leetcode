#include <iostream>
#include <vector>
#include <unordered_map>
#include <functional>
#include <algorithm>
#include <bitset>

using namespace std;

/**
 * Definition for an interval.
 */
struct Interval {
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}
};

Interval combine(const Interval &lhs, const Interval &rhs) {
  int start = lhs.start < rhs.start ? lhs.start : rhs.start;
  int end = lhs.end > rhs.end ? lhs.end : rhs.end;
  return Interval(start, end);
}

class Solution {
public:
  vector<Interval> merge(vector<Interval> &intervals) {
    if (intervals.empty())
      return {};
    vector<Interval> res;
    std::sort(intervals.begin(), intervals.end(),
              [](const Interval &lhs, const Interval &rhs) {
                return lhs.start < rhs.start;
              });
    auto item = intervals[0];
    for (int i = 1; i < intervals.size(); ++i) {
      if (item.end >= intervals[i].start) {
        item = combine(item, intervals[i]);
      } else {
        res.push_back(item);
        item = intervals[i];
      }
    }
    res.push_back(item);
    return res;
  }
};

// for debug
ostream &operator<<(ostream &out, const Interval &i) {
  out << "[" << i.start << "," << i.end << "]";
}

auto print = [](const auto &array) {
  std::for_each(std::begin(array), std::end(array), [](auto s) {
    cout << s << " ";
  });
  cout << '\n';
};

int main(int argc, char *argv[]) {
  Solution so;
  vector<Interval> data = {Interval(1, 3), Interval(2, 6), Interval(8, 10), Interval(15, 18)};
  std::random_shuffle(data.begin(), data.end());
  print(so.merge(data));

  vector<Interval> data2 = {Interval(1, 4), Interval(4, 5)};
  std::random_shuffle(data2.begin(), data2.end());
  print(so.merge(data2));

  vector<Interval> data3 = {Interval(1, 2), Interval(2, 3), Interval(3, 4), Interval(4, 5),
                            Interval(5, 6), Interval(2, 3), Interval(7, 8), Interval(9, 10), Interval(5, 9)};
  std::random_shuffle(data3.begin(), data3.end());
  print(so.merge(data3));
  return 0;
}