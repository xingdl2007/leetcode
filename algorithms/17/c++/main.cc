#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
  vector<string> letterCombinations(string digits) {
    if (digits.empty())
      return {};
    std::vector<string> table = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    std::vector<int> index(digits.size(), -1);

    // generate string based on index
    auto build = [&]() -> string {
      string s(digits.size(), ' ');
      for (int i = 0; i < digits.size(); ++i) {
        s[i] = table[digits[i] - '0'][index[i]];
      }
      return s;
    };
    auto size = [&](int pos) {
      return table[digits[pos] - '0'].size();
    };

    int pos = 0;
    vector<string> letters;
    while (pos >= 0) {
      while (pos >= 0 && pos != digits.size()) {
        ++index[pos];
        if (index[pos] == size(pos)) {
          index[pos] = -1;
          --pos;
          continue;
        }
        ++pos;
      }
      // get new combinator
      if (pos == digits.size()) {
        letters.push_back(build());
        --pos;
      }
    }
    return letters;
  }
};

// easy to figure
class Solution2 {
public:
  vector<string> letterCombinations(string digits) {
    vector<string> result;
    if (digits.empty())
      return vector<string>();
    static const vector<string> v = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    result.push_back("");   // add a seed for the initial case
    for (int i = 0; i < digits.size(); ++i) {
      int num = digits[i] - '0';
      if (num < 0 || num > 9)
        break;
      const string &candidate = v[num];
      if (candidate.empty())
        continue;
      vector<string> tmp;
      for (int j = 0; j < candidate.size(); ++j) {
        for (int k = 0; k < result.size(); ++k) {
          tmp.push_back(result[k] + candidate[j]);
        }
      }
      result.swap(tmp);
    }
    return result;
  }
};

int main(int argc, char *argv[]) {
  Solution so;
  auto data = {string("23"), string("432")};
  for (auto &s:data) {
    auto res = so.letterCombinations(s);
    cout << res.size() << " ";
    for (auto &o:res) {
      cout << o << " ";
    }
    cout << '\n';
  }
}