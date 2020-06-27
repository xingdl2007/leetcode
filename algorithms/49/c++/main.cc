#include <algorithm>
#include <bitset>
#include <functional>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

struct Key {
  Key(const string &s) : data(s) { std::sort(data.begin(), data.end()); }
  string data;
};
bool operator==(const Key &lhs, const Key &rhs) { return lhs.data == rhs.data; }
size_t hasher(const Key &k) { return std::hash<string>{}(k.data); }

class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    using Table = std::unordered_map<Key, vector<string>, decltype(hasher) *>;
    Table table(0, hasher);
    for (auto &s : strs) {
      table[s].push_back(s);
    }
    vector<vector<string>> res;
    std::for_each(table.begin(), table.end(),
                  [&res](auto &vec) { res.push_back(std::move(vec.second)); });
    return res;
  }
};

class Solution2 {
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    std::unordered_map<string, vector<string>> table;
    for (auto &s : strs) {
      auto key = s;
      std::sort(key.begin(), key.end());
      table[key].push_back(s);
    }
    vector<vector<string>> res;
    for (auto &p : table) {
      res.push_back(std::move(p.second));
    }
    return res;
  }
};

auto print = [](const auto &array) {
  std::for_each(std::begin(array), std::end(array),
                [](string s) { cout << s << " "; });
  cout << '\n';
};
auto print2D = [](const auto &matrix) {
  std::for_each(begin(matrix), end(matrix), print);
};

int main(int argc, char *argv[]) {
  Solution so;
  vector<string> data = {"eat", "tea", "tan", "ate", "nat", "bat"};
  print(data);
  print2D(so.groupAnagrams(data));
  return 0;
}