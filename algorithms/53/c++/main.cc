#include <iostream>
#include <climits>
#include <vector>

using namespace std;

class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    int sum = -1, max = INT_MIN;
    for (auto n: nums) {
      if (sum > 0)
        sum += n;
      else
        sum = n;
      if (sum > max) {
        max = sum;
      }
    }
    return max;
  }
};

int main(int argc, char *argv[]) {
  Solution so;
  return 0;
}