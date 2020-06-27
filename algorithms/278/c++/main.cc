#include <algorithm>
#include <climits>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

// The API isBadVersion is defined for you.
bool isBadVersion(int version);

class Solution {
public:
  int firstBadVersion(int n) {
    int low = 1, high = n, mid;
    while (low < high) {
      mid = low + (high - low) / 2; // careful: use minus to avoid overflow
      if (isBadVersion(mid)) {
        high = mid;
      } else {
        low = mid + 1;
      }
    }
    return low;
  }
};

int main(int argc, char *argv[]) {
  Solution so;
  return 0;
}