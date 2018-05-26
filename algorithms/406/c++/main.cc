#include <iostream>
#include <vector>
#include <climits>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

auto print = [](const auto &array) {
  std::for_each(std::begin(array), std::end(array), [](const auto &s) {
    cout << "{" << s.first << "," << s.second << "}" << " ";
  });
  cout << '\n';
};

// interesting
// "Brilliant idea, below is my understanding,
// k is only determined by people with equal or larger height,
// so makes sense to insert in non-increasing order of height.
// Because when we insert some person with height h and count k,
// we know that we have found its correct position relative to
// people with equal and larger height.
// And when we later insert other people with equal or smaller height,
// we know that it will not affect this relative position. So the answer
// is right after we insert all people."
class Solution {
public:
  vector<pair<int, int>> reconstructQueue(vector<pair<int, int>> &people) {
    sort(people.begin(), people.end(), [](pair<int, int> p1, pair<int, int> p2) {
      return p1.first > p2.first || (p1.first == p2.first && p1.second < p2.second);
    });
    //print(people);
    vector<pair<int, int>> sol;
    for (auto person : people) {
      sol.insert(sol.begin() + person.second, person);
    }
    return sol;
  }
};

int main(int argc, char *argv[]) {
  Solution so;
  vector<pair<int, int>> people = {{7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2}};
  print(so.reconstructQueue(people));
  return 0;
}
