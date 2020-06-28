#include <algorithm>
#include <bitset>
#include <deque>
#include <functional>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
    // shit, revese copy
    for (int i = 0; i < m; ++i) {
      nums1[m + n - 1 - i] = nums1[m - 1 - i];
    }

    // merge
    int left = 0, right = 0;
    for (int i = 0, j = 0, k = 0; i < m + n; ++i) {
      if (j < m && k < n) {
        left = nums1[n + j];
        right = nums2[k];

        if (left <= right) {
          nums1[i] = left;
          ++j;
        } else {
          nums1[i] = right;
          ++k;
        }
        continue;
      }

      if (j < m) {
        nums1[i] = nums1[n + j];
        ++j;
        continue;
      }

      if (k < n) {
        nums1[i] = nums2[k];
        ++k;
        continue;
      }
    }
  }
};

int main(int argc, char *argv[]) {
  Solution so;
  return 0;
}