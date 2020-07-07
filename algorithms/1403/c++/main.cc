#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums)
    {
        std::vector<int> ret;
        std::sort(nums.begin(), nums.end(), std::greater<int>());
        for (int i = 0, j = nums.size() - 1; i <= j; ++i) {
            ret.push_back(nums[i]);
            if (i > 0) {
                nums[i] += nums[i - 1];
            }
            while (nums[i] > nums[j] && i != j) {
                nums[i] -= nums[j];
                j--;
            }
        }
        return ret;
    }
};

int main(int argc, char* argv[])
{
    Solution so;
    return 0;
}